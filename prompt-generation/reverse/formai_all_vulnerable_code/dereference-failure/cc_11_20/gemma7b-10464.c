//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
  int **grid = NULL;
  int x, y;
  int seed;

  // Allocate memory for the grid
  grid = (int **)malloc(WIDTH * sizeof(int *));
  for (x = 0; x < WIDTH; x++) {
    grid[x] = (int *)malloc(HEIGHT * sizeof(int));
  }

  // Initialize the grid
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      grid[x][y] = 0;
    }
  }

  // Set the seed
  seed = time(NULL);
  srand(seed);

  // Percolation
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      if (grid[x][y] == 0) {
        int neighbor_count = 0;
        // Check the neighbors
        if (x > 0 && grid[x - 1][y] == 1) {
          neighbor_count++;
        }
        if (x < WIDTH - 1 && grid[x + 1][y] == 1) {
          neighbor_count++;
        }
        if (y > 0 && grid[x][y - 1] == 1) {
          neighbor_count++;
        }
        if (y < HEIGHT - 1 && grid[x][y + 1] == 1) {
          neighbor_count++;
        }

        // If the neighbor count is greater than 0, set the cell to 1
        if (neighbor_count > 0) {
          grid[x][y] = 1;
        }
      }
    }
  }

  // Print the grid
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      printf("%d ", grid[x][y]);
    }
    printf("\n");
  }

  // Free the memory
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      free(grid[x][y]);
    }
    free(grid[x]);
  }
  free(grid);

  return 0;
}