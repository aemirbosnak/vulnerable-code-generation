//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game world
    int map[5][5] = {{1, 1, 1, 1, 0},
                           {1, 1, 1, 0, 0},
                           {1, 1, 0, 0, 0},
                           {1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0}};

    // Create the hero
    int hero_x = 0;
    int hero_y = 0;

    // Start the game
    while (1)
    {
        // Display the game world
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (map[y][x] == 1)
                {
                    printf("%c ", '#');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Get the hero's move
        int move = getchar();

        // Move the hero
        switch (move)
        {
            case 'w':
                hero_y--;
                break;
            case 'a':
                hero_x--;
                break;
            case 's':
                hero_y++;
                break;
            case 'd':
                hero_x++;
                break;
        }

        // Check if the hero has won or lost
        if (map[hero_y][hero_x] == 0)
        {
            printf("You have won!");
            break;
        }
        else if (map[hero_y][hero_x] == 2)
        {
            printf("You have lost!");
            break;
        }
    }

    return 0;
}