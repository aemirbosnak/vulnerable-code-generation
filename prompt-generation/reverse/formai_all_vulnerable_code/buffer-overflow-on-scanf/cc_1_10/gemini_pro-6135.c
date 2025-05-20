//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

// Sudoku grid
int grid[N][N];

// Function to print the grid
void printGrid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
bool isSafe(int row, int col, int num) {
  // Check row
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return false;
    }
  }

  // Check column
  for (int i = 0; i < N; i++) {
    if (grid[i][col] == num) {
      return false;
    }
  }

  // Check box
  int boxRow = row / 3;
  int boxCol = col / 3;
  for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
    for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku() {
  // Find an empty cell
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        goto found;
      }
    }
  }

found:
  // If there are no empty cells, the puzzle is solved
  if (row == N && col == N) {
    return true;
  }

  // Try all possible numbers for the empty cell
  for (int num = 1; num <= N; num++) {
    // If the number is safe to place in the cell, place it and recur
    if (isSafe(row, col, num)) {
      grid[row][col] = num;
      if (solveSudoku()) {
        return true;
      }
      // If the number is not safe, reset the cell and try the next number
      else {
        grid[row][col] = 0;
      }
    }
  }

  // If none of the numbers are safe, the puzzle is unsolvable
  return false;
}

int main() {
  // Get the input Sudoku puzzle
  printf("Enter the Sudoku puzzle:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }

  // Print the original puzzle
  printf("Original puzzle:\n");
  printGrid();

  // Solve the puzzle
  if (solveSudoku()) {
    // Print the solved puzzle
    printf("Solved puzzle:\n");
    printGrid();
  } else {
    printf("Puzzle could not be solved.\n");
  }

  return 0;
}