//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void game_of_life(int **grid, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      int neighbors = 0;
      // Check the 8 neighbors
      if (r > 0) neighbors++;
      if (r < size - 1) neighbors++;
      if (c > 0) neighbors++;
      if (c < size - 1) neighbors++;
      if (r > 0 && c > 0) neighbors++;
      if (r > 0 && c < size - 1) neighbors++;
      if (r < size - 1 && c > 0) neighbors++;
      if (r < size - 1 && c < size - 1) neighbors++;

      // Apply the Game of Life rules
      if (neighbors < 2) grid[r][c] = 0;
      else if (neighbors == 2) grid[r][c] = 1;
      else if (neighbors > 3) grid[r][c] = 0;
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **grid = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    grid[i] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      grid[r][c] = 0;
    }
  }

  // Set some initial cells to 1
  grid[10][10] = 1;
  grid[10][11] = 1;
  grid[11][10] = 1;

  // Run the game for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    game_of_life(grid, size);
  }

  // Print the final grid
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < size; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}