//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];

int is_safe(int row, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num || grid[i][col] == num) {
      return 0;
    }
  }
  int start_row = (row / 3) * 3;
  int start_col = (col / 3) * 3;
  for (int i = start_row; i < start_row + 3; i++) {
    for (int j = start_col; j < start_col + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int solve_sudoku() {
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        for (int num = 1; num <= N; num++) {
          if (is_safe(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku()) {
              return 1;
            }
            grid[row][col] = 0;
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int i, j;
  printf("Enter the Sudoku puzzle:\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  if (solve_sudoku()) {
    printf("Solved Sudoku:\n");
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("Sudoku cannot be solved.\n");
  }
  return 0;
}