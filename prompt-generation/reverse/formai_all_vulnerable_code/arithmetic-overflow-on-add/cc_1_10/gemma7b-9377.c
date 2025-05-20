//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5
#define GHOUL_SPEED 2
#define GHOUL_DELAY 1

typedef struct Ghost {
  int x, y;
  char direction;
  time_t timer;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].x = rand() % 10;
    ghosts[i].y = rand() % 10;
    ghosts[i].direction = (rand() % 2) ? 'H' : 'V';
    ghosts[i].timer = time(NULL) + GHOUL_DELAY;
  }
}

void moveGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    switch (ghosts[i].direction) {
      case 'H':
        ghosts[i].x += GHOUL_SPEED;
        if (ghosts[i].x >= 10) ghosts[i].direction = 'V';
        break;
      case 'V':
        ghosts[i].y += GHOUL_SPEED;
        if (ghosts[i].y >= 10) ghosts[i].direction = 'H';
        break;
    }
    ghosts[i].timer = time(NULL) + GHOUL_DELAY;
  }
}

void checkCollisions() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    for (int j = 0; j < MAX_GHOULS; j++) {
      if (i != j && ghosts[i].x == ghosts[j].x && ghosts[i].y == ghosts[j].y) {
        ghosts[i].direction = (rand() % 2) ? 'H' : 'V';
      }
    }
  }
}

int main() {
  initializeGhosts();
  moveGhosts();
  checkCollisions();

  return 0;
}