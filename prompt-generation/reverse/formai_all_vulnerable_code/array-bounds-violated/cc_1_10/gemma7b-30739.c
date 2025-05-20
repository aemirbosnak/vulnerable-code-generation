//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define the game map
    char map[4][4] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P'}
    };

    // Initialize the player's position
    int x = 0;
    int y = 0;

    // Game loop
    while (1)
    {
        // Display the map
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c ", map[i][j]);
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
        if (map[y][x] == 'P')
        {
            printf("You win!\n");
            break;
        }
        else if (map[y][x] == 'O')
        {
            printf("You lose!\n");
            break;
        }
    }

    // End the game
    return;
}