//Gemma-7B DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a simple C table game
    int table[5][5] = {{0, 1, 0, 1, 0},
                           {1, 0, 1, 0, 1},
                           {0, 1, 0, 1, 0},
                           {1, 0, 1, 0, 1},
                           {0, 1, 0, 1, 0}};

    // Print the table
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // Play the game
    int move = 0;
    while (move < 25)
    {
        // Get the move
        printf("Enter your move (1-25): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 25)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        table[move/5][move%5] = 1;

        // Print the updated table
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }

        // Check if the player has won
        if (table[4][4] == 1)
        {
            printf("You have won!\n");
            break;
        }
    }

    // End of the game
    return 0;
}