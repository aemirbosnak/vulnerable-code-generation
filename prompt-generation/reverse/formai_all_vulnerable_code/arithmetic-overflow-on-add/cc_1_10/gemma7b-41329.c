//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void createMaze(int **maze, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      maze[i][j] = 0;
    }
  }
  maze[n / 2][n / 2] = 1;
}

int main() {
  int n;
  printf("Enter the number of rows and columns: ");
  scanf("%d", &n);

  int **maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    maze[i] = (int *)malloc(n * sizeof(int));
  }

  createMaze(maze, n);

  int x, y;
  printf("Enter the starting position (x, y): ");
  scanf("%d %d", &x, &y);

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  int found = 0;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (maze[x][y] == 1) {
        found = 1;
        break;
      } else {
        x += dx[i];
        y += dy[j];
      }
    }
  }

  if (found) {
    printf("The goal has been found!");
  } else {
    printf("The goal has not been found.");
  }

  return 0;
}