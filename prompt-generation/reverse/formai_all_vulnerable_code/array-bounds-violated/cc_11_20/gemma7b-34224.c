//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (1)
    {
        system("clear");

        // Draw the board
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
                    printf("  ");
                }
            }

            printf("\n");
        }

        // Get the direction of the player
        direction = getchar();

        // Move the player
        switch (direction)
        {
            case 'w':
                player_y--;
                break;
            case 's':
                player_y++;
                break;
            case 'a':
                player_x--;
                break;
            case 'd':
                player_x++;
                break;
        }

        // Check if the player has won or lost
        if (board[player_x][player_y] == 2)
        {
            printf("You won!");
            break;
        }
        else if (board[player_x][player_y] == 3)
        {
            printf("You lost!");
            break;
        }
    }

    return 0;
}