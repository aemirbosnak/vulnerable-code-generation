//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 1

typedef struct Ball {
    int x, y;
    int dx, dy;
} Ball;

typedef struct Paddle {
    int x, y;
    int dx, dy;
} Paddle;

Ball ball;
Paddle paddle;

void initializeGame() {
    ball.x = BOARD_SIZE / 2;
    ball.y = BOARD_SIZE - BALL_SIZE - 1;
    ball.dx = 1;
    ball.dy = -1;

    paddle.x = 0;
    paddle.y = BOARD_SIZE - PADDLE_SIZE - 1;
    paddle.dx = 0;
    paddle.dy = 0;
}

void moveBall() {
    ball.x += ball.dx * time(NULL) / 1000;
    ball.y += ball.dy * time(NULL) / 1000;

    if (ball.x >= BOARD_SIZE - BALL_SIZE || ball.x <= 0) {
        ball.dx *= -1;
    }

    if (ball.y <= 0) {
        ball.dy *= -1;
    }
}

void movePaddle() {
    int key = getchar();

    switch (key) {
        case 'w':
            paddle.y--;
            break;
        case 's':
            paddle.y++;
            break;
    }

    if (paddle.y < 0) {
        paddle.y = 0;
    }

    if (paddle.y >= BOARD_SIZE - PADDLE_SIZE) {
        paddle.y = BOARD_SIZE - PADDLE_SIZE;
    }
}

int main() {
    initializeGame();

    while (1) {
        moveBall();
        movePaddle();

        system("clear");

        printf("Ball: (%d, %d)\n", ball.x, ball.y);
        printf("Paddle: (%d, %d)\n", paddle.x, paddle.y);

        if (ball.x == paddle.x && ball.y == paddle.y) {
            printf("GAME OVER!\n");
            break;
        }
    }

    return 0;
}