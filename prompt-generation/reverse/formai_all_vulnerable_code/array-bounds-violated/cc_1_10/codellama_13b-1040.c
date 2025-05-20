//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 10

// Define the maze as a 2D array of characters
char maze[MAZE_HEIGHT][MAZE_WIDTH];

// Function to initialize the maze
void initializeMaze() {
  // Set all cells to walls
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      maze[i][j] = '#';
    }
  }
}

// Function to generate a random path
void generatePath() {
  // Set the starting cell
  int x = rand() % MAZE_WIDTH;
  int y = rand() % MAZE_HEIGHT;
  maze[y][x] = ' ';

  // Generate a random path
  while (x != MAZE_WIDTH - 1 && y != MAZE_HEIGHT - 1) {
    // Choose a random direction
    int direction = rand() % 4;

    // Move in the chosen direction
    if (direction == 0) {
      x++;
    } else if (direction == 1) {
      x--;
    } else if (direction == 2) {
      y++;
    } else {
      y--;
    }

    // Mark the new cell as a path
    maze[y][x] = ' ';
  }
}

// Function to display the maze
void displayMaze() {
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Initialize the maze
  initializeMaze();

  // Generate a random path
  generatePath();

  // Display the maze
  displayMaze();

  return 0;
}