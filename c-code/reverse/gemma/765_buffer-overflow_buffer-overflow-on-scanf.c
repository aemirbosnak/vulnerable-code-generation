#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int grid[10][10] = {0};
  int x, y, start_x, start_y, dest_x, dest_y;

  scanf("Enter the number of rows: ", &x);
  scanf("Enter the number of columns: ", &y);

  printf("Enter the starting coordinates: ");
  scanf("(%d, %d)", &start_x, &start_y);

  printf("Enter the destination coordinates: ");
  scanf("(%d, %d)", &dest_x, &dest_y);

  // Implement pathfinding algorithm with nested loops and conditional branching
  for (int row = 0; row < x; row++) {
    for (int col = 0; col < y; col++) {
      if (grid[row][col] == 1) {
        if (row == dest_x && col == dest_y) {
          printf("Path found!");
          return 0;
        }
      }
    }
  }

  printf("No path found.");
  return 0;
}
