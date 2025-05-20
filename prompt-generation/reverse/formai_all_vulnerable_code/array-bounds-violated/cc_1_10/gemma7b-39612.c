//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

int main()
{
    int x = 10, y = 10, direction = RIGHT;
    char board[MAX_WIDTH * MAX_HEIGHT] = {'#'};

    board[x * MAX_HEIGHT + y] = 'O';

    for (int i = 0; i < 10000; i++)
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

        if (board[x * MAX_HEIGHT + y] == '#')
        {
            direction = (direction + 1) % 4;
        }

        board[x * MAX_HEIGHT + y] = 'O';
    }

    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++)
    {
        printf("%c", board[i]);
    }

    return 0;
}