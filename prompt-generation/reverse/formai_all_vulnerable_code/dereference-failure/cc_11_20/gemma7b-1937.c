//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, bingo_number, count = 0, winner = 0;
    char **bingo_card = NULL;
    printf("Grateful Bingo Simulator!\n");
    bingo_card = (char**)malloc(25 * sizeof(char*));
    for(i = 0; i < 5; i++)
    {
        bingo_card[i] = (char*)malloc(5 * sizeof(char));
    }

    // Generate Bingo Numbers
    for(k = 0; k < 10; k++)
    {
        bingo_number = rand() % 90 + 1;
        for(l = 0; l < 5; l++)
        {
            for(i = 0; i < 5; i++)
            {
                if(bingo_card[l][i] == bingo_number)
                {
                    bingo_card[l][i] = 'B';
                }
            }
        }
    }

    // Check for Bingo
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(bingo_card[i][j] == 'B')
            {
                count++;
            }
        }
        if(count == 5)
        {
            winner = 1;
            break;
        }
        count = 0;
    }

    // Print Winner
    if(winner)
    {
        printf("Congratulations, you won!\n");
    }
    else
    {
        printf("Sorry, no winner.\n");
    }

    return 0;
}