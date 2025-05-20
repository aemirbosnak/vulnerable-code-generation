//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main() {
  int width = rand() % MAX_WIDTH + 1;
  int height = rand() % MAX_HEIGHT + 1;

  // Allocate memory for the maze
  int **maze = malloc(height * sizeof(int *));
  for (int i = 0; i < height; i++) {
    maze[i] = malloc(width * sizeof(int));
  }

  // Initialize the maze
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze[i][j] = 0;
    }
  }

  // Create the maze
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
        maze[i][j] = 1;
      } else {
        maze[i][j] = rand() % 2;
      }
    }
  }

  // Print the maze
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < height; i++) {
    free(maze[i]);
  }
  free(maze);

  return 0;
}