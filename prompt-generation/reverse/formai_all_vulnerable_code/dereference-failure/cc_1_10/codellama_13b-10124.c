//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: authentic
// A unique C Game of Life example program in an authentic style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Define the size of the grid
#define GRID_WIDTH 30
#define GRID_HEIGHT 30

// Define the initial state of the grid
#define GRID_INIT_STATE ".......O.......O.......O.......O.......O.......O.......O......."

// Define the number of steps to simulate
#define STEPS 10000

// Define the colors for the grid
#define GRID_COLOR_ALIVE "O"
#define GRID_COLOR_DEAD "."

// Define the rules for the game of life
#define RULE_1 "Any live cell with fewer than two live neighbors dies, as if by underpopulation."
#define RULE_2 "Any live cell with two or three live neighbors lives on to the next generation."
#define RULE_3 "Any live cell with more than three live neighbors dies, as if by overpopulation."
#define RULE_4 "Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction."

// Define the game of life function
void game_of_life(char *grid) {
  // Create a new grid to store the new state
  char *new_grid = (char *) malloc(GRID_WIDTH * GRID_HEIGHT);
  memset(new_grid, 0, GRID_WIDTH * GRID_HEIGHT);

  // Iterate over each cell in the grid
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      // Count the number of live neighbors
      int live_neighbors = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (k == 0 && l == 0) continue;
          int neighbor_x = (i + k + GRID_WIDTH) % GRID_WIDTH;
          int neighbor_y = (j + l + GRID_HEIGHT) % GRID_HEIGHT;
          if (grid[neighbor_x * GRID_WIDTH + neighbor_y] == GRID_COLOR_ALIVE) {
            live_neighbors++;
          }
        }
      }

      // Apply the rules
      if (grid[i * GRID_WIDTH + j] == GRID_COLOR_ALIVE) {
        if (live_neighbors < 2) {
          new_grid[i * GRID_WIDTH + j] = GRID_COLOR_DEAD;
        } else if (live_neighbors == 2 || live_neighbors == 3) {
          new_grid[i * GRID_WIDTH + j] = GRID_COLOR_ALIVE;
        } else if (live_neighbors > 3) {
          new_grid[i * GRID_WIDTH + j] = GRID_COLOR_DEAD;
        }
      } else {
        if (live_neighbors == 3) {
          new_grid[i * GRID_WIDTH + j] = GRID_COLOR_ALIVE;
        }
      }
    }
  }

  // Update the grid
  memcpy(grid, new_grid, GRID_WIDTH * GRID_HEIGHT);
  free(new_grid);
}

// Define the main function
int main(void) {
  // Initialize the grid
  char *grid = (char *) malloc(GRID_WIDTH * GRID_HEIGHT);
  memset(grid, 0, GRID_WIDTH * GRID_HEIGHT);
  memcpy(grid, GRID_INIT_STATE, strlen(GRID_INIT_STATE));

  // Print the initial state of the grid
  printf("Initial state of the grid:\n");
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      printf("%c", grid[i * GRID_WIDTH + j]);
    }
    printf("\n");
  }
  printf("\n");

  // Simulate the game of life
  for (int i = 0; i < STEPS; i++) {
    game_of_life(grid);
    printf("Step %d:\n", i + 1);
    for (int i = 0; i < GRID_WIDTH; i++) {
      for (int j = 0; j < GRID_HEIGHT; j++) {
        printf("%c", grid[i * GRID_WIDTH + j]);
      }
      printf("\n");
    }
    printf("\n");
  }

  // Free the grid
  free(grid);

  return 0;
}