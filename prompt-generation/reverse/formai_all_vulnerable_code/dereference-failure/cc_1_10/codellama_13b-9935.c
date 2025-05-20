//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
// percolation_simulator.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define PERCOLATION_THRESHOLD 0.5

// struct to represent a grid
typedef struct {
  int n; // number of rows
  int m; // number of columns
  int **data; // array of pointers to arrays of integers
} Grid;

// function to create a new grid
Grid *create_grid(int n, int m) {
  Grid *grid = malloc(sizeof(Grid));
  grid->n = n;
  grid->m = m;
  grid->data = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    grid->data[i] = malloc(m * sizeof(int));
  }
  return grid;
}

// function to delete a grid
void delete_grid(Grid *grid) {
  for (int i = 0; i < grid->n; i++) {
    free(grid->data[i]);
  }
  free(grid->data);
  free(grid);
}

// function to initialize a grid
void init_grid(Grid *grid) {
  for (int i = 0; i < grid->n; i++) {
    for (int j = 0; j < grid->m; j++) {
      grid->data[i][j] = 0;
    }
  }
}

// function to print a grid
void print_grid(Grid *grid) {
  for (int i = 0; i < grid->n; i++) {
    for (int j = 0; j < grid->m; j++) {
      printf("%d ", grid->data[i][j]);
    }
    printf("\n");
  }
}

// function to check if a site is open
int is_open(Grid *grid, int i, int j) {
  return grid->data[i][j] == 0;
}

// function to open a site
void open_site(Grid *grid, int i, int j) {
  grid->data[i][j] = 1;
}

// function to check if a site is connected to the top
int is_connected_to_top(Grid *grid, int i, int j) {
  return i == 0 || grid->data[i - 1][j] == 1;
}

// function to check if a site is connected to the bottom
int is_connected_to_bottom(Grid *grid, int i, int j) {
  return i == grid->n - 1 || grid->data[i + 1][j] == 1;
}

// function to check if a site is connected to the left
int is_connected_to_left(Grid *grid, int i, int j) {
  return j == 0 || grid->data[i][j - 1] == 1;
}

// function to check if a site is connected to the right
int is_connected_to_right(Grid *grid, int i, int j) {
  return j == grid->m - 1 || grid->data[i][j + 1] == 1;
}

// function to check if a site is connected to the top, bottom, left, or right
int is_connected(Grid *grid, int i, int j) {
  return is_connected_to_top(grid, i, j) ||
         is_connected_to_bottom(grid, i, j) ||
         is_connected_to_left(grid, i, j) ||
         is_connected_to_right(grid, i, j);
}

// function to check if a site is percolated
int is_percolated(Grid *grid, int i, int j) {
  return is_connected_to_top(grid, i, j) &&
         is_connected_to_bottom(grid, i, j) &&
         is_connected_to_left(grid, i, j) &&
         is_connected_to_right(grid, i, j);
}

// function to simulate a percolation event
void percolate(Grid *grid) {
  // select a random site
  int i = rand() % grid->n;
  int j = rand() % grid->m;
  // check if the site is open
  if (is_open(grid, i, j)) {
    // open the site
    open_site(grid, i, j);
    // check if the site is percolated
    if (is_percolated(grid, i, j)) {
      // print the grid
      print_grid(grid);
      // delete the grid
      delete_grid(grid);
      // exit the program
      exit(0);
    }
  }
}

int main() {
  // create a grid
  Grid *grid = create_grid(N, N);
  // initialize the grid
  init_grid(grid);
  // simulate percolation events
  while (1) {
    percolate(grid);
  }
  // delete the grid
  delete_grid(grid);
  return 0;
}