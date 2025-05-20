//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int board[SIZE][SIZE];

int main()
{
  // Read the puzzle from the user.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // Solve the puzzle.
  if (!solve_sudoku(board)) {
    printf("No solution found.\n");
    return 1;
  }

  // Print the solution.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int solve_sudoku(int board[][SIZE])
{
  int row, col;

  // Find an empty cell.
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      if (board[row][col] == 0) {
        goto found;
      }
    }
  }

  // No empty cell found, the puzzle is solved.
  return 1;

found:

  // Try all possible values for the empty cell.
  for (int value = 1; value <= SIZE; value++) {
    // Check if the value is valid.
    if (is_valid(board, row, col, value)) {
      // Set the value and recurse.
      board[row][col] = value;
      if (solve_sudoku(board)) {
        return 1;
      }
      // The value is not valid, reset the cell.
      board[row][col] = 0;
    }
  }

  // No valid value found, backtrack.
  return 0;
}

int is_valid(int board[][SIZE], int row, int col, int value)
{
  // Check the row.
  for (int i = 0; i < SIZE; i++) {
    if (board[row][i] == value) {
      return 0;
    }
  }

  // Check the column.
  for (int i = 0; i < SIZE; i++) {
    if (board[i][col] == value) {
      return 0;
    }
  }

  // Check the 3x3 box.
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
    for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
      if (board[i][j] == value) {
        return 0;
      }
    }
  }

  // The value is valid.
  return 1;
}