//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: retro
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    system("clear");
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (1)
    {
        system("clear");

        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (board[x][y] == 1)
                {
                    printf("O ");
                }
                else if (x == player_x && y == player_y)
                {
                    printf("P ");
                }
                else
                {
                    printf(" ");
                }
            }

            printf("\n");
        }

        switch (direction)
        {
            case 'w':
                player_y--;
                break;
            case 'a':
                player_x--;
                break;
            case 's':
                player_y++;
                break;
            case 'd':
                player_x++;
                break;
        }

        if (board[player_x][player_y] == 1)
        {
            printf("Game Over!");
            break;
        }

        if (player_x == WIDTH - 1)
        {
            direction = 's';
        }
        else if (player_x == 0)
        {
            direction = 'a';
        }
        else if (player_y == HEIGHT - 1)
        {
            direction = 'w';
        }
        else if (player_y == 0)
        {
            direction = 'd';
        }

        sleep(0.1);
    }

    return 0;
}