//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

int main()
{
    time_t t;
    srand(time(&t));

    // Create the bingo card
    int **card = (int *)malloc(NUM_ROWS * sizeof(int *));
    for (int i = 0; i < NUM_ROWS; i++)
    {
        card[i] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int j = 0; j < NUM_COLS; j++)
        {
            card[i][j] = 0;
        }
    }

    // Populate the bingo card
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            card[i][j] = rand() % 90 + 1;
        }
    }

    // Print the bingo card
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }

    // Check for bingo
    int bingo = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (card[i][j] == card[0][0])
            {
                bingo = 1;
            }
        }
    }

    // Print the winner
    if (bingo)
    {
        printf("You won!");
    }
    else
    {
        printf("Sorry, you lost.");
    }

    // Free the memory
    for (int i = 0; i < NUM_ROWS; i++)
    {
        free(card[i]);
    }
    free(card);

    return 0;
}