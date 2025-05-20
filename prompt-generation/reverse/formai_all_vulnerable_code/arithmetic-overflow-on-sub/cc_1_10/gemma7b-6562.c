//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 5
#define TURN_RADIUS 20

typedef struct Knight {
  int x, y;
  int direction;
  int speed;
} Knight;

Knight knight;

void moveKnight(int dx, int dy) {
  knight.x += dx;
  knight.y += dy;

  switch (knight.direction) {
    case 0:
      knight.x++;
      break;
    case 1:
      knight.y++;
      break;
    case 2:
      knight.x--;
      break;
    case 3:
      knight.y--;
      break;
  }
}

int main() {
  knight.x = 0;
  knight.y = 0;
  knight.direction = 0;
  knight.speed = 0;

  time_t start_time = time(NULL);

  while (time(NULL) - start_time < 60) {
    int input = getchar();

    switch (input) {
      case 'w':
        moveKnight(0, MAX_SPEED);
        break;
      case 'a':
        moveKnight(-TURN_RADIUS, 0);
        break;
      case 's':
        moveKnight(0, -MAX_SPEED);
        break;
      case 'd':
        moveKnight(TURN_RADIUS, 0);
        break;
    }

    knight.speed++;

    if (knight.speed > MAX_SPEED) {
      knight.speed = MAX_SPEED;
    }
  }

  return 0;
}