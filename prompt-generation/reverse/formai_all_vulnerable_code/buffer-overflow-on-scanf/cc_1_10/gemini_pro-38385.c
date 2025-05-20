//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

int grid[N][N];
bool solved = false;

void print_grid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

bool is_valid_move(int row, int col, int num) {
  // Check row and column for duplicates
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num || grid[i][col] == num) {
      return false;
    }
  }

  // Check 3x3 box for duplicates
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

void solve_sudoku(int row, int col) {
  // Base case: we have filled the entire grid
  if (row == N - 1 && col == N) {
    solved = true;
    return;
  }

  // Recursive case: try all possible numbers for the current cell
  for (int num = 1; num <= N && !solved; num++) {
    if (is_valid_move(row, col, num)) {
      grid[row][col] = num;

      // Move to the next cell
      if (col == N - 1) {
        solve_sudoku(row + 1, 0);
      } else {
        solve_sudoku(row, col + 1);
      }

      // Backtrack if the recursive call didn't solve the sudoku
      if (!solved) {
        grid[row][col] = 0;
      }
    }
  }
}

int main() {
  // Read the input sudoku puzzle from stdin
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }

  // Solve the sudoku puzzle
  solve_sudoku(0, 0);

  // Print the solved sudoku puzzle
  if (solved) {
    print_grid();
  } else {
    printf("No solution exists.\n");
  }

  return 0;
}