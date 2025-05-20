//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rows, cols, num, min, max, i, j;

    printf("Welcome to the Bingo Simulator!\n");

    printf("Please enter the number of rows in your bingo card: ");
    scanf("%d", &rows);

    printf("Please enter the number of columns in your bingo card: ");
    scanf("%d", &cols);

    printf("Please enter the minimum number for your bingo card: ");
    scanf("%d", &min);

    printf("Please enter the maximum number for your bingo card: ");
    scanf("%d", &max);

    int bingoCard[rows][cols];

    srand(time(0)); // Seed random number generator with current time

    // Initialize bingo card array with random numbers in range
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            num = rand() % (max - min + 1) + min;
            bingoCard[i][j] = num;
        }
    }

    // Print out bingo card
    printf("\nYour Bingo Card:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", bingoCard[i][j]);
        }
        printf("\n");
    }

    printf("\nLet's play the game!\n");

    int callNum, matchCount, bingoCount;
    int calledNums[rows*cols]; // Array to keep track of called numbers
    bingoCount = 0; // Initialize number of bingos to 0

    // Keep calling numbers until someone gets a bingo
    while(bingoCount == 0)
    {
        matchCount = 0; // Initialize match count for each new number called

        // Generate new random number that hasn't been called yet
        do
        {
            num = rand() % (max - min + 1) + min;
            matchCount = 0; // Reset match count for each number tested
            for(i = 0; i < rows*cols; i++)
            {
                if(calledNums[i] == num)
                {
                    matchCount++; // Increment match count if number has already been called
                }
            }
        } while(matchCount > 0);

        // Add new called number to calledNums array
        for(i = 0; i < rows*cols; i++)
        {
            if(calledNums[i] == 0)
            {
                calledNums[i] = num;
                break;
            }
        }

        // Print out called number
        printf("\nNumber called: %d\n", num);

        // Check if called number matches any on bingo card
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(bingoCard[i][j] == num)
                {
                    bingoCard[i][j] = 0; // Mark number as called on bingo card
                }
            }
        }

        // Check for bingo
        for(i = 0; i < rows; i++)
        {
            matchCount = 0; // Reset match count for each row/column/diagonal
            for(j = 0; j < cols; j++)
            {
                if(bingoCard[i][j] == 0)
                {
                    matchCount++;
                }
            }
            if(matchCount == cols)
            {
                bingoCount++;
                printf("\nBINGO! Row %d\n", i+1);
            }
        }

        for(j = 0; j < cols; j++)
        {
            matchCount = 0; // Reset match count for each row/column/diagonal
            for(i = 0; i < rows; i++)
            {
                if(bingoCard[i][j] == 0)
                {
                    matchCount++;
                }
            }
            if(matchCount == rows)
            {
                bingoCount++;
                printf("\nBINGO! Column %d\n", j+1);
            }
        }

        matchCount = 0; // Reset match count for each row/column/diagonal
        for(i = 0, j = 0; i < rows && j < cols; i++, j++)
        {
            if(bingoCard[i][j] == 0)
            {
                matchCount++;
            }
        }
        if(matchCount == rows)
        {
            bingoCount++;
            printf("\nBINGO! Diagonal (top left to bottom right)\n");
        }

        matchCount = 0; // Reset match count for each row/column/diagonal
        for(i = 0, j = cols-1; i < rows && j >= 0; i++, j--)
        {
            if(bingoCard[i][j] == 0)
            {
                matchCount++;
            }
        }
        if(matchCount == rows)
        {
            bingoCount++;
            printf("\nBINGO! Diagonal (top right to bottom left)\n");
        }
    }

    printf("\nCongratulations, someone got a bingo!\n");

    return 0;
}