//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game world
    int world[5][5] = {{1, 1, 1, 1, 1},
                            {1, 0, 0, 0, 1},
                            {1, 0, 0, 0, 1},
                            {1, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1}};

    // Define the player's position
    int x = 0;
    int y = 0;

    // Game loop
    while (1)
    {
        // Display the game world
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c ", world[i][j] == 0 ? '.' : 'X');
            }
            printf("\n");
        }

        // Get the player's move
        char move;
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &move);

        // Move the player
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

        // Check if the player has won or lost
        if (world[y][x] == 3)
        {
            printf("You have won!\n");
            break;
        }
        else if (world[y][x] == 2)
        {
            printf("You have lost.\n");
            break;
        }
    }

    return 0;
}