//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
// Game of Life in C
//
// Usage: ./game_of_life [width] [height]
//
// Example: ./game_of_life 10 10
//
// The Game of Life is a cellular automaton devised by John Horton Conway in 1970.
// The game is a simple simulation of a two-dimensional grid of cells.
// The cells are either alive or dead, and the rules for determining the next state of a cell
// depend on the current state of the cell and its neighbors.
//
// The rules are as follows:
// 1. Any live cell with fewer than two live neighbors dies (underpopulation)
// 2. Any live cell with two or three live neighbors remains alive (survival)
// 3. Any live cell with more than three live neighbors dies (overpopulation)
// 4. Any dead cell with exactly three live neighbors becomes alive (reproduction)
//
// The program takes two arguments, the width and height of the grid, and displays
// the grid at each iteration. The user can press any key to advance to the next
// iteration, or press 'q' to quit.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define SIZE (WIDTH * HEIGHT)

typedef struct {
  int alive;
  int neighbors;
} cell_t;

void display_grid(cell_t grid[WIDTH][HEIGHT]) {
  int i, j;

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%c", grid[i][j].alive ? '*' : ' ');
    }
    printf("\n");
  }
}

int get_neighbors(cell_t grid[WIDTH][HEIGHT], int i, int j) {
  int count = 0;
  int row, col;

  for (row = i - 1; row <= i + 1; row++) {
    for (col = j - 1; col <= j + 1; col++) {
      if (row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH &&
          (row != i || col != j) && grid[row][col].alive) {
        count++;
      }
    }
  }

  return count;
}

void update_grid(cell_t grid[WIDTH][HEIGHT]) {
  int i, j;
  cell_t new_grid[WIDTH][HEIGHT];

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      new_grid[i][j].alive = grid[i][j].alive;
      new_grid[i][j].neighbors = get_neighbors(grid, i, j);

      if (grid[i][j].alive) {
        if (new_grid[i][j].neighbors < 2) {
          new_grid[i][j].alive = 0;
        } else if (new_grid[i][j].neighbors > 3) {
          new_grid[i][j].alive = 0;
        }
      } else if (new_grid[i][j].neighbors == 3) {
        new_grid[i][j].alive = 1;
      }
    }
  }

  memcpy(grid, new_grid, sizeof(new_grid));
}

int main(int argc, char **argv) {
  int width, height;
  cell_t grid[WIDTH][HEIGHT];
  char ch;

  if (argc != 3) {
    printf("Usage: ./game_of_life [width] [height]\n");
    return 1;
  }

  width = atoi(argv[1]);
  height = atoi(argv[2]);

  if (width < 1 || height < 1) {
    printf("Invalid dimensions\n");
    return 1;
  }

  if (width > WIDTH || height > HEIGHT) {
    printf("Dimensions exceed maximum size\n");
    return 1;
  }

  memset(grid, 0, sizeof(grid));

  // Initialize the grid with a random pattern
  srand(time(NULL));
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      grid[i][j].alive = rand() % 2;
    }
  }

  // Display the grid and wait for user input
  while (1) {
    display_grid(grid);
    printf("\nPress any key to advance to the next iteration, 'q' to quit\n");
    ch = getchar();

    if (ch == 'q') {
      break;
    }

    update_grid(grid);
  }

  return 0;
}