//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];

int is_safe(int row, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
    if (grid[i][col] == num) {
      return 0;
    }
  }

  int box_row_start = (row / 3) * 3;
  int box_col_start = (col / 3) * 3;

  for (int i = box_row_start; i < box_row_start + 3; i++) {
    for (int j = box_col_start; j < box_col_start + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  return 1;
}

int solve_sudoku(int row, int col) {
  if (row == N - 1 && col == N) {
    return 1;
  }

  if (col == N) {
    row++;
    col = 0;
  }

  if (grid[row][col] != 0) {
    return solve_sudoku(row, col + 1);
  }

  for (int num = 1; num <= N; num++) {
    if (is_safe(row, col, num)) {
      grid[row][col] = num;

      if (solve_sudoku(row, col + 1)) {
        return 1;
      }

      grid[row][col] = 0;
    }
  }

  return 0;
}

int main() {
  int i, j;

  printf("Enter the Sudoku puzzle:\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  if (solve_sudoku(0, 0)) {
    printf("The solution to the Sudoku puzzle is:\n");
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution exists for the given Sudoku puzzle.\n");
  }

  return 0;
}