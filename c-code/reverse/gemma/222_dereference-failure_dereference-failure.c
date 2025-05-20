#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <time.h>

int main() {
  int **maze = NULL;
  int rows, cols;

  // Generate maze size
  rows = rand() % 10 + 10;
  cols = rand() % 10 + 10;

  // Allocate memory for maze
  maze = (int**)malloc(rows * sizeof(int*));
  maze[0] = (int*)malloc(cols * sizeof(int));

  // Generate maze
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      maze[r][c] = rand() % 2;
    }
  }

  // Print maze
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", maze[r][c]);
    }
    printf("\n");
  }

  return 0;
}
