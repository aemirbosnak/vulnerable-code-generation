//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_NUMBERS 24

int main()
{
    // Create a bingo card with 5 rows and 5 columns
    int bingoCard[MAX_BINGO_NUMBERS] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Generate 20 random numbers
    for (int i = 0; i < MAX_BINGO_NUMBERS; i++)
    {
        bingoCard[i] = rand() % MAX_BINGO_NUMBERS + 1;
    }

    // Print the bingo card
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", bingoCard[i * 5 + j]);
        }
        printf("\n");
    }

    // Check if the player has won
    int hasWon = 0;
    for (int i = 0; i < 5; i++)
    {
        // Check if the player has won in a row
        for (int j = 0; j < 5; j++)
        {
            if (bingoCard[i * 5 + j] == bingoCard[i * 5] && bingoCard[i * 5 + j] != 0)
            {
                hasWon = 1;
            }
        }

        // Check if the player has won in a column
        for (int j = 0; j < 5; j++)
        {
            if (bingoCard[j] == bingoCard[j] && bingoCard[j] != 0)
            {
                hasWon = 1;
            }
        }
    }

    // If the player has won, print a congratulatory message
    if (hasWon)
    {
        printf("Congratulations! You have won!\n");
    }
    else
    {
        printf("Sorry, you have not won.\n");
    }

    return 0;
}