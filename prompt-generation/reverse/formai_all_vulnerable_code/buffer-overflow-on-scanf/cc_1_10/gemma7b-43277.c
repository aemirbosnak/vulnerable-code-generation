//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int location[2];
  int activity;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
  {"Mr. Jones", {10, 15}, 1},
  {"Mrs. Smith", {12, 18}, 2},
  {"Mr. Brown", {14, 16}, 3},
  {"Miss Alice", {16, 20}, 4},
  {"Mr. Grey", {18, 12}, 5}
};

int main() {
  int i, j, r, nGhosts = MAX_GHOULS;

  srand(time(NULL));

  for (i = 0; i < nGhosts; i++) {
    ghosts[i].activity = rand() % 3;
  }

  printf("Enter the room number: ");
  scanf("%d", &r);

  for (i = 0; i < nGhosts; i++) {
    if (ghosts[i].location[0] == r) {
      switch (ghosts[i].activity) {
        case 0:
          printf("You hear footsteps in the hallway.\n");
          break;
        case 1:
          printf("You smell a faint odor of burning flesh.\n");
          break;
        case 2:
          printf("You see a ghostly figure standing in the doorway.\n");
          break;
      }
    }
  }

  return 0;
}