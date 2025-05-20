//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_SIZE 9
#define GRID_SIZE SUDOKU_SIZE * SUDOKU_SIZE
#define BOX_SIZE 3

// The Sudoku puzzle grid
int grid[GRID_SIZE];

// Function to check if a number is valid in a cell
int is_valid(int cell, int number) {
  // Check the row
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (grid[cell / SUDOKU_SIZE * SUDOKU_SIZE + i] == number) {
      return 0;
    }
  }

  // Check the column
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (grid[cell % SUDOKU_SIZE + i * SUDOKU_SIZE] == number) {
      return 0;
    }
  }

  // Check the box
  int box_row = cell / SUDOKU_SIZE / BOX_SIZE;
  int box_col = cell % SUDOKU_SIZE / BOX_SIZE;
  for (int i = 0; i < BOX_SIZE; i++) {
    for (int j = 0; j < BOX_SIZE; j++) {
      if (grid[box_row * BOX_SIZE * SUDOKU_SIZE + box_col * BOX_SIZE + i * SUDOKU_SIZE + j] == number) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to solve the Sudoku puzzle
int solve(int cell) {
  // If we have reached the end of the grid, the puzzle is solved
  if (cell == GRID_SIZE) {
    return 1;
  }

  // If the cell is already filled, move on to the next cell
  if (grid[cell] != 0) {
    return solve(cell + 1);
  }

  // Try all possible numbers for the cell
  for (int number = 1; number <= SUDOKU_SIZE; number++) {
    if (is_valid(cell, number)) {
      grid[cell] = number;

      // If the number is valid, solve the rest of the puzzle
      if (solve(cell + 1)) {
        return 1;
      }

      // If the number is not valid, reset the cell and try the next number
      grid[cell] = 0;
    }
  }

  return 0;
}

// Function to print the Sudoku puzzle
void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    if (i % SUDOKU_SIZE == 0) {
      printf("\n");
    }
    printf("%d ", grid[i]);
  }
  printf("\n");
}

int main() {
  // Get the Sudoku puzzle from the user
  printf("Enter the Sudoku puzzle:\n");
  for (int i = 0; i < GRID_SIZE; i++) {
    scanf("%d", &grid[i]);
  }

  // Solve the Sudoku puzzle
  if (solve(0)) {
    printf("The solution to the Sudoku puzzle is:\n");
    print_grid();
  } else {
    printf("The Sudoku puzzle cannot be solved.\n");
  }

  return 0;
}