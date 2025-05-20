//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0},
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
                if (x == player_x && y == player_y)
                {
                    printf("P ");
                }
                else if (board[x][y] == 1)
                {
                    printf("# ");
                }
                else
                {
                    printf("  ");
                }
            }

            printf("\n");
        }

        printf("Enter direction (w, a, s, d): ");
        scanf(" %c", &direction);

        switch (direction)
        {
            case 'w':
                if (player_y > 0)
                {
                    player_y--;
                }
                break;
            case 'a':
                if (player_x > 0)
                {
                    player_x--;
                }
                break;
            case 's':
                if (player_y < HEIGHT - 1)
                {
                    player_y++;
                }
                break;
            case 'd':
                if (player_x < WIDTH - 1)
                {
                    player_x++;
                }
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        if (board[player_x][player_y] == 1)
        {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}