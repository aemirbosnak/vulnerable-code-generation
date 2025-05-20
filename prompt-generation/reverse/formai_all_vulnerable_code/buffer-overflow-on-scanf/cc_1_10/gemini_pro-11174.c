//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The Sudoku board
int board[9][9];

// The possible values for each cell
int possibilities[9][9][9];

// The number of possible values for each cell
int num_possibilities[9][9];

// The stack of cells to be checked
int stack[81][2];
int stack_size = 0;

// The function to initialize the Sudoku board
void init_board() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = 0;
      for (int k = 0; k < 9; k++) {
        possibilities[i][j][k] = 1;
      }
      num_possibilities[i][j] = 9;
    }
  }
}

// The function to print the Sudoku board
void print_board() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// The function to check if a cell is valid
bool is_valid(int row, int col, int value) {
  // Check the row
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == value) {
      return false;
    }
  }

  // Check the column
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == value) {
      return false;
    }
  }

  // Check the 3x3 box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (board[i][j] == value) {
        return false;
      }
    }
  }

  return true;
}

// The function to solve the Sudoku puzzle
bool solve() {
  // If the stack is empty, the puzzle is solved
  if (stack_size == 0) {
    return true;
  }

  // Pop the next cell from the stack
  int row = stack[stack_size - 1][0];
  int col = stack[stack_size - 1][1];
  stack_size--;

  // Try all possible values for the cell
  for (int value = 1; value <= 9; value++) {
    // If the value is valid, set the cell to that value and push the cell onto the stack
    if (is_valid(row, col, value)) {
      board[row][col] = value;
      stack[stack_size][0] = row;
      stack[stack_size][1] = col;
      stack_size++;

      // Recursively solve the puzzle
      if (solve()) {
        return true;
      }

      // If the puzzle is not solved, pop the cell from the stack and reset the cell to 0
      stack_size--;
      board[row][col] = 0;
    }
  }

  // If no valid values were found, the puzzle is not solvable
  return false;
}

int main() {
  init_board();

  // Read the Sudoku puzzle from the user
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d ", &board[i][j]);
    }
  }

  // Solve the Sudoku puzzle
  if (solve()) {
    // Print the solved puzzle
    print_board();
  } else {
    printf("The puzzle is not solvable.\n");
  }

  return 0;
}