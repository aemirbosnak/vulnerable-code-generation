//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game map
    char map[2][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}};

    // Initialize the player's position
    int x = 0, y = 0;

    // Game loop
    while (1)
    {
        // Display the map
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &input);

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
                printf("Invalid move.\n");
                break;
        }

        // Check if the player has won or lost
        if (map[x][y] == 'F')
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

    return 0;
}