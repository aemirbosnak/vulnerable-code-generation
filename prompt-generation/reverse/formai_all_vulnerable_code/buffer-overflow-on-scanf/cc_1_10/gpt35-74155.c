//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int randomNumber, guess, guessCount = 0;
    char playAgain = 'y';

    printf("Welcome to Guess-a-Number Game!\n");

    while (playAgain == 'y') {
        printf("\nI'm thinking of a number between 1 and 100... Can you guess it?\n");

        randomNumber = generateRandomNumber(1, 100);

        while (1) {
            printf("\nGuess a number: ");
            scanf("%d", &guess);

            guessCount++;

            if (guess == randomNumber) {
                printf("\nCongratulations! You guessed the number in %d tries.\n", guessCount);
                break;
            } 
            else if (guess < randomNumber) {
                printf("\nNo, the number I'm thinking of is higher than %d. Try again.\n", guess);
            } 
            else {
                printf("\nNo, the number I'm thinking of is lower than %d. Try again.\n", guess);
            }
        }

        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain != 'y' && playAgain != 'n') {
            printf("\nInvalid input. Goodbye!\n");
            return 1;
        }
        guessCount = 0;
    }

    printf("\nThanks for playing! Goodbye.\n");

    return 0;
}