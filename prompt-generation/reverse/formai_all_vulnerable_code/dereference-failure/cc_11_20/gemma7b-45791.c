//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALLS 10
#define MAX_ROWS 5
#define MAX_COLS 5

int main()
{
    // Create a bingo card
    int **card = (int *)malloc(MAX_ROWS * MAX_COLS * sizeof(int));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            card[r][c] = 0;
        }
    }

    // Generate balls
    int balls[MAX_BALLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Draw balls
    for (int i = 0; i < MAX_BALLS; i++)
    {
        int number = balls[i];

        // Mark the ball on the card
        for (int r = 0; r < MAX_ROWS; r++)
        {
            for (int c = 0; c < MAX_COLS; c++)
            {
                if (card[r][c] == number)
                {
                    card[r][c] = -1;
                }
            }
        }

        // Print the ball
        printf("%d ", number);
    }

    // Check if the player has won
    int winner = 0;
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            if (card[r][c] == -1)
            {
                winner = 1;
            }
        }
    }

    // Print the winner
    if (winner)
    {
        printf("Winner!");
    }

    // Free the memory
    free(card);

    return 0;
}