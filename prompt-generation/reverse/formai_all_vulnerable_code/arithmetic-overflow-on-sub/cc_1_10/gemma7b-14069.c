//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
  char name[20];
  int room_num;
  int active;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].active = 0;
  }
}

void activateGhost(int room_num) {
  for (int i = 0; i < MAX_GHOULS; i++) {
    if (ghosts[i].room_num == room_num) {
      ghosts[i].active = 1;
    }
  }
}

void simulateHauntedHouse() {
  initializeGhosts();
  activateGhost(1);
  activateGhost(3);
  activateGhost(5);

  time_t t = time(NULL);
  for (int i = 0; i < 10; i++) {
    printf("Time: %ld\n", time(NULL) - t);
    for (int j = 0; j < MAX_GHOULS; j++) {
      if (ghosts[j].active) {
        printf("Ghost: %s is roaming the halls!\n", ghosts[j].name);
      }
    }
    sleep(1);
  }
}

int main() {
  simulateHauntedHouse();
  return 0;
}