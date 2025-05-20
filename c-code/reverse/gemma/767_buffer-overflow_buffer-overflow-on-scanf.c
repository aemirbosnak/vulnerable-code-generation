#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int **grid = NULL;
  int rows, cols;
  scanf(" %d %d ", &rows, &cols);

  grid = (int **)malloc(rows * sizeof(int *));
  for (int r = 0; r < rows; r++) {
    grid[r] = (int *)malloc(cols * sizeof(int));
  }

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      scanf(" %d ", &grid[r][c]);
    }
  }

  int start_row, start_col, end_row, end_col;
  scanf(" %d %d %d %d ", &start_row, &start_col, &end_row, &end_col);

  int path_found = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == 0 && r == start_row && c == start_col) {
        path_found = 1;
        grid[r][c] = 2;
      } else if (path_found && grid[r][c] == 0 && r == end_row && c == end_col) {
        path_found = 1;
        grid[r][c] = 2;
      }
    }
  }

  if (path_found) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  for (int r = 0; r < rows; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}
