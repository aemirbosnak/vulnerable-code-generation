//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5
#define GHOUL_SPEED 2

struct ghoul {
  char name[20];
  int location[2];
  int direction[2];
  int speed;
  int target_location[2];
};

void initialize_ghosts(struct ghoul *ghosts) {
  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].speed = GHOUL_SPEED;
    ghosts[i].target_location[0] = rand() % 10;
    ghosts[i].target_location[1] = rand() % 10;
  }
}

void move_ghosts(struct ghoul *ghosts) {
  for (int i = 0; i < MAX_GHOULS; i++) {
    int dx = ghosts[i].target_location[0] - ghosts[i].location[0];
    int dy = ghosts[i].target_location[1] - ghosts[i].location[1];

    if (dx > 0) ghosts[i].direction[0] = 1;
    else if (dx < 0) ghosts[i].direction[0] = -1;
    if (dy > 0) ghosts[i].direction[1] = 1;
    else if (dy < 0) ghosts[i].direction[1] = -1;

    ghosts[i].location[0] += ghosts[i].direction[0] * ghosts[i].speed;
    ghosts[i].location[1] += ghosts[i].direction[1] * ghosts[i].speed;
  }
}

int main() {
  srand(time(NULL));
  struct ghoul ghosts[MAX_GHOULS];

  initialize_ghosts(ghosts);
  move_ghosts(ghosts);

  for (int i = 0; i < MAX_GHOULS; i++) {
    printf("Ghost %s is at (%d, %d)\n", ghosts[i].name, ghosts[i].location[0], ghosts[i].location[1]);
  }

  return 0;
}