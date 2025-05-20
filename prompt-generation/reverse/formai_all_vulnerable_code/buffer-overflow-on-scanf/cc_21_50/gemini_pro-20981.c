//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define BLACK 1
#define WHITE 2
#define EMPTY 0

int board[BOARD_SIZE][BOARD_SIZE];

int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0) {
        board[i][j] = EMPTY;
      } else if (i < 3) {
        board[i][j] = BLACK;
      } else if (i > 4) {
        board[i][j] = WHITE;
      } else {
        board[i][j] = EMPTY;
      }
    }
  }

  // Print the board
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == BLACK) {
        printf("● ");
      } else if (board[i][j] == WHITE) {
        printf("○ ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // Get the player's move
  int from_row, from_col, to_row, to_col;
  printf("Enter the coordinates of the piece you want to move (row, column): ");
  scanf("%d %d", &from_row, &from_col);
  printf("Enter the coordinates of the square you want to move to (row, column): ");
  scanf("%d %d", &to_row, &to_col);

  // Check if the move is valid
  if (board[from_row][from_col] == EMPTY) {
    printf("Invalid move: There is no piece at that location.\n");
  } else if (board[from_row][from_col] == WHITE && to_row > from_row) {
    printf("Invalid move: White pieces can only move forward.\n");
  } else if (board[from_row][from_col] == BLACK && to_row < from_row) {
    printf("Invalid move: Black pieces can only move backward.\n");
  } else if (board[to_row][to_col] != EMPTY) {
    printf("Invalid move: The destination square is not empty.\n");
  } else {
    // Make the move
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;

    // Print the board
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
      printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
      printf("%d ", i);
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == BLACK) {
          printf("● ");
        } else if (board[i][j] == WHITE) {
          printf("○ ");
        } else {
          printf("  ");
        }
      }
      printf("\n");
    }
  }

  return 0;
}