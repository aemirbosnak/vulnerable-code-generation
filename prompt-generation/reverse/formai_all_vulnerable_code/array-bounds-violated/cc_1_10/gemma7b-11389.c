//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

int main()
{
    int i, j, k, num, bingo, card[MAX_NUM][MAX_NUM], draw[MAX_NUM];
    srand(time(NULL));

    // Create a bingo card
    for (i = 0; i < MAX_NUM; i++)
    {
        for (j = 0; j < MAX_NUM; j++)
        {
            card[i][j] = -1;
        }
    }

    // Fill the card with numbers
    for (i = 0; i < MAX_NUM; i++)
    {
        for (j = 0; j < MAX_NUM; j++)
        {
            card[i][j] = rand() % MAX_NUM + 1;
        }
    }

    // Draw the numbers
    for (k = 0; k < MAX_NUM; k++)
    {
        draw[k] = rand() % MAX_NUM + 1;
    }

    // Check for bingo
    for (i = 0; i < MAX_NUM; i++)
    {
        for (j = 0; j < MAX_NUM; j++)
        {
            if (card[i][j] == draw[k])
            {
                bingo = 1;
            }
        }
    }

    // Print the results
    if (bingo)
    {
        printf("Bingo!\n");
    }
    else
    {
        printf("No bingo.\n");
    }

    return 0;
}