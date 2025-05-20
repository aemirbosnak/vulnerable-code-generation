#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int **maze = NULL;
  int x = 50, y = 50;

  maze = (int**)malloc(x * y * sizeof(int));
  if (maze == NULL) {
    return 1;
  }

  // Allocate memory for the maze elements
  maze[0] = (int*)malloc(x * y * sizeof(int));
  if (maze[0] == NULL) {
    return 1;
  }

  // Fill the maze with random numbers
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      maze[i][j] = rand() % 2;
    }
  }

  // Free the memory allocated for the maze elements
  free(maze[0]);
  free(maze);

  return 0;
}
