//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_GENERATIONS 100
#define RULE_1 3
#define RULE_2 2

// Define the grid structure
struct grid {
  int cells[GRID_SIZE][GRID_SIZE];
};

// Define the cell structure
struct cell {
  int alive;
  int neighbors;
};

// Initialize the grid
void init_grid(struct grid* grid) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid->cells[i][j] = 0;
    }
  }
}

// Set the state of a cell
void set_cell(struct grid* grid, int x, int y, int state) {
  if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
    grid->cells[x][y] = state;
  }
}

// Get the state of a cell
int get_cell(struct grid* grid, int x, int y) {
  if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
    return grid->cells[x][y];
  }
  return 0;
}

// Update the state of a cell
void update_cell(struct grid* grid, int x, int y) {
  int alive = get_cell(grid, x, y);
  int neighbors = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;
      neighbors += get_cell(grid, x + i, y + j);
    }
  }
  if (alive) {
    if (neighbors < RULE_1 || neighbors > RULE_2) {
      set_cell(grid, x, y, 0);
    }
  } else {
    if (neighbors == 3) {
      set_cell(grid, x, y, 1);
    }
  }
}

// Update the state of the grid
void update_grid(struct grid* grid) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      update_cell(grid, i, j);
    }
  }
}

// Print the state of the grid
void print_grid(struct grid* grid) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", get_cell(grid, i, j));
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  struct grid* grid = malloc(sizeof(struct grid));
  init_grid(grid);
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      set_cell(grid, i, j, rand() % 2);
    }
  }
  for (int i = 0; i < NUM_GENERATIONS; i++) {
    print_grid(grid);
    update_grid(grid);
  }
  free(grid);
  return 0;
}