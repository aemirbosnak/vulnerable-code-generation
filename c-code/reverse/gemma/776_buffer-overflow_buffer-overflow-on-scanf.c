#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char board[36] = {0};
  int x, y;

  printf("Enter coordinates:");
  scanf("%d %d", &x, &y);

  if (x > 5 || x < 1 || y > 5 || y < 1) {
    printf("Invalid coordinates.\n");
  } else {
    board[x + 6 * (y - 1)] = 'X';
    printf("Move accepted.\n");
  }

  return 0;
}
