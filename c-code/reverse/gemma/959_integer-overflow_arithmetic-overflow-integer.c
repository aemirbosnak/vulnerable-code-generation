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

  int moveDisks(int numDisks, int source, int destination) {
    if (numDisks > 0) {
      moveDisks(numDisks - 1, source, destination);
      printf("Move disk %d from %c to %c\n", numDisks, source, destination);
      moveDisks(numDisks - 1, destination, source);
    }
  }

  moveDisks(numDisks, 'a', 'c');

  return 0;
}
