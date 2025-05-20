//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 10

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    int ball_x = 2;
    int ball_y = 2;
    int paddle_x = 1;
    int paddle_y = BOARD_SIZE - 1;

    char direction = 'r';

    time_t start_time = time(NULL);
    int score = 0;

    while (!board[ball_y][ball_x] && time(NULL) - start_time < 60) {
        switch (direction) {
            case 'r':
                ball_x++;
                break;
            case 'l':
                ball_x--;
                break;
            case 'u':
                ball_y--;
                break;
            case 'd':
                ball_y++;
                break;
        }

        if (board[ball_y][ball_x] == 1) {
            board[ball_y][ball_x] = 2;
            direction = 'r';
            ball_x++;
            score++;
        } else if (board[ball_y][ball_x] == 2) {
            direction = 'l';
            ball_x--;
        } else if (board[ball_y][ball_x] == 3) {
            direction = 'u';
            ball_y--;
        } else if (board[ball_y][ball_x] == 4) {
            direction = 'd';
            ball_y++;
        }

        board[ball_y][ball_x] = 3;
        board[paddle_y][paddle_x] = 4;

        system("clear");
        for (int y = 0; y < BOARD_SIZE; y++) {
            for (int x = 0; x < BOARD_SIZE; x++) {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }

        printf("Score: %d\n", score);
    }

    return 0;
}