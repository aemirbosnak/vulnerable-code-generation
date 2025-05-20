//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: optimized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2

typedef struct Ball {
    int x;
    int y;
    int dx;
    int dy;
} Ball;

Ball ball;
int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

void draw_board() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void move_ball() {
    ball.x += ball.dx;
    ball.y += ball.dy;

    if (ball.x >= BOARD_SIZE - BALL_SIZE || ball.x < 0) {
        ball.dx *= -1;
    }

    if (ball.y >= BOARD_SIZE - BALL_SIZE || ball.y < 0) {
        ball.dy *= -1;
    }

    board[ball.x][ball.y] = 1;
}

int main() {
    srand(time(NULL));

    ball.x = rand() % BOARD_SIZE;
    ball.y = rand() % BOARD_SIZE;
    ball.dx = rand() % 2 - 1;
    ball.dy = rand() % 2 - 1;

    draw_board();
    move_ball();
    draw_board();

    return 0;
}