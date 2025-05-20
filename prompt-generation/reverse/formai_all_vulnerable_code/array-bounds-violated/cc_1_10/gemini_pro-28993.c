//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_SIZE 9
#define SUDOKU_CELL_EMPTY 0

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];

int check_row(int row, int num) {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (sudoku[row][i] == num) {
      return 0;
    }
  }
  return 1;
}

int check_column(int col, int num) {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (sudoku[i][col] == num) {
      return 0;
    }
  }
  return 1;
}

int check_box(int row, int col, int num) {
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (sudoku[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int is_valid(int row, int col, int num) {
  return check_row(row, num) && check_column(col, num) && check_box(row, col, num);
}

int solve_sudoku() {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      if (sudoku[i][j] == SUDOKU_CELL_EMPTY) {
        for (int num = 1; num <= SUDOKU_SIZE; num++) {
          if (is_valid(i, j, num)) {
            sudoku[i][j] = num;
            if (solve_sudoku()) {
              return 1;
            } else {
              sudoku[i][j] = SUDOKU_CELL_EMPTY;
            }
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  memset(sudoku, SUDOKU_CELL_EMPTY, sizeof(sudoku));

  int n;
  printf("Enter the number of cells to fill: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int row, col, num;
    printf("Enter row, column, and number: ");
    scanf("%d %d %d", &row, &col, &num);
    sudoku[row - 1][col - 1] = num;
  }

  if (solve_sudoku()) {
    printf("Solved Sudoku:\n");
    for (int i = 0; i < SUDOKU_SIZE; i++) {
      for (int j = 0; j < SUDOKU_SIZE; j++) {
        printf("%d ", sudoku[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }

  return 0;
}