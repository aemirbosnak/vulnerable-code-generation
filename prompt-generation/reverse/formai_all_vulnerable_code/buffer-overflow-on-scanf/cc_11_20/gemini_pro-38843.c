//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

typedef struct {
  int num_disks;
  int pegs[3];
} State;

int main() {
  State state;
  int i, j;

  printf("Enter the number of disks: ");
  scanf("%d", &state.num_disks);

  // Initialize the pegs.
  for (i = 0; i < 3; i++) {
    state.pegs[i] = 0;
  }

  // Place the disks on the first peg.
  for (i = state.num_disks; i > 0; i--) {
    state.pegs[0] |= (1 << (i - 1));
  }

  // Solve the Tower of Hanoi problem.
  for (i = 0; i < (1 << state.num_disks); i++) {
    // Find the disk that is being moved.
    for (j = 0; j < 3; j++) {
      if ((state.pegs[j] & (1 << i)) != 0) {
        break;
      }
    }

    // Find the peg that the disk is being moved to.
    for (j = 0; j < 3; j++) {
      if ((state.pegs[j] & (1 << i)) == 0) {
        break;
      }
    }

    // Move the disk.
    state.pegs[j] |= (1 << i);
    state.pegs[j - 1] &= ~(1 << i);
  }

  // Print the solution.
  for (i = 0; i < 3; i++) {
    for (j = 0; j < state.num_disks; j++) {
      if ((state.pegs[i] & (1 << j)) != 0) {
        printf("%d ", i + 1);
      }
    }
  }

  printf("\n");

  return 0;
}