//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    printf("Welcome to the Crystal Cave, traveler.\n");
    printf("You wake up in a dim and mysterious cave. The only sound is your breathing and the faintest echo of your footsteps.\n");

    // Create a 2D array to represent the cave map
    int caveMap[5][5] = {{0, 1, 1, 0, 0},
                            {1, 1, 1, 1, 0},
                            {1, 0, 0, 1, 0},
                            {0, 1, 1, 1, 0},
                            {0, 0, 0, 0, 1}};

    // Player's position in the cave
    int x = 0, y = 0;

    // Loop until the player finds the treasure
    while (caveMap[x][y] != 2)
    {
        // Get the player's input
        char input;
        printf("What direction do you want to go (N, S, E, W)? ");
        scanf(" %c", &input);

        // Move the player
        switch (input)
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
                printf("Invalid input.\n");
                break;
        }

        // Print the cave map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (caveMap[i][j] == 1)
                {
                    printf("X ");
                }
                else if (caveMap[i][j] == 2)
                {
                    printf("T ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }

        // Check if the player has found the treasure
        if (caveMap[x][y] == 2)
        {
            printf("Congratulations! You have found the treasure!\n");
        }
    }

    return 0;
}