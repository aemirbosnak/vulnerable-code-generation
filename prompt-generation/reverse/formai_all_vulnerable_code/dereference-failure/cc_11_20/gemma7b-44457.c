//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 200

int main() {
  int **cells = NULL;
  int i, j, k, num_alive = 0;
  cells = (int **)malloc(MAX_CELLS * sizeof(int *));
  for (i = 0; i < MAX_CELLS; i++) {
    cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
  }

  // Initialize the game board
  for (i = 0; i < MAX_CELLS; i++) {
    for (j = 0; j < MAX_CELLS; j++) {
      cells[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Create a random number of living cells
  num_alive = rand() % MAX_CELLS * MAX_CELLS;

  // Place the living cells
  for (k = 0; k < num_alive; k++) {
    cells[rand() % MAX_CELLS][rand() % MAX_CELLS] = 1;
  }

  // Run the game for 20 generations
  for (k = 0; k < 20; k++) {
    // Calculate the number of living neighbors for each cell
    for (i = 0; i < MAX_CELLS; i++) {
      for (j = 0; j < MAX_CELLS; j++) {
        int num_neighbors = 0;
        if (cells[i - 1][j] == 1) num_neighbors++;
        if (cells[i + 1][j] == 1) num_neighbors++;
        if (cells[i][j - 1] == 1) num_neighbors++;
        if (cells[i][j + 1] == 1) num_neighbors++;
        if (cells[i][j] == 1 && num_neighbors < 2) cells[i][j] = 0;
        else if (cells[i][j] == 0 && num_neighbors == 3) cells[i][j] = 1;
      }
    }
  }

  // Print the final game board
  for (i = 0; i < MAX_CELLS; i++) {
    for (j = 0; j < MAX_CELLS; j++) {
      printf("%d ", cells[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (i = 0; i < MAX_CELLS; i++) {
    free(cells[i]);
  }
  free(cells);

  return 0;
}