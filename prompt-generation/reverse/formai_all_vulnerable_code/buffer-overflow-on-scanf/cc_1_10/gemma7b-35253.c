//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Magical Forest!\n");
    printf("------------------------\n");

    // Create a forest map
    char forest[5][5] = {
        {'F', 'F', 'F', 'F', 'F'},
        {'F', 'T', 'F', 'F', 'F'},
        {'F', 'T', 'T', 'F', 'F'},
        {'F', 'T', 'T', 'T', 'F'},
        {'F', 'F', 'F', 'F', 'F'}
    };

    // Player's position
    int x = 0;
    int y = 0;

    // Game loop
    while (1)
    {
        // Draw the forest
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c ", forest[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        char move;
        printf("Enter your move (W, A, S, D): ");
        scanf("%c", &move);

        // Move the player
        switch (move)
        {
            case 'W':
                y--;
                break;
            case 'A':
                x--;
                break;
            case 'S':
                y++;
                break;
            case 'D':
                x++;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check if the player has won or lost
        if (forest[y][x] == 'T')
        {
            printf("You have won!\n");
            break;
        }
        else if (forest[y][x] == 'O')
        {
            printf("You have lost.\n");
            break;
        }
    }

    return 0;
}