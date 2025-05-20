//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int tableSize, maxNumber, guess, correctGuesses = 0, totalGuesses = 0;
    char playAgain = 'Y';
    srand(time(0));

    // Prompt for table size
    printf("Enter the size of the table (minimum 2, maximum 20): ");
    scanf("%d", &tableSize);
    while (tableSize < 2 || tableSize > 20) {
        printf("Invalid table size. Please enter a value between 2 and 20: ");
        scanf("%d", &tableSize);
    }

    // Prompt for maximum number
    printf("\nEnter the maximum number to guess (minimum %d, maximum %d): ", tableSize + 1, 100);
    scanf("%d", &maxNumber);
    while (maxNumber < tableSize + 1 || maxNumber > 100) {
        printf("Invalid number. Please enter a value between %d and 100: ", tableSize + 1);
        scanf("%d", &maxNumber);
    }

    // Play game loop
    while (playAgain == 'Y' || playAgain == 'y') {
        int table[tableSize][tableSize];
        int i, j, randomNumber;
        correctGuesses = 0;
        totalGuesses = 0;

        // Generate table numbers and display table
        printf("\nTable numbers:\n");
        for (i = 0; i < tableSize; i++) {
            for (j = 0; j < tableSize; j++) {
                randomNumber = rand() % (maxNumber - tableSize + 1) + tableSize;
                table[i][j] = randomNumber;
                printf("%-5d", table[i][j]);
            }
            printf("\n");
        }

        // Guess number loop
        while (correctGuesses < tableSize * tableSize) {
            printf("\nEnter a number from the table: ");
            scanf("%d", &guess);
            
            // Check if guess is in table
            int found = 0;
            for (i = 0; i < tableSize; i++) {
                for (j = 0; j < tableSize; j++) {
                    if (table[i][j] == guess) {
                        found = 1;
                        table[i][j] = -1;
                        correctGuesses++;
                        break;
                    }
                }
            }

            if (found) {
                printf("Correct guess! ");
            }
            else {
                printf("Incorrect guess. ");
            }

            totalGuesses++;
            printf("You have made %d correct guesses out of %d total guesses.\n", correctGuesses, totalGuesses);
        }

        // Game over
        printf("\nCongratulations! You have guessed all the numbers in the table in %d guesses.\n", totalGuesses);
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
    }

    printf("\nThanks for playing! Goodbye.\n");
    return 0;
}