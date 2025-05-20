//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

int grid[N][N];
int solved = 0;

void print_grid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int is_safe(int row, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num || grid[i][col] == num) {
      return 0;
    }
  }

  int box_row = row / 3;
  int box_col = col / 3;

  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  return 1;
}

void solve_sudoku(int row, int col) {
  if (row == N - 1 && col == N) {
    solved = 1;
    return;
  }

  if (col == N) {
    row++;
    col = 0;
  }

  if (grid[row][col] != 0) {
    solve_sudoku(row, col + 1);
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (is_safe(row, col, i)) {
      grid[row][col] = i;
      solve_sudoku(row, col + 1);
      if (solved) {
        return;
      }
      grid[row][col] = 0;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  solve_sudoku(0, 0);

  if (solved) {
    print_grid();
  } else {
    printf("No solution exists.\n");
  }

  return 0;
}