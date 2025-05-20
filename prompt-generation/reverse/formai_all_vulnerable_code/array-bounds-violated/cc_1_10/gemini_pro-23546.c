//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// The maze
char maze[MAZE_SIZE][MAZE_SIZE] = {
  { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
  { '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
  { '1', '0', '1', '1', '1', '1', '0', '1', '0', '1' },
  { '1', '0', '1', '0', '0', '0', '0', '1', '0', '1' },
  { '1', '0', '1', '0', '1', '1', '0', '1', '0', '1' },
  { '1', '0', '1', '0', '1', '0', '0', '1', '0', '1' },
  { '1', '0', '1', '0', '1', '0', '1', '1', '0', '1' },
  { '1', '0', '1', '0', '1', '0', '0', '0', '0', '1' },
  { '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
  { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' }
};

// The path
int path[MAZE_SIZE][MAZE_SIZE];

// The visited array
int visited[MAZE_SIZE][MAZE_SIZE];

// Find the path through the maze
int find_path(int x, int y) {
  // Check if we have reached the end
  if (x == END_X && y == END_Y) {
    return 1;
  }

  // Check if we have visited this cell
  if (visited[x][y] == 1) {
    return 0;
  }

  // Mark this cell as visited
  visited[x][y] = 1;

  // Try all possible moves
  if (maze[x][y+1] == '0' && find_path(x, y+1)) {
    path[x][y] = 1;
    return 1;
  }
  if (maze[x+1][y] == '0' && find_path(x+1, y)) {
    path[x][y] = 1;
    return 1;
  }
  if (maze[x][y-1] == '0' && find_path(x, y-1)) {
    path[x][y] = 1;
    return 1;
  }
  if (maze[x-1][y] == '0' && find_path(x-1, y)) {
    path[x][y] = 1;
    return 1;
  }

  // No path found
  return 0;
}

// Print the maze
void print_maze() {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

// Print the path
void print_path() {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      if (path[i][j] == 1) {
        printf("%c", '*');
      } else {
        printf("%c", ' ');
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Find the path
  if (find_path(START_X, START_Y)) {
    // Print the maze
    printf("The maze:\n");
    print_maze();

    // Print the path
    printf("The path:\n");
    print_path();
  } else {
    printf("No path found.\n");
  }

  return 0;
}