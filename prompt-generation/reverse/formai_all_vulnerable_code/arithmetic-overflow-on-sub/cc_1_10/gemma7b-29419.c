//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

typedef struct invader_t {
  int x, y;
  char direction;
} invader_t;

invader_t invaders[BOARD_SIZE];

void initialize_invasions(void) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    invaders[i].x = -1;
    invaders[i].y = -1;
    invaders[i].direction = ' ';
  }
}

void draw_board(void) {
  system("clear");
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      if (invaders[x].x == y) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

void move_invasions(void) {
  time_t t = time(NULL);
  if (time(NULL) - t >= 1) {
    for (int i = 0; i < BOARD_SIZE; i++) {
      switch (invaders[i].direction) {
        case 'r':
          invaders[i].x++;
          break;
        case 'l':
          invaders[i].x--;
          break;
        case 'u':
          invaders[i].y--;
          break;
        case 'd':
          invaders[i].y++;
          break;
      }

      if (invaders[i].x == BOARD_SIZE - 1) {
        invaders[i].direction = 'u';
      } else if (invaders[i].x == 0) {
        invaders[i].direction = 'r';
      } else if (invaders[i].y == BOARD_SIZE - 1) {
        invaders[i].direction = 'l';
      } else if (invaders[i].y == 0) {
        invaders[i].direction = 'd';
      }
    }
    t = time(NULL);
  }
}

int main(void) {
  initialize_invasions();
  draw_board();
  move_invasions();
  draw_board();
  return 0;
}