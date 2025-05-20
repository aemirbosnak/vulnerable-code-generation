//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main() {
  int i, j, x, y, n, p, seed;
  n = MAX;
  p = 0.5;
  seed = time(NULL);

  // Allocate memory for the grid
  int **grid = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    grid[i] = (int *)malloc(n * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      grid[i][j] = 0;
    }
  }

  // Percolation
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      x = rand() % n;
      y = rand() % n;
      if (grid[x][y] == 0 && rand() % 2 == 0) {
        grid[x][y] = 1;
      }
    }
  }

  // Print the grid
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (i = 0; i < n; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}