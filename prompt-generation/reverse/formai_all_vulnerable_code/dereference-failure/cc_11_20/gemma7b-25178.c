//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

void draw_grid(int **grid) {
  for (int r = 0; r < GRID_SIZE; r++) {
    for (int c = 0; c < GRID_SIZE; c++) {
      printf("%c ", grid[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **grid = (int **)malloc(GRID_SIZE * sizeof(int *));
  for (int r = 0; r < GRID_SIZE; r++) {
    grid[r] = (int *)malloc(GRID_SIZE * sizeof(int));
  }

  // Initialize the grid with random values
  for (int r = 0; r < GRID_SIZE; r++) {
    for (int c = 0; c < GRID_SIZE; c++) {
      grid[r][c] = rand() % 2;
    }
  }

  // Draw the grid
  draw_grid(grid);

  // Simulate game of life
  for (int t = 0; t < 10; t++) {
    // Calculate the next generation
    int **next_grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int r = 0; r < GRID_SIZE; r++) {
      next_grid[r] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    for (int r = 0; r < GRID_SIZE; r++) {
      for (int c = 0; c < GRID_SIZE; c++) {
        int neighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (r + dr >= 0 && r + dr < GRID_SIZE && c + dc >= 0 && c + dc < GRID_SIZE && grid[r + dr][c + dc]) {
              neighbors++;
            }
          }
        }

        next_grid[r][c] = (neighbors == 2 || neighbors == 3) && grid[r][c] ? 1 : 0;
      }
    }

    // Free the previous grid
    for (int r = 0; r < GRID_SIZE; r++) {
      free(grid[r]);
    }
    free(grid);

    // Draw the next generation
    draw_grid(next_grid);

    // Copy the next generation to the previous grid
    for (int r = 0; r < GRID_SIZE; r++) {
      for (int c = 0; c < GRID_SIZE; c++) {
        grid[r][c] = next_grid[r][c];
      }
    }

    // Free the next generation grid
    for (int r = 0; r < GRID_SIZE; r++) {
      free(next_grid[r]);
    }
    free(next_grid);
  }

  return 0;
}