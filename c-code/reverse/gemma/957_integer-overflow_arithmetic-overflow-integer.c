#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int numDisks;
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);

  // Move the disks
  int moveDisks(int numDisks, int fromPeg, int toPeg) {
    printf("Move disk %d from peg %d to peg %d\n", numDisks, fromPeg, toPeg);
  }

  moveDisks(numDisks, 1, 3);
  moveDisks(numDisks - 1, 3, 2);
  moveDisks(numDisks - 1, 2, 3);

  return 0;
}
