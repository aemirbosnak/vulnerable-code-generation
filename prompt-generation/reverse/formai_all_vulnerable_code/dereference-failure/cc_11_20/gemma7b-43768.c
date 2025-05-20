//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define START 2
#define END 3

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Create the maze
  int **maze = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
  for (int x = 0; x < WIDTH; x++) {
    maze[x] = (int *)malloc(HEIGHT * sizeof(int));
    for (int y = 0; y < HEIGHT; y++) {
      maze[x][y] = EMPTY;
    }
  }

  // Create the walls
  for (int x = 0; x < WIDTH; x++) {
    maze[x][0] = WALL;
    maze[x][HEIGHT - 1] = WALL;
  }

  for (int y = 0; y < HEIGHT; y++) {
    maze[0][y] = WALL;
    maze[WIDTH - 1][y] = WALL;
  }

  // Place the start and end points
  maze[0][0] = START;
  maze[WIDTH - 1][HEIGHT - 1] = END;

  // Draw the maze
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      switch (maze[x][y]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case START:
          printf("S");
          break;
        case END:
          printf("E");
          break;
      }
    }
    printf("\n");
  }

  // Free the memory
  for (int x = 0; x < WIDTH; x++) {
    free(maze[x]);
  }
  free(maze);

  return 0;
}