//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void drawGrid(int **grid, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", grid[r][c] == 0 ? '.' : grid[r][c] == 1 ? 'O' : 'X');
    }
    printf("\n");
  }
}

int main() {
  int size = MAX_SIZE;
  int **grid = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++) {
    grid[r] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      grid[r][c] = 0;
    }
  }

  // Create a random pattern
  grid[5][5] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;
  grid[7][5] = 1;
  grid[7][6] = 1;

  // Simulate Game of Life
  for (int t = 0; t < 10; t++) {
    drawGrid(grid, size);
    printf("Generation %d:\n", t + 1);

    // Calculate the next generation
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int neighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (r + dr >= 0 && r + dr < size && c + dc >= 0 && c + dc < size && grid[r + dr][c + dc] == 1) {
              neighbors++;
            }
          }
        }
        if (neighbors < 2) {
          grid[r][c] = 0;
        } else if (neighbors > 3) {
          grid[r][c] = 0;
        } else if (grid[r][c] == 0 && neighbors == 2) {
          grid[r][c] = 1;
        }
      }
    }
  }

  drawGrid(grid, size);
  printf("Final Generation:\n");

  free(grid);
  return 0;
}