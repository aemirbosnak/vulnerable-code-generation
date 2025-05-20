//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for a 5x5 matrix
    int **bingoCard = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        bingoCard[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the matrix with random numbers
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bingoCard[i][j] = rand() % 90 + 1;
        }
    }

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
    int won = 0;
    for (int i = 0; i < 5; i++)
    {
        // Check if the row has been completed
        for (int j = 0; j < 5; j++)
        {
            if (bingoCard[i][j] == 0)
            {
                won = 1;
            }
        }

        // Check if the column has been completed
        for (int j = 0; j < 5; j++)
        {
            int columnWon = 1;
            for (int k = 0; k < 5; k++)
            {
                if (bingoCard[k][j] != 0)
                {
                    columnWon = 0;
                }
            }
            if (columnWon)
            {
                won = 1;
            }
        }
    }

    // Print the winner's message
    if (won)
    {
        printf("You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    // Free the memory allocated for the bingo card
    for (int i = 0; i < 5; i++)
    {
        free(bingoCard[i]);
    }
    free(bingoCard);

    return 0;
}