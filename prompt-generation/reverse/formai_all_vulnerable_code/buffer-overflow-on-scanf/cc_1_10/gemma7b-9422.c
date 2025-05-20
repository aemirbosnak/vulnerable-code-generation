//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5
#define PLAYER_SIZE 2

int map[MAP_SIZE][MAP_SIZE] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0}};

int player_x = 0;
int player_y = 0;

void draw_map() {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (map[y][x] == 1) {
        printf("# ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void move_player(int dx, int dy) {
  if (map[player_y + dy][player_x + dx] == 0) {
    player_x += dx;
    player_y += dy;
  }
}

int main() {
  draw_map();

  char input;

  printf("Enter direction (w/a/s/d): ");
  scanf("%c", &input);

  switch (input) {
    case 'w':
      move_player(0, -1);
      break;
    case 'a':
      move_player(-1, 0);
      break;
    case 's':
      move_player(0, 1);
      break;
    case 'd':
      move_player(1, 0);
      break;
  }

  draw_map();

  return 0;
}