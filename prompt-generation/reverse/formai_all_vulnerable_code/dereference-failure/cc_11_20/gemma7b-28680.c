//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main() {
  int **grid = (int **)malloc(WIDTH * sizeof(int *));
  for (int i = 0; i < WIDTH; i++) {
    grid[i] = (int *)malloc(HEIGHT * sizeof(int));
  }

  // Seed the random number generator
  srand(time(NULL));

  // Initialize the grid
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  // Game loop
  while (1) {
    // Print the grid
    for (int i = 0; i < WIDTH; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }

    // Calculate the next generation
    for (int i = 0; i < WIDTH; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        int neighbors = 0;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) {
              continue;
            }
            if (grid[i + x][j + y] == 1) {
              neighbors++;
            }
          }
        }
        if (grid[i][j] == 1 && neighbors < 2) {
          grid[i][j] = 0;
        } else if (grid[i][j] == 0 && neighbors == 3) {
          grid[i][j] = 1;
        }
      }
    }

    // Pause
    system("pause");
  }

  // Free the memory
  for (int i = 0; i < WIDTH; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}