//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>

int grid[9][9];

int is_valid(int row, int col, int val) {
  for (int i = 0; i < 9; i++) {
    if (grid[row][i] == val) return 0;
    if (grid[i][col] == val) return 0;
  }
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
    for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
      if (grid[i][j] == val) return 0;
    }
  }
  return 1;
}

int solve(int row, int col) {
  if (row == 9) return 1;
  if (col == 9) return solve(row + 1, 0);
  if (grid[row][col] != 0) return solve(row, col + 1);
  for (int val = 1; val <= 9; val++) {
    if (is_valid(row, col, val)) {
      grid[row][col] = val;
      if (solve(row, col + 1)) return 1;
      grid[row][col] = 0;
    }
  }
  return 0;
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  if (solve(0, 0)) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }
  return 0;
}