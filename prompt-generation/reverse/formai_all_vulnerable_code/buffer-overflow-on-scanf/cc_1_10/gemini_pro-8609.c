//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Sudoku board
int board[9][9];

// Function to print the Sudoku board
void printBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
int isSafe(int row, int col, int num) {
  // Check row
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == num) {
      return 0;
    }
  }

  // Check box
  int boxRow = row / 3;
  int boxCol = col / 3;
  for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
    for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }

  // If all checks pass, then the number is safe to place
  return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku() {
  // Find an empty cell
  int row, col;
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (board[row][col] == 0) {
        goto found;
      }
    }
  }
  return 1; // Puzzle solved

found:
  // Try all possible numbers for the empty cell
  for (int num = 1; num <= 9; num++) {
    // If the number is safe to place
    if (isSafe(row, col, num)) {
      // Place the number in the cell
      board[row][col] = num;

      // Recursively solve the rest of the puzzle
      if (solveSudoku()) {
        return 1; // Puzzle solved
      }

      // If the recursion fails, reset the cell to empty
      board[row][col] = 0;
    }
  }

  // If no valid number can be placed in the cell, then the puzzle is unsolvable
  return 0;
}

// Main function
int main() {
  // Read the Sudoku puzzle from the user
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // Solve the Sudoku puzzle
  if (solveSudoku()) {
    // Print the solved puzzle
    printBoard();
  } else {
    // Print that the puzzle is unsolvable
    printf("Unsolvable");
  }

  return 0;
}