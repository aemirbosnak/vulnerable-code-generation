//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 4

#define LEFT_PADDLE_X 0
#define RIGHT_PADDLE_X BOARD_SIZE - PADDLE_SIZE - 1

#define BALL_START_X 2
#define BALL_START_Y 2

#define MOVE_BALL_UP 0
#define MOVE_BALL_RIGHT 1
#define MOVE_BALL_DOWN 2
#define MOVE_BALL_LEFT 3

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int ball_x = BALL_START_X;
    int ball_y = BALL_START_Y;
    int paddle_x = LEFT_PADDLE_X;
    int paddle_y = 0;
    int direction = MOVE_BALL_RIGHT;

    time_t t = time(NULL);
    int score = 0;

    while (!board[ball_x][ball_y] && time(NULL) - t < 60) {
        switch (direction) {
            case MOVE_BALL_UP:
                board[ball_x][ball_y] = 1;
                ball_y--;
                break;
            case MOVE_BALL_RIGHT:
                board[ball_x][ball_y] = 1;
                ball_x++;
                break;
            case MOVE_BALL_DOWN:
                board[ball_x][ball_y] = 1;
                ball_y++;
                break;
            case MOVE_BALL_LEFT:
                board[ball_x][ball_y] = 1;
                ball_x--;
                break;
        }

        if (board[ball_x][ball_y] == 2) {
            direction = MOVE_BALL_UP;
            score++;
        }

        if (board[ball_x][ball_y] == 3) {
            direction = MOVE_BALL_LEFT;
            score++;
        }

        if (ball_x == RIGHT_PADDLE_X) {
            direction = MOVE_BALL_DOWN;
        }

        if (ball_y == BOARD_SIZE - 1) {
            direction = MOVE_BALL_LEFT;
        }

        system("clear");
        for (int y = 0; y < BOARD_SIZE; y++) {
            for (int x = 0; x < BOARD_SIZE; x++) {
                printf("%d ", board[x][y]);
            }
            printf("\n");
        }

        printf("Score: %d\n", score);

        sleep(0.1);
    }

    return 0;
}