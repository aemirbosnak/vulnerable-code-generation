//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

int grid[SUDOKU_SIZE][SUDOKU_SIZE];

void print_grid() {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int is_valid_move(int row, int col, int num) {
  // Check row
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (grid[i][col] == num) {
      return 0;
    }
  }

  // Check 3x3 box
  int box_row_start = row - row % 3;
  int box_col_start = col - col % 3;
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
  // Base case: we have reached the end of the grid
  if (row == SUDOKU_SIZE) {
    return 1;
  }

  // If the current cell is already filled, move on to the next cell
  if (grid[row][col] != 0) {
    return solve_sudoku(row + (col + 1) / SUDOKU_SIZE, (col + 1) % SUDOKU_SIZE);
  }

  // Try all possible numbers for the current cell
  for (int num = 1; num <= SUDOKU_SIZE; num++) {
    if (is_valid_move(row, col, num)) {
      grid[row][col] = num;

      // Recursively solve the rest of the grid
      if (solve_sudoku(row + (col + 1) / SUDOKU_SIZE, (col + 1) % SUDOKU_SIZE)) {
        return 1;
      }

      // If the recursive call failed, reset the current cell to 0 and try the next number
      grid[row][col] = 0;
    }
  }

  // If we have tried all possible numbers without success, return 0 to indicate that the grid is unsolvable
  return 0;
}

int main() {
  // Initialize the grid with the given values
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }

  // Solve the sudoku
  if (solve_sudoku(0, 0)) {
    printf("Solved sudoku:\n");
    print_grid();
  } else {
    printf("sudoku is unsolvable\n");
  }

  return 0;
}