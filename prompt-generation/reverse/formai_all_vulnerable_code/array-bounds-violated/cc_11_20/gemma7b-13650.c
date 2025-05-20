//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdlib.h>
#include <stdio.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int main()
{
    int x = 5, y = 5, direction = RIGHT, speed = 1;
    char board[10][10] = {{0}};

    board[x][y] = 'O';

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        switch (direction)
        {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
        }

        if (board[x][y] == '#')
        {
            direction = UP;
            speed = 1;
        }
        else if (board[x][y] == 'O')
        {
            direction = UP;
            speed = 0;
        }

        board[x][y] = 'O';

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        if (speed)
        {
            sleep(0.1);
        }
    }

    return 0;
}