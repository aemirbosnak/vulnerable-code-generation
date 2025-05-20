#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int **maze = NULL;
  int x, y;

  // Allocate memory for the maze
  maze = malloc(50 * 50 * sizeof(int));
  if (maze == NULL) {
    return 1;
  }

  // Initialize the maze
  for (x = 0; x < 50; x++) {
    for (y = 0; y < 50; y++) {
      maze[x][y] = 0;
    }
  }

  // Randomly place walls
  for (x = 0; x < 50; x++) {
    for (y = 0; y < 50; y++) {
      if (rand() % 20 == 0) {
        maze[x][y] = 1;
      }
    }
  }

  // Display the maze
  for (x = 0; x < 50; x++) {
    for (y = 0; y < 50; y++) {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }

  // Deallocate memory for the maze
  free(maze);

  return 0;
}
