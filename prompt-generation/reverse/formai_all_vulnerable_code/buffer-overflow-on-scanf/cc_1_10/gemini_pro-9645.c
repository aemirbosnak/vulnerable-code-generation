//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// Sudoku grid
int grid[N][N];

// Function to print the Sudoku grid
void print_grid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
int is_safe(int row, int col, int num) {
  // Check row and column
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num || grid[i][col] == num) {
      return 0;
    }
  }

  // Check 3x3 box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  // If all checks pass, return true
  return 1;
}

// Function to solve the Sudoku grid using backtracking
int solve_sudoku() {
  // Find an empty cell
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        goto found;
      }
    }
  }
  return 1; // Grid is solved

found:
  // Try all possible numbers for the empty cell
  for (int num = 1; num <= N; num++) {
    // If the number is safe to place
    if (is_safe(row, col, num)) {
      // Place the number in the cell
      grid[row][col] = num;

      // Recursively solve the rest of the grid
      if (solve_sudoku()) {
        return 1;
      }

      // If the recursive call fails, reset the cell to 0
      grid[row][col] = 0;
    }
  }

  // If no number is safe to place, the grid is unsolvable
  return 0;
}

// Main function
int main() {
  // Initialize the Sudoku grid
  memset(grid, 0, sizeof(grid));

  // Read the Sudoku grid from the user
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Print the original Sudoku grid
  printf("Original Sudoku grid:\n");
  print_grid();

  // Solve the Sudoku grid
  if (solve_sudoku()) {
    // Print the solved Sudoku grid
    printf("Solved Sudoku grid:\n");
    print_grid();
  } else {
    printf("The Sudoku grid is unsolvable.\n");
  }

  return 0;
}