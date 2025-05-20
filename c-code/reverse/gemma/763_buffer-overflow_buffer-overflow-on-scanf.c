#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int grid[10][10], x1, y1, x2, y2, i, j, obstacle = -1;
  scanf("Enter the number of obstacles: ", &obstacle);
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      grid[i][j] = 0;
    }
  }
  for (i = 0; i < obstacle; i++) {
    scanf("Enter the coordinates of an obstacle: ", &x1, &y1);
    grid[x1][y1] = obstacle;
  }
  scanf("Enter the coordinates of the starting point: ", &x1, &y1);
  scanf("Enter the coordinates of the destination point: ", &x2, &y2);
  if (grid[x2][y2] == obstacle) {
    printf("No path found.\n");
  } else {
    for (i = x1; i <= x2; i++) {
      for (j = y1; j <= y2; j++) {
        if (grid[i][j] == 0) {
          grid[i][j] = 1;
        }
      }
    }
    printf("Path found.\n");
  }
  return 0;
}
