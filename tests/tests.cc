// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Michael R. Nowak                Environment : ubuntu:latest               //
//  Date ......: 2022/02/07                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "board.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
constexpr int kBoardWidth = 7;
constexpr int kBoardHeight = 6;

bool AreEqual(DiskType solution[][kBoardWidth],
              DiskType student[][kBoardWidth]) {
  for (int i = 0; i < kBoardHeight; ++i) {
    for (int j = 0; j < kBoardWidth; ++j) {
      if (solution[i][j] != student[i][j]) return false;
    }
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Board initialization", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
}

TEST_CASE("Check Horizontal", "[check_hori") {
  DiskType solution[kBoardHeight][kBoardWidth] = {{DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer2,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer2,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer2,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer1,
                                                   DiskType::kPlayer1,
                                                   DiskType::kPlayer1,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty}};
  Board student;  // NOLINT
  InitBoard(student);
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      student.board[i][j] = solution[i][j];
    }
  }
  REQUIRE(SearchForWinner(student,
                          DiskType::kPlayer1,
                          WinningDirection::kHorizontal) == true);
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kHorizontal));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kVertical));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kVertical));
}
TEST_CASE("Check Vertical", "[check_verti]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = {{DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer2,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer1,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer1,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer1,
                                                   DiskType::kPlayer2,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty}};
  //clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      student.board[i][j] = solution[i][j];
    }
  }
  REQUIRE(SearchForWinner(student,
                          DiskType::kPlayer1,
                          WinningDirection::kVertical) == true);
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kHorizontal));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kVertical));
}
 TEST_CASE("Check Range", "[check_rang]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = {{DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer2,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer1,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer1,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty},
                                                  {DiskType::kPlayer1,
                                                   DiskType::kPlayer2,
                                                   DiskType::kPlayer1,
                                                   DiskType::kPlayer2,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty,
                                                   DiskType::kEmpty}};
  //clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      student.board[i][j] = solution[i][j];
    }
  }
  REQUIRE(BoardLocationInBounds(Board::kBoardHeight, Board::kBoardWidth));
  REQUIRE(SearchForWinner(student,
                          DiskType::kPlayer1,
                          WinningDirection::kVertical) );
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kHorizontal));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kVertical));
}



/////////////////////////////////////////////////////////////////////////////////////////////