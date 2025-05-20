//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define PADDLE_SIZE 5

typedef struct Paddle {
  int x;
  int y;
  int speed_x;
  int speed_y;
} Paddle;

Paddle player1;
Paddle player2;

void initialize_paddles() {
  player1.x = 0;
  player1.y = BOARD_SIZE / 2 - PADDLE_SIZE / 2;
  player1.speed_x = 0;
  player1.speed_y = 0;

  player2.x = BOARD_SIZE - PADDLE_SIZE - 1;
  player2.y = BOARD_SIZE / 2 - PADDLE_SIZE / 2;
  player2.speed_x = 0;
  player2.speed_y = 0;
}

void move_paddles() {
  player1.x += player1.speed_x;
  player1.y += player1.speed_y;

  player2.x += player2.speed_x;
  player2.y += player2.speed_y;
}

void draw_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (i == player1.y && j == player1.x) {
        printf("P");
      } else if (i == player2.y && j == player2.x) {
        printf("P");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  initialize_paddles();

  time_t start_time = time(NULL);

  while (time(NULL) - start_time < 10) {
    move_paddles();
    draw_board();

    // AI move
    player2.speed_y = -1;
    if (player2.y < 0) {
      player2.speed_y = 1;
    }

    sleep(0.1);
  }

  return 0;
}