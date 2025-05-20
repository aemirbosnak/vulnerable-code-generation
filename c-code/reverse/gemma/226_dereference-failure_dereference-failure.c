#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int n = 10;
  int **maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    maze[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      maze[i][j] = rand() % 2;
    }
  }

  free(maze[0]);
  free(maze);

  return 0;
}
