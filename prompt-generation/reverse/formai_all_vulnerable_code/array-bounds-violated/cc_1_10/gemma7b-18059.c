//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a magical garden
    char garden[10][10] = {
        {'G', 'T', 'R', 'O', 'W', 'S', 'S', 'M', 'E', 'R', 'N'},
        {'N', 'A', 'L', 'L', 'R', 'O', 'W', 'A', 'Y', 'L', 'M'},
        {'R', 'E', 'H', 'T', 'A', 'N', 'R', 'E', 'A', 'R', 'T'},
        {'A', 'N', 'A', 'T', 'R', 'E', 'H', 'A', 'N', 'R', 'A'},
        {'R', 'O', 'W', 'A', 'R', 'E', 'H', 'T', 'R', 'N', 'T'},
        {'S', 'E', 'C', 'R', 'E', 'T', 'M', 'A', 'R', 'N', 'A'},
        {'S', 'M', 'A', 'R', 'N', 'H', 'A', 'R', 'T', 'A', 'L'},
        {'M', 'E', 'R', 'A', 'N', 'H', 'A', 'R', 'S', 'S', 'T'},
        {'E', 'R', 'A', 'T', 'R', 'N', 'A', 'R', 'T', 'A', 'S'},
        {'N', 'R', 'A', 'S', 'M', 'A', 'R', 'N', 'S', 'E', 'R'}
    };

    // Player's position
    int x = 0;
    int y = 0;

    // Inventory
    char inventory[5] = {0};

    // Game loop
    int game_over = 0;
    while (!game_over)
    {
        // Display the garden
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", garden[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input[20];
        printf("Enter your move (N/S/E/W): ");
        scanf("%s", input);

        // Move the player
        switch (input[0])
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
        if (garden[y][x] == 'M')
        {
            game_over = 1;
            printf("You have won!");
        }
        else if (garden[y][x] == 'R')
        {
            game_over = 1;
            printf("You have lost!");
        }
    }

    return 0;
}