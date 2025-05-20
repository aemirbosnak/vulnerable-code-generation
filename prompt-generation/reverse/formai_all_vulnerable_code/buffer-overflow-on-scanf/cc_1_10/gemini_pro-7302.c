//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the Sudoku grid
#define SIZE 9

// Create a 2D array to represent the Sudoku grid
int grid[SIZE][SIZE];

// Define a function to check if a number is safe to place in a given cell
bool isSafe(int row, int col, int num) {
  // Check if the number is already present in the row
  for (int i = 0; i < SIZE; i++) {
    if (grid[row][i] == num) {
      return false;
    }
  }

  // Check if the number is already present in the column
  for (int i = 0; i < SIZE; i++) {
    if (grid[i][col] == num) {
      return false;
    }
  }

  // Check if the number is already present in the 3x3 box
  int boxRow = row / 3;
  int boxCol = col / 3;
  for (int i = 3 * boxRow; i < 3 * boxRow + 3; i++) {
    for (int j = 3 * boxCol; j < 3 * boxCol + 3; j++) {
      if (grid[i][j] == num) {
        return false;
      }
    }
  }

  // If the number is not present in any of the above cases, it is safe to place
  return true;
}

// Define a function to solve the Sudoku puzzle
bool solveSudoku() {
  // Iterate over all the cells in the grid
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      // If the cell is empty, try to place a number in it
      if (grid[row][col] == 0) {
        for (int num = 1; num <= SIZE; num++) {
          // If the number is safe to place, place it in the cell and recursively solve the rest of the grid
          if (isSafe(row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku()) {
              return true;
            } else {
              // If the recursive call fails, reset the cell to empty and try the next number
              grid[row][col] = 0;
            }
          }
        }

        // If no number can be placed in the cell, the puzzle is unsolvable
        return false;
      }
    }
  }

  // If all the cells have been filled, the puzzle is solved
  return true;
}

// Define a function to print the Sudoku grid
void printSudoku() {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      printf("%d ", grid[row][col]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Read the Sudoku puzzle from the user
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      scanf("%d", &grid[row][col]);
    }
  }

  // Solve the Sudoku puzzle
  if (solveSudoku()) {
    // Print the solved Sudoku grid
    printSudoku();
  } else {
    // Print an error message if the puzzle is unsolvable
    printf("The puzzle is unsolvable.\n");
  }

  return 0;
}