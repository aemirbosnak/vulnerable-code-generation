//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 5

typedef struct Paddle {
  int x;
  int y;
  int dx;
  int dy;
} Paddle;

Paddle player1;
Paddle player2;

void initializePaddles() {
  player1.x = 10;
  player1.y = 200;
  player1.dx = 0;
  player1.dy = MAX_SPEED;

  player2.x = 790;
  player2.y = 200;
  player2.dx = 0;
  player2.dy = -MAX_SPEED;
}

void updatePaddles() {
  player1.x += player1.dx;
  player1.y += player1.dy;

  player2.x += player2.dx;
  player2.y += player2.dy;

  if (player1.x < 0) {
    player1.x = 0;
  } else if (player1.x > 790) {
    player1.x = 790;
  }

  if (player2.x < 0) {
    player2.x = 0;
  } else if (player2.x > 790) {
    player2.x = 790;
  }
}

void drawPaddles() {
  printf("*************************************\n");
  printf("           /\n");
  printf("          |||||\n");
  printf("           \__)\n");
  printf("*************************************\n");

  printf("*************************************\n");
  printf("           /|\n");
  printf("          |||||\n");
  printf("           \__)\n");
  printf("*************************************\n");
}

int main() {
  initializePaddles();

  time_t t = time(NULL);
  int score = 0;

  while (1) {
    updatePaddles();
    drawPaddles();

    if (time(NULL) - t >= 1) {
      t = time(NULL);
      score++;
    }

    if (player1.y > 400) {
      printf("Player 2 wins!\n");
      break;
    } else if (player2.y < 0) {
      printf("Player 1 wins!\n");
      break;
    }
  }

  printf("Final score: %d", score);

  return 0;
}