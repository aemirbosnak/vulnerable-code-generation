//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: configurable
/*
 * game_of_life.c
 *
 * A configurable Game of Life example program.
 *
 * Usage: game_of_life [size] [seed]
 *
 * The size argument specifies the size of the grid, and the seed
 * argument specifies the random seed for the grid initialization.
 *
 * The game is played by printing the grid to the console, and then
 * stepping through each generation, applying the rules of the game
 * to each cell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the grid
#define GRID_SIZE 100

// Define the number of generations to play
#define NUM_GENERATIONS 100

// Define the rules of the game
#define LIVE 1
#define DEAD 0

int grid[GRID_SIZE][GRID_SIZE];

// Initialize the grid with a random seed
void init_grid(int seed) {
  srand(seed);
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

// Print the grid to the console
void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Apply the rules of the game to each cell
void step_generation() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      int live_neighbors = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (i + k < 0 || i + k >= GRID_SIZE || j + l < 0 || j + l >= GRID_SIZE) {
            continue;
          }
          if (grid[i + k][j + l] == LIVE) {
            live_neighbors++;
          }
        }
      }
      if (grid[i][j] == LIVE) {
        if (live_neighbors < 2 || live_neighbors > 3) {
          grid[i][j] = DEAD;
        }
      } else {
        if (live_neighbors == 3) {
          grid[i][j] = LIVE;
        }
      }
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: game_of_life [size] [seed]\n");
    return 1;
  }
  int size = atoi(argv[1]);
  int seed = atoi(argv[2]);
  init_grid(seed);
  for (int i = 0; i < NUM_GENERATIONS; i++) {
    print_grid();
    step_generation();
  }
  return 0;
}