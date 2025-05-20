//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the hero's name
    char hero_name[20];

    // Get the hero's name from the user
    printf("What is your hero's name? ");
    scanf("%s", hero_name);

    // Create a map of the adventure world
    int map[10][10] = {{0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Define the adventure path
    int x = 0, y = 0;

    // Start the adventure
    while (1)
    {
        // Display the map
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("%c ", '*');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Get the hero's move
        printf("What direction do you want to go (N, S, E, W)? ");
        char move;
        scanf(" %c", &move);

        // Move the hero
        switch (move)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check if the hero has reached the end of the adventure
        if (map[x][y] == 2)
        {
            printf("Congratulations, %s! You have completed the adventure!\n", hero_name);
            break;
        }

        // Check if the hero has stumbled upon a trap
        if (map[x][y] == 3)
        {
            printf("Oh no, %s! You have triggered a trap!\n", hero_name);
            break;
        }
    }

    return 0;
}