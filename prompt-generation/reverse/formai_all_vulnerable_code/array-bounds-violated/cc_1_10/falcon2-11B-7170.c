//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze
int maze[5][5] = {
  {0, 1, 1, 1, 1},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1}
};

// Define the starting position
int startX = 2;
int startY = 3;

// Function to check if a position is valid
bool isValid(int x, int y) {
  if (x < 0 || x >= 5 || y < 0 || y >= 5) {
    return false;
  }
  return true;
}

// Function to print the maze
void printMaze() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

// Function to move the player
void move(int *x, int *y, bool direction) {
  if (direction == 0) {
    *x = *x - 1;
  } else if (direction == 1) {
    *x = *x + 1;
  } else if (direction == 2) {
    *y = *y - 1;
  } else if (direction == 3) {
    *y = *y + 1;
  }
}

// Function to play the game
void play() {
  int x = startX;
  int y = startY;
  bool exit = false;

  while (!exit) {
    printf("Current position: (%d, %d)\n", x, y);
    printf("Enter direction (0-3): ");
    int direction;
    scanf("%d", &direction);

    if (direction == 0) {
      move(&x, &y, 0);
    } else if (direction == 1) {
      move(&x, &y, 1);
    } else if (direction == 2) {
      move(&x, &y, 2);
    } else if (direction == 3) {
      move(&x, &y, 3);
    }

    if (maze[x][y] == 0) {
      exit = true;
    }
  }
}

int main() {
  // Print the maze
  printMaze();

  // Play the game
  play();

  return 0;
}