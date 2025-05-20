//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define the adventure map
    char map[4][4] = {{'A', 'B', 'C', 'D'},
                           {'E', 'F', 'G', 'H'},
                           {'I', 'J', 'K', 'L'},
                           {'M', 'N', 'O', 'P'}};

    // Initialize the player's position
    int x = 0, y = 0;

    // Loop until the player wins or loses
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

        // Validate the move
        if (move != 'W' && move != 'S' && move != 'E' && move != 'N')
        {
            printf("Invalid move.\n");
            continue;
        }

        // Move the player
        switch (move)
        {
            case 'W':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'N':
                x--;
                break;
        }

        // Check if the player has won or lost
        if (map[x][y] == 'P')
        {
            printf("You have won!\n");
            break;
        }
        else if (map[x][y] == 'O')
        {
            printf("You have lost.\n");
            break;
        }
    }

    return;
}