//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>

#define MAX_SIZE 100

int maze[MAX_SIZE][MAX_SIZE];
int path[MAX_SIZE][MAX_SIZE];

int rows, cols, start_row, start_col, end_row, end_col;

void read_maze() {
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  printf("Enter number of columns: ");
  scanf("%d", &cols);

  printf("Enter maze (0 for empty cell, 1 for obstacles):\n");

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      scanf("%d", &maze[i][j]);
      path[i][j] = 0;
    }
  }

  printf("Enter starting row and column:\n");
  scanf("%d %d", &start_row, &start_col);

  printf("Enter ending row and column:\n");
  scanf("%d %d", &end_row, &end_col);
}

void print_maze() {
  printf("Maze:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int solve_maze(int row, int col) {
  if(row < 0 || row >= rows || col < 0 || col >= cols || maze[row][col] == 1 || path[row][col] == 1) {
    return 0;
  }

  if(row == end_row && col == end_col) {
    path[row][col] = 1;
    return 1;
  }

  path[row][col] = 1;

  if(solve_maze(row + 1, col) == 1) { // check down
    return 1;
  }

  if(solve_maze(row, col + 1) == 1) { // check right
    return 1;
  }

  if(solve_maze(row - 1, col) == 1) { // check up
    return 1;
  }

  if(solve_maze(row, col - 1) == 1) { // check left
    return 1;
  }

  path[row][col] = 0; // backtracking
  return 0;
}

void print_path() {
  printf("Path:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      printf("%d ", path[i][j]);
    }
    printf("\n");
  }
}

void print_route() {
  int curr_row = start_row;
  int curr_col = start_col;

  printf("Route:\n(%d,%d) -> ", curr_row, curr_col);

  while(curr_row != end_row || curr_col != end_col) {
    if(curr_row < rows - 1 && path[curr_row + 1][curr_col] == 1) { // check down
      curr_row++;
      printf("(%d,%d) -> ", curr_row, curr_col);
    }
    else if(curr_col < cols - 1 && path[curr_row][curr_col + 1] == 1) { // check right
      curr_col++;
      printf("(%d,%d) -> ", curr_row, curr_col);
    }
    else if(curr_row > 0 && path[curr_row - 1][curr_col] == 1) { // check up
      curr_row--;
      printf("(%d,%d) -> ", curr_row, curr_col);
    }
    else if(curr_col > 0 && path[curr_row][curr_col - 1] == 1) { // check left
      curr_col--;
      printf("(%d,%d) -> ", curr_row, curr_col);
    }
  }

  printf("(%d,%d)\n", end_row, end_col);
}

int main() {
  read_maze();
  print_maze();

  if(solve_maze(start_row, start_col)) {
    printf("Solution found!\n");
    print_path();
    print_route();
  }
  else {
    printf("No solution found.\n");
  }

  return 0;
}