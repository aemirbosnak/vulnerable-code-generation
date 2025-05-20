//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10

int main() {
  int **grid = NULL;
  int i, j, k, x, y;

  grid = (int**)malloc(DIM * sizeof(int *));
  for (i = 0; i < DIM; i++) {
    grid[i] = (int *)malloc(DIM * sizeof(int));
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      grid[i][j] = 0;
    }
  }

  x = rand() % DIM;
  y = rand() % DIM;
  grid[x][y] = 1;

  k = 0;
  while (k < 10) {
    for (i = 0; i < DIM; i++) {
      for (j = 0; j < DIM; j++) {
        if (grid[i][j] == 1) {
          printf("(%d, %d) is wet\n", i, j);
          // Dig neighbor cells
          if (i - 1 >= 0 && grid[i - 1][j] == 0) {
            grid[i - 1][j] = 1;
          }
          if (i + 1 < DIM && grid[i + 1][j] == 0) {
            grid[i + 1][j] = 1;
          }
          if (j - 1 >= 0 && grid[i][j - 1] == 0) {
            grid[i][j - 1] = 1;
          }
          if (j + 1 < DIM && grid[i][j + 1] == 0) {
            grid[i][j + 1] = 1;
          }
        }
      }
    }

    k++;
  }

  for (i = 0; i < DIM; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}