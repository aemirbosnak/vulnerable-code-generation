//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the map of the dungeon.
    char map[4][4] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P'}
    };

    // Get the player's input.
    char input;

    // Initialize the player's position.
    int x = 0;
    int y = 0;

    // Loop until the player enters 'Q'.
    while (input != 'Q')
    {
        // Print the map.
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's input.
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &input);

        // Move the player.
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
                break;
        }

        // Check if the player has reached the end of the dungeon.
        if (map[x][y] == 'P')
        {
            printf("You have reached the end of the dungeon!");
            break;
        }
    }

    return 0;
}