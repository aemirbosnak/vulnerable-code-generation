//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main() {
  int **grid = NULL;
  int x, y;
  int gen = 0;

  // Allocate memory for the grid
  grid = malloc(MAX * sizeof(int *));
  for (x = 0; x < MAX; x++) {
    grid[x] = malloc(MAX * sizeof(int));
  }

  // Initialize the grid
  for (x = 0; x < MAX; x++) {
    for (y = 0; y < MAX; y++) {
      grid[x][y] = 0;
    }
  }

  // Set some initial values
  grid[5][5] = 1;
  grid[5][6] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;

  // Game loop
  while (1) {
    gen++;
    // Calculate the next generation
    for (x = 0; x < MAX; x++) {
      for (y = 0; y < MAX; y++) {
        int neighbors = 0;
        // Count the number of neighbors
        if (x > 0) neighbors++;
        if (x < MAX - 1) neighbors++;
        if (y > 0) neighbors++;
        if (y < MAX - 1) neighbors++;

        // Apply the Game of Life rules
        if (grid[x][y] == 1 && neighbors < 2) grid[x][y] = 0;
        if (grid[x][y] == 0 && neighbors == 3) grid[x][y] = 1;
      }
    }

    // Print the grid
    for (x = 0; x < MAX; x++) {
      for (y = 0; y < MAX; y++) {
        printf("%d ", grid[x][y]);
      }
      printf("\n");
    }

    // Check if the game is over
    if (gen == 10) break;
  }

  // Free memory
  for (x = 0; x < MAX; x++) {
    free(grid[x]);
  }
  free(grid);

  return 0;
}