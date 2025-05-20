//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
  char maze[MAX_SIZE][MAX_SIZE];
  int start_x, start_y, end_x, end_y;
  int i, j;
  int found = 0;

  // Get the maze from the user.
  printf("Enter the maze:\n");
  for (i = 0; i < MAX_SIZE; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      scanf(" %c", &maze[i][j]);
    }
  }

  // Get the starting and ending points.
  printf("Enter the starting point (x, y): ");
  scanf(" %d %d", &start_x, &start_y);
  printf("Enter the ending point (x, y): ");
  scanf(" %d %d", &end_x, &end_y);

  // Find the path from the starting point to the ending point.
  i = start_x;
  j = start_y;
  while (!found) {
    // Check if we have reached the ending point.
    if (i == end_x && j == end_y) {
      found = 1;
      break;
    }

    // Check if we can move north.
    if (maze[i - 1][j] != '#') {
      i--;
    }
    // Check if we can move east.
    else if (maze[i][j + 1] != '#') {
      j++;
    }
    // Check if we can move south.
    else if (maze[i + 1][j] != '#') {
      i++;
    }
    // Check if we can move west.
    else if (maze[i][j - 1] != '#') {
      j--;
    }
    // If we can't move in any direction, we're stuck.
    else {
      break;
    }
  }

  // Print the path from the starting point to the ending point.
  if (found) {
    printf("The path from the starting point to the ending point is:\n");
    for (i = start_x; i <= end_x; i++) {
      for (j = start_y; j <= end_y; j++) {
        printf("%c", maze[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No path from the starting point to the ending point exists.\n");
  }

  return 0;
}