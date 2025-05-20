//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

// Define the Game of Life rules
void game_of_life(int **cells, int num_cells) {
  int i, j, k, alive_neighbors, is_alive = 0;

  for (i = 0; i < num_cells; i++) {
    for (j = 0; j < num_cells; j++) {
      alive_neighbors = 0;

      // Check the neighbors of the current cell
      for (k = -1; k <= 1; k++) {
        if (i + k < 0 || i + k >= num_cells) continue;
        for (int l = -1; l <= 1; l++) {
          if (j + l < 0 || j + l >= num_cells) continue;
          if (cells[i + k][j + l] == 1) alive_neighbors++;
        }
      }

      // Apply the rules of life
      if (cells[i][j] == 1 && alive_neighbors < 2) is_alive = 0;
      if (cells[i][j] == 0 && alive_neighbors == 3) is_alive = 1;

      cells[i][j] = is_alive;
    }
  }
}

int main() {
  int num_cells = MAX_CELLS;
  int **cells = (int **)malloc(num_cells * sizeof(int *));
  for (int i = 0; i < num_cells; i++) {
    cells[i] = (int *)malloc(num_cells * sizeof(int));
  }

  // Initialize the cell array
  for (int i = 0; i < num_cells; i++) {
    for (int j = 0; j < num_cells; j++) {
      cells[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Create a random pattern of alive cells
  for (int i = 0; i < num_cells; i++) {
    for (int j = 0; j < num_cells; j++) {
      cells[i][j] = rand() % 2;
    }
  }

  // Play the game of life
  game_of_life(cells, num_cells);

  // Print the final pattern of alive cells
  for (int i = 0; i < num_cells; i++) {
    for (int j = 0; j < num_cells; j++) {
      printf("%d ", cells[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < num_cells; i++) {
    free(cells[i]);
  }
  free(cells);

  return 0;
}