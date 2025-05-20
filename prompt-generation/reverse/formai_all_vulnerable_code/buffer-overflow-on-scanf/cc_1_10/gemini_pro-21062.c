//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_SIZE 9

// Sudoku board
int board[SUDOKU_SIZE][SUDOKU_SIZE];

// Function to print the Sudoku board
void print_board() {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
int is_safe(int row, int col, int num) {
  // Check the row
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (board[row][i] == num) {
      return 0;
    }
  }

  // Check the column
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (board[i][col] == num) {
      return 0;
    }
  }

  // Check the box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }

  // The number is safe to place
  return 1;
}

// Function to solve the Sudoku puzzle
int solve_sudoku() {
  // Loop through the board
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      // If the cell is empty, try to place a number in it
      if (board[i][j] == 0) {
        // Loop through the numbers from 1 to 9
        for (int num = 1; num <= SUDOKU_SIZE; num++) {
          // If the number is safe to place, place it in the cell
          if (is_safe(i, j, num)) {
            board[i][j] = num;

            // Recursively solve the rest of the puzzle
            if (solve_sudoku()) {
              return 1;
            }

            // If the puzzle is not solved, reset the cell to empty
            board[i][j] = 0;
          }
        }

        // If no number is safe to place, the puzzle is not solvable
        return 0;
      }
    }
  }

  // The puzzle is solved
  return 1;
}

// Main function
int main() {
  // Initialize the board
  memset(board, 0, sizeof(board));

  // Read the puzzle from the user
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // Print the original puzzle
  printf("Original puzzle:\n");
  print_board();

  // Solve the puzzle
  if (solve_sudoku()) {
    // Print the solved puzzle
    printf("Solved puzzle:\n");
    print_board();
  } else {
    // The puzzle is not solvable
    printf("The puzzle is not solvable.\n");
  }

  return 0;
}