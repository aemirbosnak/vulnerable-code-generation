//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GHOULS 5
#define GHOUL_MAX_SPEED 3
#define ROOM_MAX_SIZE 10

typedef struct Ghost {
  char name[20];
  int x, y;
  int speed_x, speed_y;
  int target_x, target_y;
} Ghost;

Ghost ghosts[NUM_GHOULS];

void initialize_ghosts() {
  for (int i = 0; i < NUM_GHOULS; i++) {
    ghosts[i].x = rand() % ROOM_MAX_SIZE;
    ghosts[i].y = rand() % ROOM_MAX_SIZE;
    ghosts[i].speed_x = rand() % GHOUL_MAX_SPEED;
    ghosts[i].speed_y = rand() % GHOUL_MAX_SPEED;
    ghosts[i].target_x = rand() % ROOM_MAX_SIZE;
    ghosts[i].target_y = rand() % ROOM_MAX_SIZE;
  }
}

void move_ghosts() {
  for (int i = 0; i < NUM_GHOULS; i++) {
    int dx = ghosts[i].speed_x;
    int dy = ghosts[i].speed_y;

    ghosts[i].x += dx * time(NULL) / 1000;
    ghosts[i].y += dy * time(NULL) / 1000;

    if (ghosts[i].x >= ROOM_MAX_SIZE || ghosts[i].x <= 0) {
      ghosts[i].speed_x *= -1;
    }
    if (ghosts[i].y >= ROOM_MAX_SIZE || ghosts[i].y <= 0) {
      ghosts[i].speed_y *= -1;
    }

    if (ghosts[i].x == ghosts[i].target_x && ghosts[i].y == ghosts[i].target_y) {
      ghosts[i].target_x = rand() % ROOM_MAX_SIZE;
      ghosts[i].target_y = rand() % ROOM_MAX_SIZE;
    }
  }
}

int main() {
  initialize_ghosts();
  move_ghosts();

  return 0;
}