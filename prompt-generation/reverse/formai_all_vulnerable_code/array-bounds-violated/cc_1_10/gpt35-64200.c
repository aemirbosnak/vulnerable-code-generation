//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void initializeCard(int card[][COLS]);
void printCard(int card[][COLS]);
void generateCall(int calledNumbers[]);
void markNumber(int card[][COLS], int number);
int checkBingo(int card[][COLS]);

int main()
{
    int card[ROWS][COLS];
    int calledNumbers[MAX_NUM];
    int numCalls = 0;
    int bingo = 0;

    // Initialize the card and print it
    initializeCard(card);
    printf("BINGO CARD:\n");
    printCard(card);

    // Start calling numbers until there is a bingo
    while (!bingo)
    {
        int call = 0;

        // Generate the next number to call
        generateCall(calledNumbers);
        numCalls++;

        // Mark the number on the card and print the updated card
        markNumber(card, calledNumbers[numCalls-1]);
        printf("CALL #%d: %d\n", numCalls, calledNumbers[numCalls-1]);
        printCard(card);

        // Check for bingo
        bingo = checkBingo(card);
        if (bingo)
        {
            printf("BINGO! It took %d calls.\n", numCalls);
        }
    }

    return 0;
}

// Initializes the bingo card with randomized numbers
void initializeCard(int card[][COLS])
{
    int i, j;
    int usedNumbers[MAX_NUM] = {0};
    srand(time(NULL));

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            int num;

            // Generate a unique number for this space
            do
            {
                num = rand() % MAX_NUM + 1;
            } while (usedNumbers[num]);

            usedNumbers[num] = 1;
            card[i][j] = num;
        }
    }

    // Mark the free space as already called
    card[2][2] = -1;
}

// Prints out the current state of the card
void printCard(int card[][COLS])
{
    int i, j;

    printf("-----\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                printf("| F ");
            }
            else
            {
                printf("| %2d", card[i][j]);
            }
        }
        printf("|\n");
        printf("-----\n");
    }
}

// Generates the next number to call
void generateCall(int calledNumbers[])
{
    int num;

    // Generate a unique number that hasn't been called yet
    do
    {
        num = rand() % MAX_NUM + 1;
    } while (calledNumbers[num]);

    calledNumbers[num] = 1;
}

// Marks the called number on the bingo card
void markNumber(int card[][COLS], int number)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (card[i][j] == number)
            {
                card[i][j] = -1;
            }
        }
    }
}

// Checks if a bingo has occurred
int checkBingo(int card[][COLS])
{
    int i, j;
    int bingo = 0;

    // Check for horizontal bingos
    for (i = 0; i < ROWS; i++)
    {
        int rowBingo = 1;

        for (j = 0; j < COLS; j++)
        {
            if (card[i][j] != -1)
            {
                rowBingo = 0;
                break;
            }
        }

        if (rowBingo)
        {
            bingo = 1;
            break;
        }
    }

    // Check for vertical bingos
    if (!bingo)
    {
        for (i = 0; i < COLS; i++)
        {
            int colBingo = 1;

            for (j = 0; j < ROWS; j++)
            {
                if (card[j][i] != -1)
                {
                    colBingo = 0;
                    break;
                }
            }

            if (colBingo)
            {
                bingo = 1;
                break;
            }
        }
    }

    // Check for diagonal bingos
    if (!bingo)
    {
        int diagBingo1 = 1;
        int diagBingo2 = 1;

        for (i = 0; i < ROWS; i++)
        {
            if (card[i][i] != -1)
            {
                diagBingo1 = 0;
            }

            if (card[i][COLS-i-1] != -1)
            {
                diagBingo2 = 0;
            }
        }

        if (diagBingo1 || diagBingo2)
        {
            bingo = 1;
        }
    }

    return bingo;
}