//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Maze representation
int maze[MAX_SIZE][MAX_SIZE];

// Directions
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// Stack for DFS
int stack_x[MAX_SIZE * MAX_SIZE];
int stack_y[MAX_SIZE * MAX_SIZE];
int stack_top = -1;

// Function to generate a random maze
void generate_maze(int size) {
  // Initialize maze
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      maze[i][j] = 1;  // Wall
    }
  }

  // Set start and end points
  maze[0][0] = 0;  // Start
  maze[size - 1][size - 1] = 0;  // End

  // Randomly visit cells and carve paths
  int x = 0, y = 0;
  int visited_cells = 1;
  while (visited_cells < size * size) {
    // Get a random direction
    int dir = rand() % 4;

    // Check if the cell in that direction is a wall
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 0 && nx < size && ny >= 0 && ny < size && maze[nx][ny] == 1) {
      // Carve a path in that direction
      maze[nx][ny] = 0;
      maze[x + dx[dir] / 2][y + dy[dir] / 2] = 0;  // Remove the wall between cells

      // Push the current cell on the stack
      stack_x[++stack_top] = x;
      stack_y[stack_top] = y;

      // Move to the new cell
      x = nx;
      y = ny;

      visited_cells++;
    } else {
      // If the cell is not a wall, pop the current cell from the stack and move back
      if (stack_top >= 0) {
        x = stack_x[stack_top--];
        y = stack_y[stack_top--];
      }
    }
  }
}

// Function to print the maze
void print_maze(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (maze[i][j] == 1) {
        printf("██");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

// Function to find the shortest path from start to end using DFS
int find_shortest_path(int size, int start_x, int start_y, int end_x, int end_y) {
  // Initialize distance array
  int distance[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      distance[i][j] = -1;
    }
  }

  // Set distance of start cell to 0
  distance[start_x][start_y] = 0;

  // Stack for DFS
  int stack_x[MAX_SIZE * MAX_SIZE];
  int stack_y[MAX_SIZE * MAX_SIZE];
  int stack_top = -1;

  // Push the start cell on the stack
  stack_x[++stack_top] = start_x;
  stack_y[stack_top] = start_y;

  // While the stack is not empty
  while (stack_top >= 0) {
    // Pop the current cell from the stack
    int x = stack_x[stack_top--];
    int y = stack_y[stack_top--];

    // If the current cell is the end cell, return the distance
    if (x == end_x && y == end_y) {
      return distance[x][y];
    }

    // For each neighbor of the current cell
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // If the neighbor is a valid cell and has not been visited
      if (nx >= 0 && nx < size && ny >= 0 && ny < size && distance[nx][ny] == -1) {
        // Push the neighbor on the stack
        stack_x[++stack_top] = nx;
        stack_y[stack_top] = ny;

        // Set the distance of the neighbor to the distance of the current cell plus 1
        distance[nx][ny] = distance[x][y] + 1;
      }
    }
  }

  // If the end cell is not reachable, return -1
  return -1;
}

int main() {
  // Seed the random number generator
  srand(time(0));

  // Generate a maze of size 10
  generate_maze(10);

  // Print the maze
  print_maze(10);

  // Find the shortest path from start to end
  int start_x = 0, start_y = 0;
  int end_x = 9, end_y = 9;
  int shortest_path = find_shortest_path(10, start_x, start_y, end_x, end_y);

  // Print the shortest path
  if (shortest_path != -1) {
    printf("Shortest path: %d\n", shortest_path);
  } else {
    printf("End cell is not reachable from start cell\n");
  }

  return 0;
}