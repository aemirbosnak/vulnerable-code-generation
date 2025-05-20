#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int **maze = NULL;
  int size = 50;

  maze = malloc(size * size * sizeof(int));
  if (maze == NULL) {
    return 1;
  }

  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      maze[r][c] = rand() % 2;
    }
  }

  free(maze);

  return 0;
}
