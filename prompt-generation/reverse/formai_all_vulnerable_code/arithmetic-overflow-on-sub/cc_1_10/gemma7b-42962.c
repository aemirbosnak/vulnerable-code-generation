//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 20

#define BALL_SIZE 20

void draw_paddle(int x, int y, int w, int h) {
  for (int i = x; i < x + w; i++) {
    for (int j = y; j < y + h; j++) {
      printf("%c", '*');
    }
    printf("\n");
  }
}

void draw_ball(int x, int y) {
  printf("%c", 'o');
  printf("(");
  printf("%d", x);
  printf(", ");
  printf("%d", y);
  printf(")\n");
}

int main() {
  int x_paddle1 = WIDTH / 2 - PADDLE_WIDTH / 2;
  int y_paddle1 = HEIGHT - PADDLE_HEIGHT - 10;
  int x_paddle2 = WIDTH / 2 + PADDLE_WIDTH / 2;
  int y_paddle2 = 10;

  int ball_x = WIDTH / 2;
  int ball_y = HEIGHT / 2;

  int direction = 1;

  time_t start_time = time(NULL);

  while (time(NULL) - start_time < 60) {
    draw_paddle(x_paddle1, y_paddle1, PADDLE_WIDTH, PADDLE_HEIGHT);
    draw_paddle(x_paddle2, y_paddle2, PADDLE_WIDTH, PADDLE_HEIGHT);
    draw_ball(ball_x, ball_y);

    if (ball_x + BALL_SIZE / 2 >= WIDTH || ball_x - BALL_SIZE / 2 <= 0) {
      direction *= -1;
    }

    if (ball_y + BALL_SIZE / 2 >= HEIGHT || ball_y - BALL_SIZE / 2 <= 0) {
      direction *= -1;
    }

    ball_x += direction * 2;
    ball_y += direction;

    sleep(0.05);
  }

  return 0;
}