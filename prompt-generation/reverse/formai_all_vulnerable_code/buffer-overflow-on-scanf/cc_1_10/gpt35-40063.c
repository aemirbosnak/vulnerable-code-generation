//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];

// Function to find empty cell in the grid
bool findEmptyCell(int *row, int *col) {
  for (*row = 0; *row < N; (*row)++) {
    for (*col = 0; *col < N; (*col)++) {
      if (grid[*row][*col] == UNASSIGNED) {
        return true;
      }
    }
  }

  return false;
}

// Function to check if num can be placed in the specified cell
bool canPlace(int row, int col, int num) {
  // Check if num is already present in the same row
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return false;
    }
  }

  // Check if num is already present in the same column
  for (int j = 0; j < N; j++) {
    if (grid[j][col] == num) {
      return false;
    }
  }

  // Check if num is already present in the same 3x3 grid
  int gridRow = row - row % 3;
  int gridCol = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[gridRow + i][gridCol + j] == num) {
        return false;
      }
    }
  }

  return true;
}

// Sudoku solver function
bool solveSudoku() {
  int row, col;

  // Check if there is any empty cell left
  if (!findEmptyCell(&row, &col)) {
    return true;
  }

  // Try numbers from 1 to 9 in the empty cell
  for (int num = 1; num <= 9; num++) {
    if (canPlace(row, col, num)) {
      grid[row][col] = num;

      // Recur with next empty cell
      if (solveSudoku()) {
        return true;
      }

      // If recursion doesn't lead to solution, reset the value
      grid[row][col] = UNASSIGNED;
    }
  }

  // If none of the numbers work, backtrack
  return false;
}

int main() {
  printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");

  // Read the input grid from the user
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Solve the Sudoku puzzle using backtracking algorithm
  if (solveSudoku()) {
    printf("The solution to the Sudoku puzzle is:\n");

    // Display the solution
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("The given Sudoku puzzle has no solution.\n");
  }

  return 0;
}