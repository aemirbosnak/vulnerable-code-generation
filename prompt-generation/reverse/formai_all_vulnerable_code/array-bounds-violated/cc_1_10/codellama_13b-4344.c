//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
// Romeo and Juliet Game of Life

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

// Cell struct
typedef struct {
  int x;
  int y;
  int alive;
} cell_t;

// Grid struct
typedef struct {
  cell_t grid[WIDTH][HEIGHT];
  int generation;
} grid_t;

// Print the grid
void print_grid(grid_t *grid) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (grid->grid[i][j].alive) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Check if a cell is alive
int check_cell(grid_t *grid, int x, int y) {
  if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
    return 0;
  }
  return grid->grid[x][y].alive;
}

// Count the number of alive cells around a cell
int count_alive_cells(grid_t *grid, int x, int y) {
  int alive_cells = 0;
  alive_cells += check_cell(grid, x - 1, y - 1);
  alive_cells += check_cell(grid, x - 1, y);
  alive_cells += check_cell(grid, x - 1, y + 1);
  alive_cells += check_cell(grid, x, y - 1);
  alive_cells += check_cell(grid, x, y + 1);
  alive_cells += check_cell(grid, x + 1, y - 1);
  alive_cells += check_cell(grid, x + 1, y);
  alive_cells += check_cell(grid, x + 1, y + 1);
  return alive_cells;
}

// Apply the rules of the Game of Life to a cell
void apply_rules(grid_t *grid, int x, int y) {
  int alive_cells = count_alive_cells(grid, x, y);
  if (grid->grid[x][y].alive) {
    if (alive_cells < 2 || alive_cells > 3) {
      grid->grid[x][y].alive = 0;
    }
  } else {
    if (alive_cells == 3) {
      grid->grid[x][y].alive = 1;
    }
  }
}

// Run the Game of Life simulation
void run_game_of_life(grid_t *grid) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      apply_rules(grid, j, i);
    }
  }
  grid->generation++;
}

int main() {
  grid_t grid;
  grid.generation = 0;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid.grid[i][j].x = j;
      grid.grid[i][j].y = i;
      grid.grid[i][j].alive = rand() % 2;
    }
  }
  while (1) {
    print_grid(&grid);
    run_game_of_life(&grid);
    sleep(1);
  }
  return 0;
}