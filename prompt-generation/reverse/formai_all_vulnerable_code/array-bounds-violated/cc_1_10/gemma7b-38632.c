//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 4

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    int ball_x = 1;
    int ball_y = 0;
    int paddle_x = 0;
    int paddle_y = BOARD_SIZE - 1;

    time_t t = time(NULL);
    int seed = t;

    srand(seed);

    int direction = rand() % 2;

    while (!board[ball_y][ball_x] && ball_x >= 0 && ball_x < BOARD_SIZE && ball_y >= 0)
    {
        switch (direction)
        {
            case 0:
                ball_y--;
                break;
            case 1:
                ball_x++;
                break;
        }

        board[ball_y][ball_x] = 1;

        if (ball_x == paddle_x && ball_y == paddle_y)
        {
            direction = (rand() % 2) ? 0 : 1;
            paddle_y--;
        }

        sleep(0.05);
    }

    return 0;
}