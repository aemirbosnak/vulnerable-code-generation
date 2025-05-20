//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the galaxy map
    int galaxy_map[10][10] = {
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    // Initialize the player's position
    int x = 0;
    int y = 0;

    // Display the galaxy map
    system("clear");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (galaxy_map[i][j] == 1)
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

    // Move the player
    char direction;

    // Loop until the player decides to quit
    while (direction != 'q')
    {
        // Get the player's direction
        printf("Enter direction (w, a, s, d, q): ");
        scanf(" %c", &direction);

        // Move the player
        switch (direction)
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
            case 'q':
                printf("Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid direction.\n");
                break;
        }

        // Display the updated galaxy map
        system("clear");
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (galaxy_map[i][j] == 1)
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
    }

    return 0;
}