//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the maze
#define MAZE_SIZE 10

// Define the different types of cells in the maze
#define CELL_EMPTY 0
#define CELL_WALL 1
#define CELL_VISITED 2

// Define the different directions that the algorithm can move in
#define DIR_NORTH 0
#define DIR_EAST 1
#define DIR_SOUTH 2
#define DIR_WEST 3

// Create a function to generate a new maze
void generate_maze(int maze[MAZE_SIZE][MAZE_SIZE]) {
  // Initialize the maze to all walls
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze[i][j] = CELL_WALL;
    }
  }

  // Set the starting cell to the top-left corner
  int current_cell_x = 0;
  int current_cell_y = 0;

  // Create a stack to keep track of the cells that have been visited
  int stack[MAZE_SIZE * MAZE_SIZE][2];
  int stack_top = 0;

  // While there are still cells to visit
  while (stack_top > 0 || current_cell_x != MAZE_SIZE - 1 || current_cell_y != MAZE_SIZE - 1) {
    // If the current cell has not been visited
    if (maze[current_cell_x][current_cell_y] == CELL_WALL) {
      // Mark the current cell as visited
      maze[current_cell_x][current_cell_y] = CELL_VISITED;

      // Push the current cell onto the stack
      stack[stack_top][0] = current_cell_x;
      stack[stack_top][1] = current_cell_y;
      stack_top++;

      // Choose a random direction to move in
      int direction = rand() % 4;

      // Move in the chosen direction
      switch (direction) {
        case DIR_NORTH:
          current_cell_y--;
          break;
        case DIR_EAST:
          current_cell_x++;
          break;
        case DIR_SOUTH:
          current_cell_y++;
          break;
        case DIR_WEST:
          current_cell_x--;
          break;
      }
    } else {
      // If the current cell has been visited
      stack_top--;

      // Pop the current cell from the stack
      current_cell_x = stack[stack_top][0];
      current_cell_y = stack[stack_top][1];
    }
  }
}

// Create a function to print the maze
void print_maze(int maze[MAZE_SIZE][MAZE_SIZE]) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      switch (maze[i][j]) {
        case CELL_EMPTY:
          printf(" ");
          break;
        case CELL_WALL:
          printf("#");
          break;
        case CELL_VISITED:
          printf(".");
          break;
      }
    }
    printf("\n");
  }
}

// Create a main function to generate and print the maze
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Create a new maze
  int maze[MAZE_SIZE][MAZE_SIZE];
  generate_maze(maze);

  // Print the maze
  print_maze(maze);

  return 0;
}