//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 3

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    int ball_x = 2;
    int ball_y = 2;

    int paddle_x = 1;
    int paddle_y = 0;

    int direction = 1;

    while (1) {
        system("clear");

        for (int y = 0; y < BOARD_SIZE; y++) {
            for (int x = 0; x < BOARD_SIZE; x++) {
                if (board[y][x] == 1) {
                    printf("%c ", '*');
                } else if (x == ball_x && y == ball_y) {
                    printf("%c ", '#');
                } else if (x == paddle_x && y == paddle_y) {
                    printf("%c ", '$');
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        switch (direction) {
            case 1:
                ball_x++;
                break;
            case 2:
                ball_x--;
                break;
            case 3:
                ball_y++;
                break;
            case 4:
                ball_y--;
                break;
        }

        if (ball_x >= BOARD_SIZE - BALL_SIZE || ball_x <= 0) {
            direction = 2;
        }

        if (ball_y >= BOARD_SIZE - BALL_SIZE || ball_y <= 0) {
            direction = 4;
        }

        if (board[ball_y][ball_x] == 1) {
            printf("Game Over!\n");
            break;
        }

        if (ball_x == paddle_x && ball_y == paddle_y) {
            direction = 3;
        }

        sleep(0.1);
    }

    return 0;
}