//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **grid = NULL;
  int rows = 5, cols = 5;
  int generation = 0;

  // Allocate memory for the grid
  grid = (int**)malloc(rows * sizeof(int*));
  for (int r = 0; r < rows; r++) {
    grid[r] = (int*)malloc(cols * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = 0;
    }
  }

  // Set some cells to 1
  grid[2][2] = 1;
  grid[2][3] = 1;
  grid[3][2] = 1;

  // Simulate Game of Life for 2 generations
  for (generation = 0; generation < 2; generation++) {
    // Calculate the number of neighbors for each cell
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int neighbors = 0;
        // Check the cells to the left
        if (c - 1 >= 0) {
          neighbors++;
        }
        // Check the cells above
        if (r - 1 >= 0) {
          neighbors++;
        }
        // Check the cells to the right
        if (c + 1 < cols) {
          neighbors++;
        }
        // Check the cells below
        if (r + 1 < rows) {
          neighbors++;
        }
        // Update the cell's status
        if (neighbors == 3) {
          grid[r][c] = 1;
        } else if (neighbors == 2) {
          grid[r][c] = 0;
        }
      }
    }
  }

  // Print the final grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < rows; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}