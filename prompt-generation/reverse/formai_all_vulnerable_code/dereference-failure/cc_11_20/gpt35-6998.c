//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    printf("Welcome to the Bingo Simulator!\n\n");

    int cardsPlayed = 0; // Count of cards played
    int rowCount, columnCount; // Row and column count for card
    int minNumber, maxNumber; // Minimum and maximum number for card
    int currentNumber; // Current number being called
    int bingo = 0; // Flag for winner
    char playAgain; // Play again flag

    do {
        printf("Enter the number of rows for the card (between 3 and 10): ");
        scanf("%d", &rowCount);

        printf("Enter the number of columns for the card (between 3 and 10): ");
        scanf("%d", &columnCount);

        printf("Enter the minimum number for the card: ");
        scanf("%d", &minNumber);

        printf("Enter the maximum number for the card: ");
        scanf("%d", &maxNumber);

        srand(time(NULL)); // Initialize random number generator

        // Create card array dynamically
        int** card = (int**)malloc(rowCount * sizeof(int*));
        for (int i = 0; i < rowCount; i++) {
            card[i] = (int*)malloc(columnCount * sizeof(int));
        }

        // Fill card with random numbers
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                card[i][j] = generateRandomNumber(minNumber, maxNumber);
            }
        }

        // Print card
        printf("\nHere's your card:\n\n");
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                printf("%-4d", card[i][j]);
            }
            printf("\n");
        }

        // Play bingo
        printf("\nLet's play bingo!\n\n");
        do {
            // Generate random number
            currentNumber = generateRandomNumber(minNumber, maxNumber);
            printf("The number %d has been called!\n\n", currentNumber);

            // Check card for number
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < columnCount; j++) {
                    if (card[i][j] == currentNumber) {
                        card[i][j] = 0; // Mark number as called
                    }
                }
            }

            // Check for bingo
            int rowSum, columnSum, diagonalSum1 = 0, diagonalSum2 = 0;

            // Check rows
            for (int i = 0; i < rowCount; i++) {
                rowSum = 0;
                for (int j = 0; j < columnCount; j++) {
                    rowSum += card[i][j];
                }
                if (rowSum == 0) {
                    printf("Bingo! You won with a full row!\n");
                    bingo = 1;
                    break;
                }
            }

            if (bingo == 1) {
                break;
            }

            // Check columns
            for (int j = 0; j < columnCount; j++) {
                columnSum = 0;
                for (int i = 0; i < rowCount; i++) {
                    columnSum += card[i][j];
                }
                if (columnSum == 0) {
                    printf("Bingo! You won with a full column!\n");
                    bingo = 1;
                    break;
                }
            }

            if (bingo == 1) {
                break;
            }

            // Check diagonal 1
            for (int i = 0, j = 0; i < rowCount && j < columnCount; i++, j++) {
                diagonalSum1 += card[i][j];
            }
            if (diagonalSum1 == 0) {
                printf("Bingo! You won with a diagonal!\n");
                bingo = 1;
                break;
            }

            // Check diagonal 2
            for (int i = rowCount - 1, j = 0; i >= 0 && j < columnCount; i--, j++) {
                diagonalSum2 += card[i][j];
            }
            if (diagonalSum2 == 0) {
                printf("Bingo! You won with a diagonal!\n");
                bingo = 1;
                break;
            }

            // Increment card count
            cardsPlayed++;

        } while (bingo == 0);

        // Ask to play again
        printf("\nYou won after %d cards played! Want to play again? (y/n) ", cardsPlayed);
        scanf(" %c", &playAgain);

        // Reset variables for new game
        cardsPlayed = 0;
        bingo = 0;

        // Free dynamically allocated memory
        for (int i = 0; i < rowCount; i++) {
            free(card[i]);
        }
        free(card);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing Bingo!\n");

    return 0;
}