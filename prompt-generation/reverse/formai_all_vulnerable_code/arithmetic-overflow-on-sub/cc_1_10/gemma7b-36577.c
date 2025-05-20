//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5
#define GHOUL_SPEED 2

typedef struct Ghost {
  char name[20];
  int x, y;
  int direction;
  time_t last_move_time;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].x = rand() % 10;
    ghosts[i].y = rand() % 10;
    ghosts[i].direction = rand() % 4;
    ghosts[i].last_move_time = time(NULL);
  }
}

void moveGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    time_t now = time(NULL);
    if (now - ghosts[i].last_move_time > GHOUL_SPEED) {
      switch (ghosts[i].direction) {
        case 0:
          ghosts[i].x++;
          break;
        case 1:
          ghosts[i].x--;
          break;
        case 2:
          ghosts[i].y++;
          break;
        case 3:
          ghosts[i].y--;
          break;
      }
      ghosts[i].last_move_time = now;
    }
  }
}

void printGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    printf("Ghost: %s (%d, %d)\n", ghosts[i].name, ghosts[i].x, ghosts[i].y);
  }
}

int main() {
  initializeGhosts();
  moveGhosts();
  printGhosts();

  return 0;
}