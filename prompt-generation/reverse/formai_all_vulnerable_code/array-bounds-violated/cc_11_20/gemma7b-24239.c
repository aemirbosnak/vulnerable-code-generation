//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define the game world
    int map[5][5] = {{1, 1, 1, 0, 1},
                           {1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0},
                           {1, 1, 1, 1, 1}};

    // Player's position and direction
    int x = 0, y = 0, dir = 0;

    // Game loop
    while (!map[x][y] || dir != 3)
    {
        // Display the map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c ", map[i][j] ? ' ' : '.');
            }
            printf("\n");
        }

        // Get the player's input
        int input = getchar();

        // Move the player
        switch (input)
        {
            case 8:
                dir = 0;
                break;
            case 6:
                dir = 1;
                break;
            case 2:
                dir = 2;
                break;
            case 4:
                dir = 3;
                break;
        }

        // Check if the player has moved into a wall
        if (map[x][y] == 0)
        {
            // The player has moved into a wall, so they must change direction
            dir = (dir + 1) % 4;
        }

        // Move the player in the direction they chose
        switch (dir)
        {
            case 0:
                y--;
                break;
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
        }
    }

    // The player has reached the end of the game, so they win
    printf("You have won!");
}