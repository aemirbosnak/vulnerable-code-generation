//FormAI DATASET v1.0 Category: Sudoku solver ; Style: secure
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int grid[SIZE][SIZE];

// Check if a number is valid in the given row
bool isValidRow(int row, int num) {
  for (int col = 0; col < SIZE; col++) {
    if (grid[row][col] == num) {
      return false;
    }
  }
  return true;
}

// Check if a number is valid in the given column
bool isValidCol(int col, int num) {
  for (int row = 0; row < SIZE; row++) {
    if (grid[row][col] == num) {
      return false;
    }
  }
  return true;
}

// Check if a number is valid in the given 3x3 box
bool isValidBox(int startRow, int startCol, int num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (grid[row + startRow][col + startCol] == num) {
        return false;
      }
    }
  }
  return true;
}

// Check if a number is valid at the given position
bool isValid(int row, int col, int num) {
  return isValidRow(row, num) && isValidCol(col, num) && isValidBox(row - row % 3, col - col % 3, num);
}

// Find an empty position in the grid
bool findEmpty(int *row, int *col) {
  for (*row = 0; *row < SIZE; (*row)++) {
    for (*col = 0; *col < SIZE; (*col)++) {
      if (grid[*row][*col] == 0) {
        return true;
      }
    }
  }
  return false;
}

// Solve the Sudoku puzzle recursively using backtracking
bool solve() {
  int row, col;
  if (!findEmpty(&row, &col)) {
    return true; // The grid is full, Sudoku solved
  }
  for (int num = 1; num <= 9; num++) { // Try each number from 1 to 9
    if (isValid(row, col, num)) {
      grid[row][col] = num; // Assign the number
      if (solve()) {
        return true; // Sudoku solved
      }
      grid[row][col] = 0; // Backtrack and try the next number
    }
  }
  return false; // Sudoku cannot be solved
}

int main() {
  // Read in the puzzle from STDIN
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      scanf("%d", &grid[row][col]);
    }
  }
  // Solve the puzzle
  if (solve()) {
    // Print out the solution to STDOUT
    for (int row = 0; row < SIZE; row++) {
      for (int col = 0; col < SIZE; col++) {
        printf("%d ", grid[row][col]);
      }
      printf("\n");
    }
  } else {
    printf("No solution.\n");
  }
  return 0;
}