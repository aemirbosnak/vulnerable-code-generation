#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int **maze = (int**)malloc(50 * sizeof(int*));
  for (int i = 0; i < 50; i++) {
    maze[i] = (int*)malloc(50 * sizeof(int));
  }

  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      maze[i][j] = rand() % 2;
    }
  }

  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}
