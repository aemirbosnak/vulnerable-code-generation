#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char grid[25] = {'#'};
  grid[0] = 'T';
  int x = 0, y = 0;

  printf("Enter move (w/a/s/d): ");
  char move = '\0';
  scanf("%c", &move);

  switch (move) {
    case 'w':
      if (y > 0) {
        y--;
      }
      break;
    case 'a':
      if (x > 0) {
        x--;
      }
      break;
    case 's':
      if (y < 4) {
        y++;
      }
      break;
    case 'd':
      if (x < 4) {
        x++;
      }
      break;
  }

  if (grid[x * 5 + y] == 'T') {
    printf("You found the treasure!\n");
  } else {
    printf("Error: invalid move.\n");
  }

  return 0;
}
