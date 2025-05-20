//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int main()
{
    char **board = (char **)malloc(HEIGHT * sizeof(char *));
    for(int i = 0; i < HEIGHT; i++)
    {
        board[i] = (char *)malloc(WIDTH * sizeof(char));
    }

    int x = 0, y = 0;
    board[x][y] = 'O';

    int direction = RIGHT;

    while(1)
    {
        switch(direction)
        {
            case UP:
                if(board[x][y - 1] != '#')
                {
                    board[x][y - 1] = 'O';
                    y--;
                }
                break;
            case DOWN:
                if(board[x][y + 1] != '#')
                {
                    board[x][y + 1] = 'O';
                    y++;
                }
                break;
            case RIGHT:
                if(board[x + 1][y] != '#')
                {
                    board[x + 1][y] = 'O';
                    x++;
                }
                break;
            case LEFT:
                if(board[x - 1][y] != '#')
                {
                    board[x - 1][y] = 'O';
                    x--;
                }
                break;
        }

        if(board[x][y] == '#')
        {
            printf("Game Over!");
            break;
        }

        direction = rand() % 4;
    }

    free(board);

    return 0;
}