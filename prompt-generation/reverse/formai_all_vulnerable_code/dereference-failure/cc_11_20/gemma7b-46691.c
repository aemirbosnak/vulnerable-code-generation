//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
  int **grid = (int **)malloc(HEIGHT * sizeof(int *));
  for (int r = 0; r < HEIGHT; r++) {
    grid[r] = (int *)malloc(WIDTH * sizeof(int));
  }

  // Seed the random number generator
  srand(time(NULL));

  // Percolation simulation
  for (int t = 0; t < 1000; t++) {
    for (int r = 0; r < HEIGHT; r++) {
      for (int c = 0; c < WIDTH; c++) {
        int probability = rand() % 10;
        if (probability < 5) {
          grid[r][c] = 1;
        } else {
          grid[r][c] = 0;
        }
      }
    }

    // Check if the simulation has reached the desired state
    int is_percolated = 0;
    for (int r = 0; r < HEIGHT; r++) {
      for (int c = 0; c < WIDTH; c++) {
        if (grid[r][c] == 1) {
          int is_connected = 0;
          for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
              if (grid[r + dr][c + dc] == 1) {
                is_connected = 1;
              }
            }
          }
          if (is_connected) {
            is_percolated = 1;
          }
        }
      }
    }

    // If the simulation has reached the desired state, break out of the loop
    if (is_percolated) {
      break;
    }
  }

  // Free the memory allocated for the grid
  for (int r = 0; r < HEIGHT; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}