//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  int width, height, generations;
  sscanf(argv[1], "%d", &width);
  sscanf(argv[2], "%d", &height);
  sscanf(argv[3], "%d", &generations);
  int **grid;
  grid = (int**)malloc(height * sizeof(int*));
  for (int i = 0; i < height; i++) {
    grid[i] = (int*)malloc(width * sizeof(int));
  }

  // Initialize the grid with random live cells
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int random = rand() % 2;
      grid[i][j] = random;
    }
  }

  // Simulate the Game of Life
  for (int i = 0; i < generations; i++) {
    // Update the grid for the next generation
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        // Count the number of live neighbors
        int neighbors = 0;
        int x, y;
        x = j - 1;
        y = i - 1;
        if (x >= 0 && y >= 0) {
          neighbors += grid[y][x];
        }
        x = j;
        y = i - 1;
        if (x >= 0 && y >= 0) {
          neighbors += grid[y][x];
        }
        x = j + 1;
        y = i - 1;
        if (x < width && y >= 0) {
          neighbors += grid[y][x];
        }
        x = j - 1;
        y = i;
        if (x >= 0 && y >= 0) {
          neighbors += grid[y][x];
        }
        x = j + 1;
        y = i;
        if (x < width && y >= 0) {
          neighbors += grid[y][x];
        }
        x = j;
        y = i + 1;
        if (x >= 0 && y < height) {
          neighbors += grid[y][x];
        }
        x = j - 1;
        y = i + 1;
        if (x >= 0 && y < height) {
          neighbors += grid[y][x];
        }

        // Determine if the cell should be alive or dead
        if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
          grid[i][j] = 1;
        } else if (grid[i][j] == 0 && neighbors == 3) {
          grid[i][j] = 1;
        }
      }
    }
  }

  // Print the final grid
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}