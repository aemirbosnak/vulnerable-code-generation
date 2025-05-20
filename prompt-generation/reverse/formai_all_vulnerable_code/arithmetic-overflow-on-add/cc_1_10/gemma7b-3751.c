//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
  int n, m, i, j, x, y, a[MAX][MAX], visited[MAX][MAX], route[MAX][MAX];
  char maze[MAX][MAX];

  printf("Enter the number of rows and columns of the maze:");
  scanf("%d %d", &n, &m);

  printf("Enter the maze:");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%c", &maze[i][j]);
    }
  }

  printf("Enter the starting position of the robot:");
  scanf("%d %d", &x, &y);

  printf("Enter the goal position of the robot:");
  scanf("%d %d", &a[x][y], &a[x][y]);

  // Calculate the route
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      visited[i][j] = 0;
      route[i][j] = -1;
    }
  }

  visited[x][y] = 1;
  route[x][y] = 0;

  while (route[a[x][y]][a[x][y]] != -1) {
    x = a[x][y] - 1;
    y = a[x][y];
    visited[x][y] = 1;
    route[x][y] = route[x][y] + 1;
  }

  // Print the route
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", route[i][j]);
    }
    printf("\n");
  }

  return 0;
}