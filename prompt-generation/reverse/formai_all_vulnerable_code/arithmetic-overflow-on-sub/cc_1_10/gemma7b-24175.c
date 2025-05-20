//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    time_t t = time(NULL);

    while (board[player_x][player_y] == 0)
    {
        int direction = rand() % 4;

        switch (direction)
        {
            case 0:
                player_y--;
                break;
            case 1:
                player_x++;
                break;
            case 2:
                player_y++;
                break;
            case 3:
                player_x--;
                break;
        }

        if (board[player_x][player_y] == 1)
        {
            board[player_x][player_y] = 2;
        }

        sleep(time(NULL) - t);
        t = time(NULL);
    }

    printf("You win!");

    return 0;
}