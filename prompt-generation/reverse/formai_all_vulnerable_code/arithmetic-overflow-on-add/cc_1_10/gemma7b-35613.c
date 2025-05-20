//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int room;
  int active;
  int timer;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
  {"Mary", 1, 1, 0},
  {"John", 2, 1, 0},
  {"Sarah", 3, 0, 0},
  {"Peter", 4, 0, 0},
  {"Alice", 5, 0, 0}
};

void spawnGhost(Ghost *ghost) {
  ghost->active = 1;
  ghost->timer = time(NULL) +  rand() % 10;
}

void moveGhost(Ghost *ghost) {
  int targetRoom = rand() % MAX_GHOSTS + 1;
  if (targetRoom != ghost->room) {
    ghost->room = targetRoom;
  }
}

void interactGhost(Ghost *ghost) {
  switch (rand() % 3) {
    case 0:
      printf("You hear a voice whispering your name.\n");
      break;
    case 1:
      printf("You feel a cold hand brush against your skin.\n");
      break;
    case 2:
      printf("You see a ghostly figure moving towards you.\n");
      break;
  }
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < MAX_GHOSTS; i++) {
    spawnGhost(&ghosts[i]);
  }

  while (1) {
    for (int i = 0; i < MAX_GHOSTS; i++) {
      moveGhost(&ghosts[i]);
      interactGhost(&ghosts[i]);
    }

    if (time(NULL) >= ghosts[0].timer) {
      break;
    }
  }

  printf("The ghosts have vanished.\n");

  return 0;
}