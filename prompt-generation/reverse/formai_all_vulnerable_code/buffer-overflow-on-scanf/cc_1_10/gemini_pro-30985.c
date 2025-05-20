//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

// The sudoku board
int board[SUDOKU_SIZE][SUDOKU_SIZE];

// Function to print the sudoku board
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

  // If all checks pass, the number is safe to place
  return 1;
}

// Function to solve the sudoku board
int solve_sudoku() {
  // Start from the top-left corner
  int row = 0;
  int col = 0;

  // Keep going until we reach the end of the board
  while (row < SUDOKU_SIZE) {
    while (col < SUDOKU_SIZE) {
      // If the cell is empty, try to fill it with a number
      if (board[row][col] == 0) {
        // Try all possible numbers
        for (int num = 1; num <= SUDOKU_SIZE; num++) {
          // If the number is safe to place, place it
          if (is_safe(row, col, num)) {
            board[row][col] = num;

            // Recursively call the solve_sudoku function to solve the rest of the board
            if (solve_sudoku()) {
              return 1;  // Sudoku solved!
            } else {
              // If the recursive call failed, reset the cell to empty
              board[row][col] = 0;
            }
          }
        }

        // If we tried all possible numbers and none of them worked, backtrack
        return 0;
      }

      // Move to the next column
      col++;
    }

    // If we reached the end of a row, move to the next row and reset the column to 0
    if (col == SUDOKU_SIZE) {
      row++;
      col = 0;
    }
  }

  // If we reached the end of the board without backtracking, the sudoku is solved!
  return 1;
}

int main() {
  // Get the input sudoku board
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // Solve the sudoku board
  if (solve_sudoku()) {
    // Print the solved sudoku board
    print_board();
  } else {
    // The sudoku board could not be solved
    printf("No solution found\n");
  }

  return 0;
}