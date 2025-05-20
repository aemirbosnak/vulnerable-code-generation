//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5
#define BALL_SIZE 2

typedef struct Ball {
    int x;
    int y;
    int dx;
    int dy;
} Ball;

void draw_board(Ball ball) {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == ball.x && y == ball.y) {
                printf("O");
            } else if (x == 0 && y == 0) {
                printf("W");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    Ball ball;
    ball.x = WIDTH / 2;
    ball.y = HEIGHT - 1;
    ball.dx = -1;
    ball.dy = -1;

    time_t t = time(NULL);
    int score = 0;

    while (ball.x >= 0 && ball.x < WIDTH && ball.y >= 0 && ball.y < HEIGHT) {
        draw_board(ball);

        ball.x += ball.dx;
        ball.y += ball.dy;

        if (time(NULL) - t > 0) {
            score++;
            t = time(NULL);
        }

        if (ball.x == 0 || ball.x == WIDTH - 1) {
            ball.dx *= -1;
        }
        if (ball.y == 0) {
            ball.dy *= -1;
        }
    }

    draw_board(ball);
    printf("GAME OVER!\n");
    printf("Your score: %d\n", score);

    return 0;
}