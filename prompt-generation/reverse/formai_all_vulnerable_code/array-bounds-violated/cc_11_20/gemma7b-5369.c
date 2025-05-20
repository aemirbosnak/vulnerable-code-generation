//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int x = 0, y = 0, direction = 1, block_x = 2, block_y = 2, speed = 1;
    char board[HEIGHT][WIDTH] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                              ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    board[block_y][block_x] = 'B';

    while (1)
    {
        system("clear");
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        switch (direction)
        {
            case 1:
                x++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
        }

        if (board[y][x] == 'W')
        {
            direction = 0;
            speed = 0;
            printf("GAME OVER!");
        }

        if (board[y][x] == 'O')
        {
            direction = 0;
            speed = 0;
            printf("YOU WON!");
        }

        board[y][x] = 'P';

        if (speed > 0)
        {
            sleep(0.1);
        }
    }

    return 0;
}