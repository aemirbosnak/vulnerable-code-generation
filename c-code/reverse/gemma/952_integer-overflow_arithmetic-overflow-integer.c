#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int nDisks;
  scanf("%d", &nDisks);

  int **towers = (int**)malloc(nDisks * sizeof(int*));
  for (int i = 0; i < nDisks; i++) {
    towers[i] = (int*)malloc(nDisks * sizeof(int));
  }

  for (int i = 0; i < nDisks; i++) {
    for (int j = 0; j < nDisks; j++) {
      towers[i][j] = 0;
    }
  }

  int moveDisks(int numDisks, int source, int destination) {
    if (numDisks == 1) {
      towers[destination][0] = towers[source][0];
      return 1;
    } else {
      moveDisks(numDisks - 1, source, destination - 1);
      towers[destination][numDisks - 1] = towers[source][numDisks - 1];
      moveDisks(1, source - 1, destination);
      return moveDisks(numDisks, source, destination) + 1;
    }
  }

  moveDisks(nDisks, 0, 2);

  printf("Number of moves: %d\n", moveDisks(nDisks, 0, 2));

  for (int i = 0; i < nDisks; i++) {
    free(towers[i]);
  }
  free(towers);

  return 0;
}
