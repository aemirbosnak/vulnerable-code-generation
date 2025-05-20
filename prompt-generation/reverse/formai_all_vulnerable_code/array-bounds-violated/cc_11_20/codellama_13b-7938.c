//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
// Maze Route Finder Program

#include <stdio.h>

int main() {
  int maze[5][5] = {
    {1, 1, 0, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 0},
    {1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1}
  };

  int start[2] = {0, 0};
  int end[2] = {4, 4};

  int visited[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  int path[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  int x = start[0];
  int y = start[1];
  int count = 0;

  while (x != end[0] || y != end[1]) {
    if (maze[x][y] == 1) {
      visited[x][y] = 1;
      path[x][y] = count;
      count++;
      if (x == end[0] && y == end[1]) {
        break;
      }
      if (maze[x+1][y] == 1 && visited[x+1][y] == 0) {
        x++;
      } else if (maze[x][y+1] == 1 && visited[x][y+1] == 0) {
        y++;
      } else if (maze[x-1][y] == 1 && visited[x-1][y] == 0) {
        x--;
      } else if (maze[x][y-1] == 1 && visited[x][y-1] == 0) {
        y--;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", path[i][j]);
    }
    printf("\n");
  }

  return 0;
}