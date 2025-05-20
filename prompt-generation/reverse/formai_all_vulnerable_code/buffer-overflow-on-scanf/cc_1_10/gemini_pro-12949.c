//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 3
#define NUM_COLS 3

char board[NUM_ROWS][NUM_COLS];

void initBoard() {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      board[i][j] = '.';
    }
  }
}

void printBoard() {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

int checkWin() {
  // Check rows
  for (int i = 0; i < NUM_ROWS; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < NUM_COLS; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.') {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {
    return 1;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {
    return 1;
  }

  return 0;
}

int main() {
  initBoard();

  int player = 1; // 1 for player 1, 2 for player 2

  while (1) {
    printBoard();

    int row, col;
    printf("Player %d's turn (enter row and column): ", player);
    scanf("%d %d", &row, &col);

    if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
      printf("Invalid move. Please enter a valid row and column.\n");
      continue;
    }

    if (board[row - 1][col - 1] != '.') {
      printf("That square is already occupied. Please enter a valid row and column.\n");
      continue;
    }

    if (player == 1) {
      board[row - 1][col - 1] = 'X';
    } else {
      board[row - 1][col - 1] = 'O';
    }

    if (checkWin()) {
      printBoard();
      printf("Player %d wins!\n", player);
      break;
    }

    player = 3 - player; // Switch players
  }

  return 0;
}