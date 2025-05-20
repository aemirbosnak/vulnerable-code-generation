//Gemma-7B DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include <stdio.h>

int conflict(int side, int current_state) {
  switch (side) {
    case 1:
      printf("Montague's side is engaged in conflict.\n");
      switch (current_state) {
        case 1:
          printf("The feud escalates.\n");
          return 1;
        case 2:
          printf("The tension subsides.\n");
          return 0;
        default:
          printf("An unexpected situation arises.\n");
          return -1;
      }
    case 2:
      printf("Capulet's side is engaged in conflict.\n");
      switch (current_state) {
        case 1:
          printf("The feud escalates.\n");
          return 1;
        case 2:
          printf("The tension subsides.\n");
          return 0;
        default:
          printf("An unexpected situation arises.\n");
          return -1;
      }
    default:
      printf("Invalid side.\n");
      return -1;
  }
}

int main() {
  int side, current_state;
  printf("Enter the side (1 or 2) involved in the conflict: ");
  scanf("%d", &side);
  printf("Enter the current state of the conflict (1 or 2): ");
  scanf("%d", &current_state);

  int result = conflict(side, current_state);

  if (result == 0) {
    printf("The conflict subsides.\n");
  } else if (result == 1) {
    printf("The feud escalates.\n");
  } else if (result == -1) {
    printf("An unexpected situation arises.\n");
  }

  return 0;
}