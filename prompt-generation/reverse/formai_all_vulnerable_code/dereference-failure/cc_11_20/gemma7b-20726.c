//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main() {
  int **grid;
  int rows, cols;
  int iteration = 0;
  int x, y;
  srand(time(NULL));

  // Allocate memory for the grid
  rows = 10;
  cols = 10;
  grid = (int *)malloc(rows * cols * sizeof(int));
  for (int i = 0; i < rows * cols; i++) {
    grid[i] = 0;
  }

  // Percolation simulation
  while (iteration < MAX_ITERATIONS) {
    for (x = 0; x < rows; x++) {
      for (y = 0; y < cols; y++) {
        if (grid[x][y] == 0) {
          int neighbor_count = 0;
          // Check the four neighbors
          if (x > 0 && grid[x - 1][y] == 1) {
            neighbor_count++;
          }
          if (x < rows - 1 && grid[x + 1][y] == 1) {
            neighbor_count++;
          }
          if (y > 0 && grid[x][y - 1] == 1) {
            neighbor_count++;
          }
          if (y < cols - 1 && grid[x][y + 1] == 1) {
            neighbor_count++;
          }

          // If the neighbor count is greater than 0, the cell becomes wet
          if (neighbor_count > 0) {
            grid[x][y] = 1;
          }
        }
      }
    }

    // Increment the iteration count
    iteration++;
  }

  // Print the final grid
  for (x = 0; x < rows; x++) {
    for (y = 0; y < cols; y++) {
      printf("%d ", grid[x][y]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  free(grid);

  return 0;
}