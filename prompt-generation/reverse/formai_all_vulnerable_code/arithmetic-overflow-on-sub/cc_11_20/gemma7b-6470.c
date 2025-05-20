//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

int main()
{
    int x = MAX_WIDTH / 2;
    int y = MAX_HEIGHT - 1;
    int direction = RIGHT;
    int speed = 1;

    char board[MAX_HEIGHT][MAX_WIDTH] = {{0}};

    board[y][x] = 'O';

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 60)
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

        if (x < 0)
        {
            direction = RIGHT;
            x = 0;
        }
        else if (x >= MAX_WIDTH - 1)
        {
            direction = LEFT;
            x = MAX_WIDTH - 2;
        }
        else if (y < 0)
        {
            direction = DOWN;
            y = 0;
        }
        else if (y >= MAX_HEIGHT - 1)
        {
            direction = UP;
            y = MAX_HEIGHT - 2;
        }

        board[y][x] = 'O';
        board[y][x - speed] = ' ';

        speed++;

        system("clear");

        for (int i = 0; i < MAX_HEIGHT; i++)
        {
            for (int j = 0; j < MAX_WIDTH; j++)
            {
                printf("%c ", board[i][j]);
            }

            printf("\n");
        }

        sleep(1);
    }

    return 0;
}