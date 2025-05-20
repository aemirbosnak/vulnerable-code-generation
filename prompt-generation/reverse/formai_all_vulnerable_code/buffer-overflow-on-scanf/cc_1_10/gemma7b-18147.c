//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5
#define BALL_SIZE 2

typedef struct Ball {
  int x, y;
} Ball;

Ball ball;

void initializeBall() {
  ball.x = MAP_SIZE / 2;
  ball.y = MAP_SIZE - 1;
}

void moveBall(char direction) {
  switch (direction) {
    case 'w':
      ball.y--;
      break;
    case 'a':
      ball.x--;
      break;
    case 's':
      ball.y++;
      break;
    case 'd':
      ball.x++;
      break;
  }
}

void drawMap() {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (x == ball.x && y == ball.y) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  initializeBall();

  char direction;

  while (1) {
    drawMap();

    printf("Enter direction (w/a/s/d): ");
    scanf("%c", &direction);

    moveBall(direction);

    if (ball.x >= MAP_SIZE - BALL_SIZE || ball.x <= 0) {
      ball.x = MAP_SIZE / 2;
    }
    if (ball.y >= MAP_SIZE - BALL_SIZE || ball.y <= 0) {
      ball.y = MAP_SIZE - 1;
    }
  }

  return 0;
}