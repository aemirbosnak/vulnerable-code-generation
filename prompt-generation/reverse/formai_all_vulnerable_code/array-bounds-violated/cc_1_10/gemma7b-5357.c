//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define a Bingo card with 5 columns and 5 rows
    int bingoCard[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Generate a random number between 1 and 25
    int randomNumber = rand() % 25 + 1;

    // Mark the number on the bingo card
    bingoCard[randomNumber / 5][randomNumber % 5] = 1;

    // Print the bingo card
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", bingoCard[i][j]);
        }
        printf("\n");
    }

    // Check if the player has won
    int hasWon = 0;
    for (int i = 0; i < 5; i++)
    {
        // Check if the row has won
        for (int j = 0; j < 5; j++)
        {
            if (bingoCard[i][j] == 1)
            {
                hasWon = 1;
            }
        }

        // Check if the column has won
        for (int j = 0; j < 5; j++)
        {
            if (bingoCard[j][i] == 1)
            {
                hasWon = 1;
            }
        }
    }

    // If the player has won, print a winning message
    if (hasWon)
    {
        printf("You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return;
}