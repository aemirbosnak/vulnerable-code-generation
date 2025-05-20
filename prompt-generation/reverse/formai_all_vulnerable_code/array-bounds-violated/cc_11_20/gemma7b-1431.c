//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5
#define PLAYER_POS 0

int main()
{
    // Map definition
    int map[MAP_SIZE][MAP_SIZE] = {{0, 1, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0}};

    // Player position and direction
    int x = PLAYER_POS;
    int y = PLAYER_POS;
    int direction = 0;

    // Game loop
    while (1)
    {
        // Display the map
        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                printf("%c ", map[i][j] ? '#' : '.');
            }
            printf("\n");
        }

        // Move the player
        switch (direction)
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

        // Check if the player has reached the end of the map
        if (map[x][y] == 2)
        {
            printf("You won!");
            break;
        }

        // Check if the player has hit a wall
        if (map[x][y] == 1)
        {
            printf("Game over!");
            break;
        }

        // Update the player position
        map[x][y] = 2;

        // Sleep for a while
        sleep(1);
    }

    return 0;
}