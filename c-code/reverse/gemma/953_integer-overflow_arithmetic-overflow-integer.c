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

  // Dynamically allocate memory for the towers
  int *towers = (int *)malloc(numDisks * sizeof(int));
  for (int i = 0; i < numDisks; i++) {
    towers[i] = 0;
  }

  // Simulate the Tower of Hanoi game
  moveDisks(numDisks, towers);

  // Free the dynamically allocated memory
  free(towers);

  return 0;
}

void moveDisks(int numDisks, int *towers) {
  for (int i = 0; i < numDisks; i++) {
    int source = findSource(numDisks, towers);
    int destination = findDestination(numDisks, towers);
    towers[destination] = towers[source] + 1;
    towers[source] = 0;
  }
}

int findSource(int numDisks, int *towers) {
  for (int i = 0; i < numDisks; i++) {
    if (towers[i] > 0) {
      return i;
    }
  }
  return -1;
}

int findDestination(int numDisks, int *towers) {
  for (int i = 0; i < numDisks; i++) {
    if (towers[i] == 0) {
      return i;
    }
  }
  return -1;
}
