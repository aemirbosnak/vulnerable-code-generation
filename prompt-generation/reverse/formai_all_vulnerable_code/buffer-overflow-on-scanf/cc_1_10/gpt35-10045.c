//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUMBERS 10

// Function to create random bingo card
void createCard(int card[][COLS])
{
    // Initialize the seed for random number generation
    srand(time(NULL));

    // Fill the card with random numbers in range 1-10
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            card[i][j] = rand() % NUMBERS + 1;
        }
    }
}

// Function to print the bingo card
void printCard(int card[][COLS])
{
    printf("BINGO CARD\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number exists in the card
int checkNumber(int card[][COLS], int num)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (card[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a row is complete
int checkRow(int card[][COLS], int row)
{
    for (int j = 0; j < COLS; j++)
    {
        if (card[row][j] != 0)
        {
            return 0;
        }
    }
    return 1;
}

// Function to check if a column is complete
int checkColumn(int card[][COLS], int col)
{
    for (int i = 0; i < ROWS; i++)
    {
        if (card[i][col] != 0)
        {
            return 0;
        }
    }
    return 1;
}

// Function to check if a diagonal is complete
int checkDiagonal(int card[][COLS], int diag)
{
    int i, j;
    if (diag == 1)
    {
        i = 0;
        j = 0;
        while (i < ROWS && j < COLS)
        {
            if (card[i][j] != 0)
            {
                return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
    else if (diag == 2)
    {
        i = ROWS - 1;
        j = 0;
        while (i >= 0 && j < COLS)
        {
            if (card[i][j] != 0)
            {
                return 0;
            }
            i--;
            j++;
        }
        return 1;
    }
    return 0;
}

int main()
{
    // Create the bingo card
    int card[ROWS][COLS];
    createCard(card);

    // Print the initial state of the bingo card
    printCard(card);

    // Initialize variables for number checking and win tracking
    int num, row, col, diag1 = 0, diag2 = 0, numCount = 0, win = 0;

    // Loop until the win condition is met
    while (win == 0)
    {
        // Get a number from the user
        printf("\nEnter a number between 1 and 10: ");
        scanf("%d", &num);

        // Check if the number exists in the card
        if (checkNumber(card, num) == 1)
        {
            // Mark the number as found in the card
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (card[i][j] == num)
                    {
                        card[i][j] = 0;
                        numCount++;
                        // Update win condition flags
                        if (checkRow(card, i) == 1 || checkColumn(card, j) == 1 || checkDiagonal(card, 1) == 1 || checkDiagonal(card, 2) == 1)
                        {
                            if (i == j)
                            {
                                diag1 = 1;
                            }
                            if (i + j == ROWS - 1)
                            {
                                diag2 = 1;
                            }
                        }
                    }
                }
            }
            // Print the updated state of the card
            printCard(card);
            // Check for win condition
            if (numCount >= 3 && (checkRow(card, 0) == 1 || checkRow(card, 1) == 1 || checkRow(card, 2) == 1 || checkColumn(card, 0) == 1 || checkColumn(card, 1) == 1 || checkColumn(card, 2) == 1 || diag1 == 1 || diag2 == 1))
            {
                win = 1;
            }
        }
        else
        {
            printf("\nThat number is not on the card. Please enter a different number.\n");
        }
    }

    // Print congratulations message
    printf("\nCongratulations, you've won!\n");

    return 0;
}