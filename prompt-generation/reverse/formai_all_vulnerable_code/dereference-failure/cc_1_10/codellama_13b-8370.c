//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
// procedural_generated_maze.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the size of the maze
#define MAZE_SIZE 20

// define the maze structure
typedef struct {
  int** cells;
  int size;
} Maze;

// function to initialize the maze
Maze* init_maze() {
  // allocate memory for the maze
  Maze* maze = (Maze*) malloc(sizeof(Maze));
  // set the size of the maze
  maze->size = MAZE_SIZE;
  // allocate memory for the cells
  maze->cells = (int**) malloc(sizeof(int*) * maze->size);
  for (int i = 0; i < maze->size; i++) {
    maze->cells[i] = (int*) malloc(sizeof(int) * maze->size);
  }
  // initialize the cells to 0
  for (int i = 0; i < maze->size; i++) {
    for (int j = 0; j < maze->size; j++) {
      maze->cells[i][j] = 0;
    }
  }
  return maze;
}

// function to generate the maze
void generate_maze(Maze* maze) {
  // set the starting cell
  int x = 0;
  int y = 0;
  // initialize the stack
  int stack[maze->size * maze->size];
  int stack_size = 0;
  // add the starting cell to the stack
  stack[stack_size++] = y * maze->size + x;
  // loop until the stack is empty
  while (stack_size > 0) {
    // pop a cell from the stack
    int cell = stack[--stack_size];
    // generate a random number
    int r = rand() % 4;
    // determine the next cell to visit
    int next_x, next_y;
    switch (r) {
      case 0:
        next_x = x - 1;
        next_y = y;
        break;
      case 1:
        next_x = x + 1;
        next_y = y;
        break;
      case 2:
        next_x = x;
        next_y = y - 1;
        break;
      case 3:
        next_x = x;
        next_y = y + 1;
        break;
    }
    // check if the next cell is valid
    if (next_x >= 0 && next_x < maze->size && next_y >= 0 && next_y < maze->size && maze->cells[next_y][next_x] == 0) {
      // set the current cell to visited
      maze->cells[y][x] = 1;
      // set the next cell to visited
      maze->cells[next_y][next_x] = 1;
      // add the next cell to the stack
      stack[stack_size++] = next_y * maze->size + next_x;
    }
    // update the current cell
    x = next_x;
    y = next_y;
  }
}

// function to print the maze
void print_maze(Maze* maze) {
  for (int i = 0; i < maze->size; i++) {
    for (int j = 0; j < maze->size; j++) {
      if (maze->cells[i][j] == 1) {
        printf("  ");
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }
}

int main() {
  // set the random seed
  srand(time(NULL));
  // create a new maze
  Maze* maze = init_maze();
  // generate the maze
  generate_maze(maze);
  // print the maze
  print_maze(maze);
  // free the memory
  for (int i = 0; i < maze->size; i++) {
    free(maze->cells[i]);
  }
  free(maze->cells);
  free(maze);
  return 0;
}