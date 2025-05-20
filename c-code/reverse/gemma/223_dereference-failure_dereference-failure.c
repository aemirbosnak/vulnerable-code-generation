#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int **maze = NULL;
  int rows = 50, cols = 50;
  maze = (int**)malloc(rows * cols * sizeof(int));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      maze[r][c] = rand() % 2;
    }
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", maze[r][c]);
    }
    printf("\n");
  }
  free(maze);
  return 0;
}
