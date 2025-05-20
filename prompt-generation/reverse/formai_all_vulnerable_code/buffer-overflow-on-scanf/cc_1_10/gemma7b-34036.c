//Gemma-7B DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_OF_SURVIVORS 5

typedef struct Survivor {
  char name[20];
  int health;
  int ammo;
  int position[2];
} Survivor;

Survivor survivors[MAX_NUM_OF_SURVIVORS];

void initializeSurvivors() {
  for (int i = 0; i < MAX_NUM_OF_SURVIVORS; i++) {
    survivors[i].name[0] = '\0';
    survivors[i].health = 100;
    survivors[i].ammo = 10;
    survivors[i].position[0] = -1;
    survivors[i].position[1] = -1;
  }
}

void moveSurvivor(Survivor *survivor) {
  printf("Enter the direction you want to move (N, S, E, W): ");
  char direction;
  scanf("%c", &direction);

  switch (direction) {
    case 'N':
      survivor->position[0]--;
      break;
    case 'S':
      survivor->position[0]++;
      break;
    case 'E':
      survivor->position[1]++;
      break;
    case 'W':
      survivor->position[1]--;
      break;
  }
}

void battle(Survivor *survivor) {
  printf("You encounter a hostile survivor. Prepare for battle!\n");

  // Combat mechanics
  survivor->health -= 20;
  survivor->ammo--;

  if (survivor->health <= 0) {
    printf("You have died. Game over.\n");
    exit(0);
  } else if (survivor->ammo <= 0) {
    printf("You have run out of ammo. You are defenseless.\n");
  } else {
    printf("You have survived the battle.\n");
  }
}

int main() {
  initializeSurvivors();

  Survivor *survivor = &survivors[0];

  moveSurvivor(survivor);
  battle(survivor);

  return 0;
}