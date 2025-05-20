//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Magical Forest!\n");

    // Create a 2D array to store the forest map
    int forest[5][5] = {{1, 1, 1, 0, 0},
                              {1, 1, 1, 1, 1},
                              {1, 1, 0, 1, 1},
                              {1, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0}};

    // Player's position in the forest
    int x = 0, y = 0;

    // Game loop
    while (1)
    {
        // Display the forest map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (forest[i][j] == 1)
                {
                    printf("+---+ ");
                }
                else
                {
                    printf("   ");
                }
            }
            printf("\n");
        }

        // Get the player's input
        char input;

        // Move the player
        switch (input)
        {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the player has reached the end of the forest
        if (forest[x][y] == 0)
        {
            printf("Congratulations! You have reached the end of the forest.\n");
            break;
        }

        // Check if the player has walked off the map
        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            printf("Oops! You have walked off the map.\n");
            break;
        }
    }

    return 0;
}