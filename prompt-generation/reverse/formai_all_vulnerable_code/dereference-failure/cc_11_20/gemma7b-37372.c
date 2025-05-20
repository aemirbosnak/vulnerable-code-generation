//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 8
#define HEIGHT 8

#define DELAY 5

int main() {
  int **grid = NULL;
  int x, y, i, j;

  // Allocate memory for the grid
  grid = malloc(HEIGHT * sizeof(int *));
  for (i = 0; i < HEIGHT; i++) {
    grid[i] = malloc(WIDTH * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      grid[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Simulate the percolation process
  for (i = 0; i < DELAY; i++) {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;

    // If the cell is not already wet and there is a chance of it becoming wet
    if (grid[y][x] == 0 && rand() % 2 == 0) {
      // Make the cell wet
      grid[y][x] = 1;

      // Spread the wetness to the neighboring cells
      if (x > 0) grid[y][x - 1] = 1;
      if (x < WIDTH - 1) grid[y][x + 1] = 1;
      if (y > 0) grid[y - 1][x] = 1;
      if (y < HEIGHT - 1) grid[y + 1][x] = 1;
    }
  }

  // Print the grid
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}