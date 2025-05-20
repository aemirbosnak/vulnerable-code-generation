//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

// Grid of cells
int grid[GRID_SIZE][GRID_SIZE];

// Function to initialize the grid
void init_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = 0;
    }
  }
}

// Function to print the grid
void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a cell is open
int is_open(int x, int y) {
  return grid[x][y] == 1;
}

// Function to open a cell
void open_cell(int x, int y) {
  grid[x][y] = 1;
}

// Function to check if a cell is percolated
int is_percolated(int x, int y) {
  // Check if the cell is open
  if (!is_open(x, y)) {
    return 0;
  }

  // Check if the cell is in the top row
  if (x == 0) {
    return 1;
  }

  // Check if the cell is connected to an open cell above it
  if (is_open(x - 1, y)) {
    return 1;
  }

  // Check if the cell is connected to an open cell to the left or right of it
  if (is_open(x, y - 1) || is_open(x, y + 1)) {
    return 1;
  }

  // The cell is not percolated
  return 0;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the grid
  init_grid();

  // Open a random number of cells
  for (int i = 0; i < GRID_SIZE * GRID_SIZE / 2; i++) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    open_cell(x, y);
  }

  // Print the grid
  print_grid();

  // Check if the grid is percolated
  int percolated = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_percolated(GRID_SIZE - 1, i)) {
      percolated = 1;
      break;
    }
  }

  // Print whether or not the grid is percolated
  if (percolated) {
    printf("The grid is percolated.\n");
  } else {
    printf("The grid is not percolated.\n");
  }

  return 0;
}