//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for a 5x5 bingo card
    int **bingoCard = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        bingoCard[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the bingo card
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bingoCard[i][j] = 0;
        }
    }

    // Create a list of numbers to draw
    int numbersToDraw[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                           11, 12, 13, 14, 15, 16,
                           17, 18, 19, 20, 21, 22,
                           23, 24, 25, 26, 27, 28,
                           29, 30, 31, 32, 33, 34,
                           35, 36, 37, 38, 39, 40,
                           41, 42, 43, 44, 45, 46,
                           47, 48, 49, 50, 51, 52,
                           53, 54, 55, 56, 57, 58,
                           59, 60, 61, 62, 63, 64,
                           65, 66, 67, 68, 69, 70,
                           71, 72, 73, 74, 75, 76,
                           77, 78, 79, 80, 81, 82,
                           83, 84, 85, 86, 87, 88,
                           89, 90, 91, 92, 93, 94,
                           95, 96, 97, 98, 99, 100};

    // Draw the numbers
    for (int i = 0; i < 25; i++)
    {
        int numberDrawn = numbersToDraw[i];

        // Check if the number is on the bingo card
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (bingoCard[j][k] == numberDrawn)
                {
                    bingoCard[j][k] = -1;
                }
            }
        }

        // Print the number drawn
        printf("%d ", numberDrawn);
    }

    // Check if the player has won
    int won = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoCard[i][j] == -1)
            {
                won = 1;
            }
        }
    }

    // Print the winner
    if (won)
    {
        printf("\nCongratulations! You have won!");
    }

    // Free the memory allocated for the bingo card
    for (int i = 0; i < 5; i++)
    {
        free(bingoCard[i]);
    }
    free(bingoCard);

    return 0;
}