//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1024

int main() {
  int **grid = NULL;
  int size = MAX_SIZE;
  int seed = time(NULL);
  int x, y, i, j, percolates = 0;

  // Allocate memory for the grid
  grid = (int**)malloc(size * sizeof(int*));
  for (i = 0; i < size; i++) {
    grid[i] = (int*)malloc(size * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      grid[i][j] = 0;
    }
  }

  // Percolation simulation
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (grid[i][j] == 0) {
        int r = rand() % size;
        int c = rand() % size;
        if (grid[r][c] == 1) {
          grid[i][j] = 1;
        }
      }
    }
  }

  // Check if the percolates
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (grid[i][j] == 1) {
        percolates = 1;
      }
    }
  }

  // Print the result
  if (percolates) {
    printf("Percolates!\n");
  } else {
    printf("Does not percolate.\n");
  }

  // Free the memory
  for (i = 0; i < size; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}