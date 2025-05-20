//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define N 9

// The grid is represented as a 2D array of integers
int grid[N][N];

// Function to print the grid
void print_grid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", grid[i][j]);
      if (j < N - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Function to check if the grid is valid
int is_valid() {
  // Check for duplicate numbers in each row
  for (int i = 0; i < N; i++) {
    int numbers[N] = {0};
    for (int j = 0; j < N; j++) {
      if (grid[i][j] != 0 && numbers[grid[i][j] - 1] == 1) {
        return 0;
      }
      numbers[grid[i][j] - 1] = 1;
    }
  }

  // Check for duplicate numbers in each column
  for (int i = 0; i < N; i++) {
    int numbers[N] = {0};
    for (int j = 0; j < N; j++) {
      if (grid[j][i] != 0 && numbers[grid[j][i] - 1] == 1) {
        return 0;
      }
      numbers[grid[j][i] - 1] = 1;
    }
  }

  // Check for duplicate numbers in each 3x3 box
  for (int i = 0; i < N; i += 3) {
    for (int j = 0; j < N; j += 3) {
      int numbers[N] = {0};
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (grid[i + k][j + l] != 0 && numbers[grid[i + k][j + l] - 1] == 1) {
            return 0;
          }
          numbers[grid[i + k][j + l] - 1] = 1;
        }
      }
    }
  }

  return 1;
}

// Function to solve the grid
int solve() {
  // If the grid is valid, print it and return 1
  if (is_valid()) {
    print_grid();
    return 1;
  }

  // Find the first empty cell
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        goto found;
      }
    }
  }

  // No empty cells found, the grid is unsolvable
  return 0;

found:
  // Try all possible values for the empty cell
  for (int k = 1; k <= N; k++) {
    // Set the empty cell to the current value
    grid[i][j] = k;

    // Recursively solve the grid
    if (solve()) {
      return 1;
    }

    // If the grid is not solvable, reset the empty cell to 0
    grid[i][j] = 0;
  }

  // No solution found for the current value, backtrack
  return 0;
}

int main() {
  // Get the grid from the user
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Solve the grid
  if (solve()) {
    printf("The grid has been solved successfully.\n");
  } else {
    printf("The grid is unsolvable.\n");
  }

  return 0;
}