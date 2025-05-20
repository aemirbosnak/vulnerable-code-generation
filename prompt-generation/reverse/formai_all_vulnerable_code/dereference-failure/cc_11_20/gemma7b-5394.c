//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 512

#define MAX_ITERATIONS 1000

int main() {
  int **grid = NULL;
  int i, j, k, iteration = 0;
  int seed = time(NULL);

  // Allocate memory for the grid
  grid = (int **)malloc(DIM * sizeof(int *));
  for (i = 0; i < DIM; i++) {
    grid[i] = (int *)malloc(DIM * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      grid[i][j] = 0;
    }
  }

  // Randomly fill the grid
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  // Percolation algorithm
  while (iteration < MAX_ITERATIONS) {
    for (i = 0; i < DIM; i++) {
      for (j = 0; j < DIM; j++) {
        if (grid[i][j] == 1) {
          // Check the four neighbors of the current cell
          if (grid[i-1][j] == 1) grid[i-1][j] = 1;
          if (grid[i+1][j] == 1) grid[i+1][j] = 1;
          if (grid[i][j-1] == 1) grid[i][j-1] = 1;
          if (grid[i][j+1] == 1) grid[i][j+1] = 1;
        }
      }
    }

    // Count the number of filled cells
    int num_filled = 0;
    for (i = 0; i < DIM; i++) {
      for (j = 0; j < DIM; j++) {
        if (grid[i][j] == 1) num_filled++;
      }
    }

    // Print the number of filled cells
    printf("Number of filled cells after iteration %d: %d\n", iteration, num_filled);

    iteration++;
  }

  // Free memory
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      free(grid[i][j]);
    }
    free(grid[i]);
  }

  free(grid);

  return 0;
}