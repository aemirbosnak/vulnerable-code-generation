#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int grid[10][10];
  int i, j, x, y;

  scanf("Enter the number of rows: ", &i);
  scanf("Enter the number of columns: ", &j);

  if (i > 10 || j > 10) {
    printf("Error: Dimensions exceed the grid size.\n");
    return 1;
  }

  printf("Enter the elements of the grid: ");
  for (x = 0; x < i; x++) {
    for (y = 0; y < j; y++) {
      scanf("%d ", &grid[x][y]);
    }
  }

  return 0;
}
