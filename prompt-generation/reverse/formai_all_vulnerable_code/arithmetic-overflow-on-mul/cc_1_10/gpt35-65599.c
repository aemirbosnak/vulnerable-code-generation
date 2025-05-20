//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
/*

The following C program simulates percolation in a decentralized way.
The program creates a 2D percolation grid of size n x n.
Each grid cell is either filled (1) or empty (0).
The system percolates when there is a connected path of filled cells from the top row to the bottom row.
The program uses union-find algorithm to connect grid cells in a decentralized way.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GRID_SIZE 100

int n;  // size of grid
int grid[MAX_GRID_SIZE][MAX_GRID_SIZE];  // 2D grid for percolation
int parent[MAX_GRID_SIZE * MAX_GRID_SIZE];
int size[MAX_GRID_SIZE * MAX_GRID_SIZE];
int top_root, bottom_root;  // virtual roots for top and bottom rows
int num_open_sites = 0;  // number of open sites in grid

// function to initialize the grid and parent array
// all cells are set to 0, and all parent index are set to -1
void initialize() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      grid[i][j] = 0;
    }
  }
  for (i = 0; i < n * n; i++) {
    parent[i] = -1;
    size[i] = 1;
  }
  top_root = n * n;
  bottom_root = n * n + 1;
}

// function to print the grid
void print_grid() {
  int i, j;
  printf("Grid:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// function to get the index of a cell in the 1D parent array
int get_index(int row, int col) {
  return row * n + col;
}

// function to check if a given cell is within the grid boundaries
int is_valid_cell(int row, int col) {
  if (row < 0 || row >= n || col < 0 || col >= n) {
    return 0;
  }
  return 1;
}

// function to connect two cells in the union-find structure
void connect_cells(int row1, int col1, int row2, int col2) {
  int index1 = get_index(row1, col1);
  int index2 = get_index(row2, col2);
  while (parent[index1] != -1) {
    index1 = parent[index1];
  }
  while (parent[index2] != -1) {
    index2 = parent[index2];
  }
  if (index1 != index2) {
    if (size[index1] >= size[index2]) {
      parent[index2] = index1;
      size[index1] += size[index2];
    } else {
      parent[index1] = index2;
      size[index2] += size[index1];
    }
  }
}

// function to check if two cells are connected
int is_connected(int row1, int col1, int row2, int col2) {
  int index1 = get_index(row1, col1);
  int index2 = get_index(row2, col2);
  while (parent[index1] != -1) {
    index1 = parent[index1];
  }
  while (parent[index2] != -1) {
    index2 = parent[index2];
  }
  if (index1 == index2) {
    return 1;
  }
  return 0;
}

// function to open a cell in the grid
void open_cell(int row, int col) {
  if (grid[row][col] == 0) {
    grid[row][col] = 1;
    num_open_sites++;
    int index = get_index(row, col);
    if (row == 0) {
      connect_cells(row, col, n, n);
    }
    if (row == n - 1) {
      connect_cells(row, col, n + 1, n + 1);
    }
    if (is_valid_cell(row - 1, col) && grid[row - 1][col] == 1) {
      connect_cells(row, col, row - 1, col);
    }
    if (is_valid_cell(row, col - 1) && grid[row][col - 1] == 1) {
      connect_cells(row, col, row, col - 1);
    }
    if (is_valid_cell(row, col + 1) && grid[row][col + 1] == 1) {
      connect_cells(row, col, row, col + 1);
    }
    if (is_valid_cell(row + 1, col) && grid[row + 1][col] == 1) {
      connect_cells(row, col, row + 1, col);
    }
  }
}

// function to check if the system percolates
int does_percolate() {
  return is_connected(n, n, n + 1, n + 1);
}

int main() {
  srand(time(NULL));
  printf("Enter the size of grid (maximum %d): ", MAX_GRID_SIZE);
  scanf("%d", &n);
  if (n > MAX_GRID_SIZE) {
    printf("Invalid grid size!\n");
    return 1;
  }
  initialize();
  while (!does_percolate()) {
    int row = rand() % n;
    int col = rand() % n;
    open_cell(row, col);
  }
  printf("Percolation achieved!\n");
  printf("Number of open sites: %d\n", num_open_sites);
  printf("Percolation grid:\n");
  print_grid();
  return 0;
}