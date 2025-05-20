//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

int grid[SUDOKU_SIZE][SUDOKU_SIZE];
int solved;

void print_grid() {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int is_safe(int row, int col, int num) {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
  }

  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (grid[i][col] == num) {
      return 0;
    }
  }

  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
    for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  return 1;
}

int solve_sudoku(int row, int col) {
  if (row == SUDOKU_SIZE - 1 && col == SUDOKU_SIZE) {
    solved = 1;
    return 1;
  }

  if (col == SUDOKU_SIZE) {
    row++;
    col = 0;
  }

  if (grid[row][col] != 0) {
    return solve_sudoku(row, col + 1);
  }

  for (int num = 1; num <= SUDOKU_SIZE; num++) {
    if (is_safe(row, col, num)) {
      grid[row][col] = num;
      if (solve_sudoku(row, col + 1)) {
        return 1;
      }
    }
  }

  grid[row][col] = 0;
  return 0;
}

int main() {
  printf("Enter the Sudoku grid (0 for empty cells):\n");
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  printf("Solving...");
  solve_sudoku(0, 0);

  if (solved) {
    printf("Solved!\n");
    print_grid();
  } else {
    printf("No solution exists.\n");
  }

  return 0;
}