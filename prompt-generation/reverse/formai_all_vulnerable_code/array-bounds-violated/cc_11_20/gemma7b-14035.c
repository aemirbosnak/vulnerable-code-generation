//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define BALL_SIZE 2
#define PADDLE_SIZE 5

int main() {
    int x_pos = WIDTH / 2;
    int y_pos = HEIGHT - 1;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 1;
    int direction = 1;
    int paddle_x = 0;
    int paddle_y = HEIGHT - 1;

    char board[WIDTH][HEIGHT] = {'#'};

    for (int i = 0; i < WIDTH; i++) {
        board[i][HEIGHT - 1] = '+';
    }

    board[ball_x][ball_y] = 'o';
    board[paddle_x][paddle_y] = 'P';

    while (1) {
        system("clear");

        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                printf("%c ", board[i][j]);
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
                ball_y--;
                break;
            case 4:
                ball_y++;
                break;
        }

        if (board[ball_x][ball_y] == '#') {
            direction = 0;
        }

        if (board[ball_x][ball_y] == 'P') {
            direction = 0;
        }

        if (ball_x >= WIDTH - BALL_SIZE || ball_x <= 0) {
            direction = 2;
        }

        if (ball_y <= 0) {
            direction = 3;
        }

        if (direction == 0) {
            printf("Game Over!");
            break;
        }

        sleep(0.1);
    }

    return 0;
}