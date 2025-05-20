//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9
#define BOX_SIZE 3
#define UNASSIGNED 0

// Helper function to print the Sudoku puzzle
void print_sudoku(int (*puzzle)[SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      printf("%d ", puzzle[row][col]);
    }
    printf("\n");
  }
}

// Helper function to check if a number is safe to assign to a given cell
int is_safe(int (*puzzle)[SIZE], int row, int col, int num) {
  // Check row
  for (int i = 0; i < SIZE; i++) {
    if (puzzle[row][i] == num) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < SIZE; i++) {
    if (puzzle[i][col] == num) {
      return 0;
    }
  }

  // Check box
  int box_row_start = row - row % BOX_SIZE;
  int box_col_start = col - col % BOX_SIZE;

  for (int i = box_row_start; i < box_row_start + BOX_SIZE; i++) {
    for (int j = box_col_start; j < box_col_start + BOX_SIZE; j++) {
      if (puzzle[i][j] == num) {
        return 0;
      }
    }
  }

  // If all checks pass, return 1
  return 1;
}

// Recursive function to solve the Sudoku puzzle
int solve_sudoku(int (*puzzle)[SIZE], int row, int col) {
  // Base case: all cells filled
  if (row == SIZE) {
    return 1;
  }

  // If the current cell is already assigned, move to the next cell
  if (puzzle[row][col] != UNASSIGNED) {
    if (col == SIZE - 1) {
      return solve_sudoku(puzzle, row + 1, 0);
    } else {
      return solve_sudoku(puzzle, row, col + 1);
    }
  }

  // Try all possible values for the current cell
  for (int num = 1; num <= SIZE; num++) {
    if (is_safe(puzzle, row, col, num)) {
      // Assign the number to the cell
      puzzle[row][col] = num;

      // Recursively solve the rest of the puzzle
      if (col == SIZE - 1) {
        if (solve_sudoku(puzzle, row + 1, 0)) {
          return 1;
        }
      } else {
        if (solve_sudoku(puzzle, row, col + 1)) {
          return 1;
        }
      }

      // If the recursive call fails, reset the cell value
      puzzle[row][col] = UNASSIGNED;
    }
  }

  // If no valid value can be found, return 0
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  // Open the input file
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error opening input file: %s\n", argv[1]);
    return 1;
  }

  // Read the Sudoku puzzle from the file
  int puzzle[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      fscanf(input_file, "%d ", &puzzle[i][j]);
    }
  }

  // Close the input file
  fclose(input_file);

  // Print the original puzzle
  printf("Original puzzle:\n");
  print_sudoku(puzzle);

  // Solve the Sudoku puzzle
  if (solve_sudoku(puzzle, 0, 0)) {
    // Print the solved puzzle
    printf("\nSolved puzzle:\n");
    print_sudoku(puzzle);
  } else {
    printf("\nNo solution found.\n");
  }

  return 0;
}