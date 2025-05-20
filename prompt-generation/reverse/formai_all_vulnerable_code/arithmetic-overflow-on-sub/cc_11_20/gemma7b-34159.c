//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int ball_x = BOARD_SIZE / 2;
    int ball_y = BOARD_SIZE - 1;
    int direction = RIGHT;

    time_t t = time(NULL);

    while (!board[ball_x][ball_y] && time(NULL) - t < 60)
    {
        switch (direction)
        {
            case LEFT:
                ball_x--;
                break;
            case RIGHT:
                ball_x++;
                break;
            case UP:
                ball_y--;
                break;
            case DOWN:
                ball_y++;
                break;
        }

        board[ball_x][ball_y] = 1;

        switch (direction)
        {
            case LEFT:
                if (board[ball_x - 1][ball_y] == 1)
                    direction = RIGHT;
                break;
            case RIGHT:
                if (board[ball_x + 1][ball_y] == 1)
                    direction = LEFT;
                break;
            case UP:
                if (board[ball_x][ball_y - 1] == 1)
                    direction = DOWN;
                break;
            case DOWN:
                if (board[ball_x][ball_y + 1] == 1)
                    direction = UP;
                break;
        }

        sleep(1);
    }

    return 0;
}