//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// Sudoku grid
int grid[N][N];

// Function to print the grid
void print_grid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the grid is valid
int is_valid() {
  // Check rows
  for (int i = 0; i < N; i++) {
    int row[N] = {0};
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        continue;
      }
      if (row[grid[i][j] - 1] == 1) {
        return 0;
      }
      row[grid[i][j] - 1] = 1;
    }
  }

  // Check columns
  for (int j = 0; j < N; j++) {
    int col[N] = {0};
    for (int i = 0; i < N; i++) {
      if (grid[i][j] == 0) {
        continue;
      }
      if (col[grid[i][j] - 1] == 1) {
        return 0;
      }
      col[grid[i][j] - 1] = 1;
    }
  }

  // Check boxes
  for (int i = 0; i < N; i += 3) {
    for (int j = 0; j < N; j += 3) {
      int box[N] = {0};
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (grid[i + k][j + l] == 0) {
            continue;
          }
          if (box[grid[i + k][j + l] - 1] == 1) {
            return 0;
          }
          box[grid[i + k][j + l] - 1] = 1;
        }
      }
    }
  }

  return 1;
}

// Function to solve the grid
int solve() {
  // Find an empty cell
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        goto found;
      }
    }
  }
  return 1;

found:
  // Try all possible values for the empty cell
  for (int value = 1; value <= N; value++) {
    // Check if the value is valid
    grid[row][col] = value;
    if (is_valid()) {
      // If the value is valid, solve the rest of the grid
      if (solve()) {
        return 1;
      }
    }
    // If the value is not valid, reset the cell to 0
    grid[row][col] = 0;
  }

  // If no valid values found, return 0
  return 0;
}

int main() {
  // Read the grid from the input
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }

  // Solve the grid
  if (solve()) {
    // Print the solved grid
    print_grid();
  } else {
    printf("No solution found.\n");
  }

  return 0;
}