//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 50
#define UP_BOUND 20
#define DOWN_BOUND 0

typedef struct invader {
  int x;
  int y;
  int direction;
} Invader;

Invader invaders[5] = {
  { LEFT_BOUND, UP_BOUND, 1 },
  { RIGHT_BOUND, UP_BOUND, -1 },
  { LEFT_BOUND, DOWN_BOUND, 1 },
  { RIGHT_BOUND, DOWN_BOUND, -1 },
  { LEFT_BOUND, DOWN_BOUND, 1 }
};

void draw_invaders() {
  for (int i = 0; i < 5; i++) {
    printf("X ");
  }
  printf("\n");
}

void move_invaders() {
  for (int i = 0; i < 5; i++) {
    switch (invaders[i].direction) {
      case 1:
        invaders[i].x++;
        break;
      case -1:
        invaders[i].x--;
        break;
    }

    if (invaders[i].x < LEFT_BOUND || invaders[i].x > RIGHT_BOUND) {
      invaders[i].direction *= -1;
    }
  }
}

int main() {
  int score = 0;
  time_t t = time(NULL);

  while (time(NULL) - t < 10) {
    system("clear");
    draw_invaders();
    move_invaders();
    score++;

    printf("Score: %d\n", score);
    sleep(0.2);
  }

  return 0;
}