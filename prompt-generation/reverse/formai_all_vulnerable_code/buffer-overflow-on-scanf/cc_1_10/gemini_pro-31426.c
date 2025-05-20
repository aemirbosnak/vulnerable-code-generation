//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_SIZE 9

typedef struct {
  int grid[SUDOKU_SIZE][SUDOKU_SIZE];
  int solved;
} Sudoku;

int is_valid_move(Sudoku *sudoku, int row, int col, int value) {
  // Check row
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (sudoku->grid[row][i] == value) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (sudoku->grid[i][col] == value) {
      return 0;
    }
  }

  // Check 3x3 box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (sudoku->grid[i][j] == value) {
        return 0;
      }
    }
  }

  return 1;
}

void solve_sudoku(Sudoku *sudoku) {
  // Find an empty cell
  int row, col;
  for (row = 0; row < SUDOKU_SIZE; row++) {
    for (col = 0; col < SUDOKU_SIZE; col++) {
      if (sudoku->grid[row][col] == 0) {
        goto found_empty_cell;
      }
    }
  }

  // No empty cells, sudoku is solved
  sudoku->solved = 1;
  return;

found_empty_cell:
  // Try all possible values for the empty cell
  for (int value = 1; value <= SUDOKU_SIZE; value++) {
    if (is_valid_move(sudoku, row, col, value)) {
      sudoku->grid[row][col] = value;

      // Solve the rest of the sudoku recursively
      solve_sudoku(sudoku);

      // If the sudoku is solved, we're done
      if (sudoku->solved) {
        return;
      }

      // If the sudoku is not solved, reset the empty cell
      sudoku->grid[row][col] = 0;
    }
  }
}

void print_sudoku(Sudoku *sudoku) {
  for (int row = 0; row < SUDOKU_SIZE; row++) {
    for (int col = 0; col < SUDOKU_SIZE; col++) {
      printf("%d ", sudoku->grid[row][col]);
    }
    printf("\n");
  }
}

int main() {
  Sudoku sudoku;

  // Get the sudoku puzzle from the user
  printf("Enter the sudoku puzzle (0 for empty cells):\n");
  for (int row = 0; row < SUDOKU_SIZE; row++) {
    for (int col = 0; col < SUDOKU_SIZE; col++) {
      scanf("%d", &sudoku.grid[row][col]);
    }
  }

  // Solve the sudoku
  solve_sudoku(&sudoku);

  // Print the solved sudoku
  if (sudoku.solved) {
    printf("Solved sudoku:\n");
    print_sudoku(&sudoku);
  } else {
    printf("Sudoku could not be solved.\n");
  }

  return 0;
}