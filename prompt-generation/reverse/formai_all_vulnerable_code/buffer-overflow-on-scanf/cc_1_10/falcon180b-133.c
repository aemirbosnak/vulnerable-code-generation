//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define BOARD_SIZE (SIZE*SIZE)

int board[BOARD_SIZE];

void printBoard() {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (i == 0 && j == 0) {
        printf("+--+--+--+\n");
      } else if (i == 0) {
        printf("| %d | %d | %d |\n", board[(j-1)*SIZE+1], board[(j-1)*SIZE+2], board[(j-1)*SIZE+3]);
      } else if (j == 0) {
        printf("+--+--+--+\n");
      } else if (i == SIZE-1) {
        printf("| %d | %d | %d |\n", board[(j-1)*SIZE+6], board[(j-1)*SIZE+7], board[(j-1)*SIZE+8]);
      } else if (j == SIZE-1) {
        printf("+--+--+--+\n");
      } else {
        printf("| %d | %d | %d |\n", board[(j-1)*SIZE+3], board[(j-1)*SIZE+4], board[(j-1)*SIZE+5]);
      }
    }
  }
}

int isValid(int row, int col, int num) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (i == row && j == col) {
        continue;
      }
      if (board[i*SIZE+j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int solveBoard(int row, int col) {
  if (row == SIZE-1 && col == SIZE-1) {
    return 1;
  }
  if (row == SIZE-1) {
    col++;
    row = 0;
  } else if (col == SIZE-1) {
    row++;
    col = 0;
  } else {
    col++;
  }
  if (board[row*SIZE+col] == 0) {
    for (int i = 1; i <= SIZE; i++) {
      if (isValid(row, col, i)) {
        board[row*SIZE+col] = i;
        if (solveBoard(row, col)) {
          return 1;
        }
        board[row*SIZE+col] = 0;
      }
    }
    return 0;
  } else {
    return solveBoard(row, col);
  }
}

int main() {
  int i, j;
  printf("Enter the Sudoku board:\n");
  for (i = 0; i < BOARD_SIZE; i++) {
    scanf("%d", &board[i]);
  }
  solveBoard(0, 0);
  printf("Solution:\n");
  printBoard();
  return 0;
}