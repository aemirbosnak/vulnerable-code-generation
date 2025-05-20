//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    system("clear");
    system("color 2");

    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 1}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (board[player_x][player_y] != 1)
    {
        printf("Press 'w', 'a', 's', or 'd' to move:");
        scanf(" %c", &direction);

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
            default:
                break;
        }

        system("clear");
        system("color 2");

        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x == player_x && y == player_y)
                {
                    printf("O ");
                }
                else if (board[x][y] == 1)
                {
                    printf("X ");
                }
                else
                {
                    printf("  ");
                }
            }

            printf("\n");
        }
    }

    printf("You win!");

    return 0;
}