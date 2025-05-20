//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Create a bingo card
    int bingo_card[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Generate the bingo numbers
    for (int i = 0; i < 20; i++)
    {
        int number = rand() % 25 + 1;

        // Mark the number on the bingo card
        bingo_card[number / 5][number % 5] = 1;
    }

    // Check if the player has won
    int won = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingo_card[i][j] == 5)
            {
                won = 1;
            }
        }
    }

    // Print the results
    if (won)
    {
        printf("You have won!\n");
    }
    else
    {
        printf("Sorry, you have not won.\n");
    }

    return 0;
}