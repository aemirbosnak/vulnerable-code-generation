#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numDisks;
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);

  int moves = 0;
  moveDisks(numDisks, 1, 2, 3, &moves);

  printf("Number of moves: %d\n", moves);

  return 0;
}

void moveDisks(int numDisks, int src, int dest, int aux, int *moves) {
  *moves++;
  if (numDisks > 0) {
    moveDisks(numDisks - 1, src, aux, dest, moves);
    moveDisks(1, aux, dest, src, moves);
  }
}
