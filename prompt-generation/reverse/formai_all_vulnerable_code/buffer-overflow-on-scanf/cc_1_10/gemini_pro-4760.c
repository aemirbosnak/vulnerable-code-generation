//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9

// The 9x9 sudoku board
int board[SIZE][SIZE];

// Function to check if the given number is valid in the given row
int is_valid_row(int row, int num) {
  for (int i = 0; i < SIZE; i++) {
    if (board[row][i] == num) {
      return 0;
    }
  }
  return 1;
}

// Function to check if the given number is valid in the given column
int is_valid_col(int col, int num) {
  for (int i = 0; i < SIZE; i++) {
    if (board[i][col] == num) {
      return 0;
    }
  }
  return 1;
}

// Function to check if the given number is valid in the given 3x3 box
int is_valid_box(int row, int col, int num) {
  int box_row = row - row % 3;
  int box_col = col - col % 3;

  for (int i = box_row; i < box_row + 3; i++) {
    for (int j = box_col; j < box_col + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to check if the given number is valid in the given cell
int is_valid(int row, int col, int num) {
  return is_valid_row(row, num) && is_valid_col(col, num) && is_valid_box(row, col, num);
}

// Function to solve the sudoku puzzle
int solve() {
  // Iterate over the cells
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      // If the cell is empty, try to fill it
      if (board[row][col] == 0) {
        // Iterate over the possible numbers
        for (int num = 1; num <= SIZE; num++) {
          // If the number is valid, fill the cell and recurse
          if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (solve()) {
              return 1;
            } else {
              board[row][col] = 0;
            }
          }
        }
        // If no valid number was found, return failure
        return 0;
      }
    }
  }
  // If all cells are filled, return success
  return 1;
}

// Function to print the sudoku puzzle
void print_board() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Get the input sudoku puzzle
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // Solve the sudoku puzzle
  if (solve()) {
    // Print the solved sudoku puzzle
    print_board();
  } else {
    printf("No solution found.\n");
  }

  return 0;
}