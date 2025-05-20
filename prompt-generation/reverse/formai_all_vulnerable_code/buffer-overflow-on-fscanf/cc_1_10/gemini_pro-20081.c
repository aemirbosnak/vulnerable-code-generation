//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Size of the Sudoku board.
#define N 9

// The Sudoku board.
int board[N][N];

// Function to check if a number is in a row.
bool in_row(int row, int num) {
  for (int i = 0; i < N; i++) {
    if (board[row][i] == num) {
      return true;
    }
  }
  return false;
}

// Function to check if a number is in a column.
bool in_col(int col, int num) {
  for (int i = 0; i < N; i++) {
    if (board[i][col] == num) {
      return true;
    }
  }
  return false;
}

// Function to check if a number is in a box.
bool in_box(int box_row, int box_col, int num) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[box_row * 3 + i][box_col * 3 + j] == num) {
        return true;
      }
    }
  }
  return false;
}

// Function to check if a number is safe to place in a cell.
bool is_safe(int row, int col, int num) {
  return !in_row(row, num) && !in_col(col, num) && !in_box(row / 3, col / 3, num);
}

// Function to find an empty cell.
bool find_empty_cell(int *row, int *col) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0) {
        *row = i;
        *col = j;
        return true;
      }
    }
  }
  return false;
}

// Function to solve the Sudoku puzzle.
bool solve_sudoku() {
  int row, col;

  // If there is no empty cell, then the puzzle is solved.
  if (!find_empty_cell(&row, &col)) {
    return true;
  }

  // Try all possible numbers for the empty cell.
  for (int num = 1; num <= N; num++) {
    // If the number is safe to place in the cell, then place it there.
    if (is_safe(row, col, num)) {
      board[row][col] = num;

      // Recursively solve the rest of the puzzle.
      if (solve_sudoku()) {
        return true;
      }

      // If the rest of the puzzle cannot be solved, then remove the number from the cell.
      board[row][col] = 0;
    }
  }

  // If none of the numbers are safe to place in the cell, then the puzzle cannot be solved.
  return false;
}

// Function to print the Sudoku board.
void print_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Read the Sudoku puzzle from the input file.
  FILE *fp = fopen("sudoku.txt", "r");
  if (fp == NULL) {
    printf("Error opening the input file.\n");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fscanf(fp, "%d ", &board[i][j]);
    }
  }
  fclose(fp);

  // Solve the Sudoku puzzle.
  if (solve_sudoku()) {
    // Print the solved Sudoku puzzle.
    printf("Solved Sudoku puzzle:\n");
    print_board();
  } else {
    printf("The Sudoku puzzle cannot be solved.\n");
  }

  return EXIT_SUCCESS;
}