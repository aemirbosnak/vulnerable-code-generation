//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

#define PADDLE_SIZE 100

typedef struct Paddle {
  int x;
  int y;
  int dx;
  int dy;
} Paddle;

Paddle player, ai;

void initialize() {
  player.x = WIDTH / 2 - PADDLE_SIZE / 2;
  player.y = HEIGHT - PADDLE_SIZE - 20;
  player.dx = 0;
  player.dy = 0;

  ai.x = WIDTH / 2 - PADDLE_SIZE / 2;
  ai.y = 0;
  ai.dx = 0;
  ai.dy = 0;
}

void move_paddle() {
  player.y += player.dy;

  if (player.y < 0) {
    player.y = 0;
  } else if (player.y > HEIGHT - PADDLE_SIZE) {
    player.y = HEIGHT - PADDLE_SIZE;
  }
}

void ai_move() {
  if (ai.y < player.y) {
    ai.dy = 1;
  } else if (ai.y > player.y) {
    ai.dy = -1;
  } else {
    ai.dy = 0;
  }

  ai.y += ai.dy;

  if (ai.y < 0) {
    ai.y = 0;
  } else if (ai.y > HEIGHT - PADDLE_SIZE) {
    ai.y = HEIGHT - PADDLE_SIZE;
  }
}

void draw_paddles() {
  printf("*******************************\n");
  printf("       /\ /|/\n");
  printf("      || \__) |\n");
  printf("      \__) \__) |\n");
  printf("*******************************\n");

  printf("*******************************\n");
  printf("       / \__) |/\n");
  printf("      || \__) \__) |\n");
  printf("      \__) \__) \__) |\n");
  printf("*******************************\n");
}

void main() {
  initialize();

  time_t start = time(NULL);

  while (time(NULL) - start < 60) {
    move_paddle();
    ai_move();
    draw_paddles();

    if (player.x - ai.x == 0 && player.y - ai.y == 0) {
      printf("It's a draw!");
      break;
    }
  }

  printf("Game Over! Player Won!");
}