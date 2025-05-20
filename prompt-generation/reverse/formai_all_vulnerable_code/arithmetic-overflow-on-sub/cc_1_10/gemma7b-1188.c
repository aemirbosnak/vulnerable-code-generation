//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20

#define BALL_SIZE 20

int main()
{
    int x = 0;
    int y = HEIGHT - 1;
    int dx = 1;
    int dy = -1;

    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    board[x][y] = BALL_SIZE;

    time_t t = time(NULL);
    while (time(NULL) - t < 60)
    {
        x += dx;
        y += dy;

        if (x >= WIDTH - BALL_SIZE || x <= 0)
        {
            dx *= -1;
        }

        if (y >= HEIGHT - BALL_SIZE || y <= 0)
        {
            dy *= -1;
        }

        board[x][y] = BALL_SIZE;
        board[x][y - 1] = BALL_SIZE;

        system("clear");
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (board[j][i] == BALL_SIZE)
                {
                    printf("#");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }

        sleep(0.1);
    }

    return 0;
}