//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define N 9

int main() {
  int sudoku[N][N];
  int i, j, k, l, m, n;

  // Read the sudoku puzzle from the standard input.
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &sudoku[i][j]);
    }
  }

  // Solve the sudoku puzzle using a recursive backtracking algorithm.
  if (solve_sudoku(sudoku)) {
    // Print the solved sudoku puzzle to the standard output.
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        printf("%d ", sudoku[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("The sudoku puzzle is unsolvable.\n");
  }

  return 0;
}

int solve_sudoku(int sudoku[N][N]) {
  int i, j, k, l, m, n;

  // Find an empty cell in the sudoku puzzle.
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (sudoku[i][j] == 0) {
        goto found_empty_cell;
      }
    }
  }

  // If there are no empty cells, the sudoku puzzle is solved.
  return 1;

found_empty_cell:

  // Try all possible values for the empty cell.
  for (k = 1; k <= N; k++) {
    // Check if the value is valid for the empty cell.
    if (is_valid(sudoku, i, j, k)) {
      // Assign the value to the empty cell.
      sudoku[i][j] = k;

      // Recursively solve the sudoku puzzle.
      if (solve_sudoku(sudoku)) {
        // The sudoku puzzle is solved.
        return 1;
      }

      // The sudoku puzzle is not solved.
      // Unassign the value from the empty cell.
      sudoku[i][j] = 0;
    }
  }

  // No valid value for the empty cell.
  return 0;
}

int is_valid(int sudoku[N][N], int i, int j, int k) {
  int l, m, n;

  // Check if the value is already present in the row.
  for (l = 0; l < N; l++) {
    if (sudoku[i][l] == k) {
      return 0;
    }
  }

  // Check if the value is already present in the column.
  for (m = 0; m < N; m++) {
    if (sudoku[m][j] == k) {
      return 0;
    }
  }

  // Check if the value is already present in the 3x3 subgrid.
  n = (i / 3) * 3 + (j / 3);
  for (l = 0; l < 3; l++) {
    for (m = 0; m < 3; m++) {
      if (sudoku[n + l][n + m] == k) {
        return 0;
      }
    }
  }

  // The value is valid.
  return 1;
}