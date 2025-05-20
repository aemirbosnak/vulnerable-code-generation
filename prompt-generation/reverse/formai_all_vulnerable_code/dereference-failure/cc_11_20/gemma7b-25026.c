//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main() {
  int **grid = NULL;
  int x, y;
  int seed = time(NULL);
  srand(seed);

  // Allocate memory for the grid
  grid = (int **)malloc(HEIGHT * sizeof(int *));
  for (y = 0; y < HEIGHT; y++) {
    grid[y] = (int *)malloc(WIDTH * sizeof(int));
  }

  // Initialize the grid
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      grid[y][x] = rand() % 2;
    }
  }

  // Percolation simulation
  for (int iteration = 0; iteration < 1000; iteration++) {
    for (y = 0; y < HEIGHT; y++) {
      for (x = 0; x < WIDTH; x++) {
        if (grid[y][x] == 1) {
          int neighbors = 0;
          // Check the neighbors
          if (grid[y - 1][x] == 1) neighbors++;
          if (grid[y + 1][x] == 1) neighbors++;
          if (grid[y][x - 1] == 1) neighbors++;
          if (grid[y][x + 1] == 1) neighbors++;

          // If the number of neighbors is greater than 1, the cell becomes active
          if (neighbors > 1) grid[y][x] = 2;
        }
      }
    }
  }

  // Print the final grid
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      printf("%d ", grid[y][x]);
    }
    printf("\n");
  }

  // Free the memory
  for (y = 0; y < HEIGHT; y++) {
    free(grid[y]);
  }
  free(grid);

  return 0;
}