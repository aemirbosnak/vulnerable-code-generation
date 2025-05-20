//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main() {
  // Allocate memory for the grid
  int **grid = (int**)malloc(WIDTH * sizeof(int *)), i, j;
  for (i = 0; i < WIDTH; i++) {
    grid[i] = (int *)malloc(HEIGHT * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      grid[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Percolation
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      if (grid[i][j] == 0) {
        int r = rand() % 2;
        if (r == 0) {
          grid[i][j] = 1;
        }
      }
    }
  }

  // Print the grid
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (i = 0; i < WIDTH; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}