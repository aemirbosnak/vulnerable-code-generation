//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a 2D array to store the game of life cells
  int **cells = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    cells[i] = (int *)malloc(5 * sizeof(int));
  }

  // Initialize the cells
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cells[i][j] = rand() % 2;
    }
  }

  // Simulate the game of life for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    // Calculate the number of neighbors for each cell
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int num_neighbors = 0;
        for (int r = -1; r <= 1; r++) {
          for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) continue;
            if (cells[i + r][j + c] == 1) num_neighbors++;
          }
        }
        // Apply the game of life rules
        if (cells[i][j] == 1 && num_neighbors < 2) cells[i][j] = 0;
        else if (cells[i][j] == 0 && num_neighbors == 3) cells[i][j] = 1;
      }
    }
  }

  // Print the final state of the cells
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", cells[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the cells
  for (int i = 0; i < 5; i++) {
    free(cells[i]);
  }
  free(cells);

  return 0;
}