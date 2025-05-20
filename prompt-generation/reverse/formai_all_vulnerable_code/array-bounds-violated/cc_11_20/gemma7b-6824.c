//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    // Game loop
    while (board[player_x][player_y] != 1)
    {
        // Display the board
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                printf("%c ", board[x][y] ? '#' : '.');
            }
            printf("\n");
        }

        // Get the direction
        direction = getchar();

        // Move the player
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

        // Check if the player has won or lost
        if (board[player_x][player_y] == 1)
        {
            printf("You won!");
        }
        else if (board[player_x][player_y] == 2)
        {
            printf("You lost!");
        }
    }

    return 0;
}