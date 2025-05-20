#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <time.h>

int main() {
  int **maze = NULL;
  int rows = 50;
  int cols = 50;

  maze = (int**)malloc(rows * sizeof(int*));
  for (int r = 0; r < rows; r++) {
    maze[r] = (int*)malloc(cols * sizeof(int));
  }

  // Generate maze logic
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      maze[r][c] = rand() % 2;
    }
  }

  // Free memory
  for (int r = 0; r < rows; r++) {
    free(maze[r]);
  }
  free(maze);

  return 0;
}
