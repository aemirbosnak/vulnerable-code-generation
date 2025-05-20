//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 9

// Declare the Sudoku grid
int grid[GRID_SIZE][GRID_SIZE];

// Function to print the Sudoku grid
void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
int is_safe(int row, int col, int num) {
  // Check the row and column
  for (int i = 0; i < GRID_SIZE; i++) {
    if (grid[row][i] == num || grid[i][col] == num) {
      return 0;
    }
  }

  // Check the 3x3 subgrid
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return 0;
      }
    }
  }

  // The number is safe to place
  return 1;
}

// Recursive function to solve the Sudoku puzzle
int solve_sudoku(int row, int col) {
  // Base case: If we have reached the end of the grid, the puzzle is solved
  if (row == GRID_SIZE - 1 && col == GRID_SIZE) {
    return 1;
  }

  // If we have reached the end of a row, move to the next row
  if (col == GRID_SIZE) {
    row++;
    col = 0;
  }

  // If the current cell is already filled, move to the next cell
  if (grid[row][col] != 0) {
    return solve_sudoku(row, col + 1);
  }

  // Try all possible numbers for the current cell
  for (int num = 1; num <= GRID_SIZE; num++) {
    // If the number is safe to place, place it and move to the next cell
    if (is_safe(row, col, num)) {
      grid[row][col] = num;
      if (solve_sudoku(row, col + 1)) {
        return 1;
      }
    }
  }

  // If none of the numbers are safe to place, backtrack and try the next cell
  grid[row][col] = 0;
  return 0;
}

int main() {
  // Read the Sudoku puzzle from the user
  printf("Enter the Sudoku puzzle:\n");
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Print the original Sudoku puzzle
  printf("Original Sudoku puzzle:\n");
  print_grid();

  // Solve the Sudoku puzzle
  if (solve_sudoku(0, 0)) {
    // Print the solved Sudoku puzzle
    printf("Solved Sudoku puzzle:\n");
    print_grid();
  } else {
    printf("The Sudoku puzzle is unsolvable.\n");
  }

  return 0;
}