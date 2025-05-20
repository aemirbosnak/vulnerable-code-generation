//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[3][3]); // function to print the board
int checkWin(int board[3][3]); // function to check if there is a win
int checkDraw(int board[3][3]); // function to check if there is a draw

int main() {
  int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }; // initialize the board with zeros
  int currentPlayer = 1; // initialize the current player to player 1
  int row, col; // variables to hold the row and column chosen by the player

  srand(time(NULL)); // seed the random number generator

  printf("Welcome to the C Table Game!\n");

  while (!checkWin(board) && !checkDraw(board)) { // loop while there is no win and no draw
    printBoard(board); // print the board
    printf("Player %d's turn.\n", currentPlayer); // prompt the current player to choose a row and column
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    // check if the chosen row and column are valid
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0) {
      printf("Invalid move. Please choose again.\n");
      printf("Enter row: ");
      scanf("%d", &row);
      printf("Enter column: ");
      scanf("%d", &col);
    }

    board[row-1][col-1] = currentPlayer; // update the board with the player's move

    // switch to the other player
    if (currentPlayer == 1) {
      currentPlayer = 2;
    } else {
      currentPlayer = 1;
    }
  }

  printBoard(board); // print the final board

  // display the final result
  if (checkWin(board)) {
    printf("Player %d wins!\n", currentPlayer);
  } else {
    printf("Draw!\n");
  }

  return 0;
}

void printBoard(int board[3][3]) {
  printf("  1 2 3\n");
  for (int i=0; i<3; i++) {
    printf("%d ", i+1);
    for (int j=0; j<3; j++) {
      if (board[i][j] == 0) {
        printf("_ ");
      } else if (board[i][j] == 1) {
        printf("X ");
      } else {
        printf("O ");
      }
    }
    printf("\n");
  }
}

int checkWin(int board[3][3]) {
  // check rows
  for (int i=0; i<3; i++) {
    if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return 1;
    }
  }

  // check columns
  for (int i=0; i<3; i++) {
    if (board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return 1;
    }
  }

  // check diagonals
  if (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return 1;
  }
  if (board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return 1;
  }

  return 0;
}

int checkDraw(int board[3][3]) {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (board[i][j] == 0) {
        return 0; // there is an empty cell, so it's not a draw
      }
    }
  }

  return 1; // all cells are filled, so it's a draw
}