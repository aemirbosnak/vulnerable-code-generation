//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: shocked
// Game of Life in C - Shocked Style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

void print_grid(int grid[WIDTH][HEIGHT]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c ", grid[i][j] == 0 ? '.' : '*');
    }
    printf("\n");
  }
}

void update_grid(int grid[WIDTH][HEIGHT]) {
  int next_grid[WIDTH][HEIGHT];

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int alive_neighbors = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (grid[(i + k + HEIGHT) % HEIGHT][(j + l + WIDTH) % WIDTH] == 1) {
            alive_neighbors++;
          }
        }
      }
      if (alive_neighbors == 3 || (alive_neighbors == 2 && grid[i][j] == 1)) {
        next_grid[i][j] = 1;
      } else {
        next_grid[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = next_grid[i][j];
    }
  }
}

int main() {
  int grid[WIDTH][HEIGHT];
  srand(time(NULL));

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  print_grid(grid);

  while (1) {
    update_grid(grid);
    print_grid(grid);
    sleep(1);
  }

  return 0;
}