//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// Function to print the sudoku grid
void printGrid(int grid[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
int isSafe(int grid[N][N], int row, int col, int num) {
  // Check the row
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return 0;
    }
  }

  // Check the column
  for (int j = 0; j < N; j++) {
    if (grid[j][col] == num) {
      return 0;
    }
  }

  // Check the subgrid
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = startRow; i < startRow + 3; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  // If all checks pass, the number is safe to place
  return 1;
}

// Function to solve the sudoku grid using backtracking
int solveSudoku(int grid[N][N]) {
  // Find an empty cell
  int row = -1;
  int col = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        row = i;
        col = j;
        break;
      }
    }
    if (row != -1) {
      break;
    }
  }

  // If no empty cells are found, the sudoku is solved
  if (row == -1) {
    return 1;
  }

  // Try all possible numbers for the empty cell
  for (int num = 1; num <= N; num++) {
    // If the number is safe to place, try it
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;

      // Recursively solve the sudoku with the new number
      if (solveSudoku(grid)) {
        return 1;
      } else {
        // If the recursive call fails, reset the cell to 0 and try the next number
        grid[row][col] = 0;
      }
    }
  }

  // If no number can be placed in the empty cell, the sudoku is not solvable
  return 0;
}

int main() {
  // Get the input sudoku grid
  int grid[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Solve the sudoku grid
  if (solveSudoku(grid)) {
    // Print the solved sudoku grid
    printGrid(grid);
  } else {
    printf("The sudoku is not solvable\n");
  }

  return 0;
}