//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 75
int generateRandomNumber()
{
    int num = rand() % 75 + 1;
    return num;
}

// Function to check if a number is in a given array
int checkIfNumberExists(int arr[], int num, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Main function
int main()
{
    int bingoCard[5][5]; // 5x5 array to store every player's card
    int calledNumbers[75] = {0}; // Array to store all the numbers that have been called so far
    int numCalled = 0; // Count of the number of numbers that have been called so far
    int winnerFound = 0; // Flag to indicate if a winner has been found
    int numPlayers; // Number of players in the game

    // Prompt user to enter number of players
    printf("How many players are in the game?");
    scanf("%d", &numPlayers);

    // Loop through every player's card and generate their unique card
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Card for player %d: \n", i+1);

        // Initialize the card with zeros
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                bingoCard[row][col] = 0;
            }
        }

        // Loop through each column of the card and fill it with unique numbers
        for (int col = 0; col < 5; col++)
        {
            int numsOnCard[15] = {0}; // Array to track what numbers are on the current column

            // Fill in the current column with unique numbers
            for (int row = 0; row < 5; row++)
            {
                int numExists = 1;
                int numToAdd = 0;

                // Keep generating numbers until a unique one is found for the current cell in the array
                while (numExists == 1)
                {
                    numToAdd = generateRandomNumber();

                    if (checkIfNumberExists(numsOnCard, numToAdd, 15) == 0)
                    {
                        numExists = 0;
                        numsOnCard[row] = numToAdd; // Add the number to the array that tracks this column's nums
                    }
                }

                if (row == 2 && col == 2)
                {
                    bingoCard[row][col] = 0; // Set the center cell to be zero for all cards
                }
                else
                {
                    bingoCard[row][col] = numToAdd; // Add the number to the current cell in the card
                }
            }
        }

        // Print out each player's card
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                printf("%d\t", bingoCard[row][col]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Game loop begins
    while (winnerFound == 0)
    {
        int numToCall = generateRandomNumber();

        // Check if the number has already been called
        while (checkIfNumberExists(calledNumbers, numToCall, numCalled) == 1)
        {
            numToCall = generateRandomNumber();
        }

        calledNumbers[numCalled] = numToCall; // Add the number to the called numbers array
        numCalled++; // Increment the count of called numbers

        // Print out the called number and the array of called numbers so far
        printf("The number called is: %d\n", numToCall);
        printf("Numbers called so far: ");
        for (int i = 0; i < numCalled; i++)
        {
            printf("%d ", calledNumbers[i]);
        }
        printf("\n");

        // Loop through each player's card to check if the called number exists on their card
        for (int i = 0; i < numPlayers; i++)
        {
            int hasNumber = 0;

            for (int row = 0; row < 5; row++)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (bingoCard[row][col] == numToCall)
                    {
                        hasNumber = 1;
                        bingoCard[row][col] = 0; // Replace the called number with a zero on the card
                    }
                }
            }

            // Check if the player has won by having all numbers in a row, column, or diagonal equal to zero
            int rowSum, colSum, diagSum, antiDiagSum;
            rowSum = colSum = diagSum = antiDiagSum = 0;

            // Check rows
            for (int row = 0; row < 5; row++)
            {
                rowSum = bingoCard[row][0] + bingoCard[row][1] + bingoCard[row][2] + bingoCard[row][3] + bingoCard[row][4];
                if (rowSum == 0)
                {
                    winnerFound = 1;
                }
            }

            // Check columns
            for (int col = 0; col < 5; col++)
            {
                colSum = bingoCard[0][col] + bingoCard[1][col] + bingoCard[2][col] + bingoCard[3][col] + bingoCard[4][col];
                if (colSum == 0)
                {
                    winnerFound = 1;
                }
            }

            // Check diagonals
            diagSum = bingoCard[0][0] + bingoCard[1][1] + bingoCard[2][2] + bingoCard[3][3] + bingoCard[4][4];
            if (diagSum == 0)
            {
                winnerFound = 1;
            }
            antiDiagSum = bingoCard[0][4] + bingoCard[1][3] + bingoCard[2][2] + bingoCard[3][1] + bingoCard[4][0];
            if (antiDiagSum == 0)
            {
                winnerFound = 1;
            }

            // Print out a message if the player has won
            if (winnerFound == 1)
            {
                printf("Player %d has won!\n", i+1);
                break;
            }
        }
    }

    return 0;
}