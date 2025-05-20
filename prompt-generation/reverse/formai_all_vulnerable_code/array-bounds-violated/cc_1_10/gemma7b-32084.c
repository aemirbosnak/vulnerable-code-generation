//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    system("clear");
    int x = WIDTH / 2;
    int y = HEIGHT - 1;

    char board[HEIGHT][WIDTH] = {{'.', '.', '.', '.', '.'},
                              {'.', '#', '.', '.', '.'},
                              {'.', '#', '#', '.', '.'},
                              {'.', '#', '#', '#', '.'},
                              {'.', '.', '.', '.', '.'}
    };

    board[y][x] = '#';

    int direction = 1;

    while (board[y][x] != '$')
    {
        switch (direction)
        {
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
            case 4:
                y++;
                break;
        }

        if (board[y][x] == '#')
        {
            direction = (direction + 1) % 4;
            board[y][x] = '$';
        }
    }

    system("clear");
    printf("You won!");

    return 0;
}