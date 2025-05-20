//GPT-4o-mini DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5
#define MAX_NUM 100

void printInstructions() {
    printf("**********************************\n");
    printf("Welcome to the Guess the Number Game!\n");
    printf("**********************************\n");
    printf("You will have %d tries to guess a number between 1 and %d.\n", MAX_TRIES, MAX_NUM);
    printf("Can you outsmart the computer? Let's find out!\n");
    printf("**********************************\n");
}

int main() {
    int secretNumber, guess, tries = 0;
    char playAgain = 'y';
    
    // Seed the random number generator
    srand(time(0));

    while (playAgain == 'y') {
        secretNumber = rand() % MAX_NUM + 1; // Generate a secret number between 1 and MAX_NUM
        tries = 0;
        printf("\nA new number has been generated. Start guessing!\n");

        while (tries < MAX_TRIES) {
            printf("Enter your guess (%d tries left): ", MAX_TRIES - tries);
            scanf("%d", &guess);
            tries++;

            if (guess < 1 || guess > MAX_NUM) {
                printf("Please guess a number between 1 and %d.\n", MAX_NUM);
                tries--; // Do not count this try
                continue;
            }

            if (guess < secretNumber) {
                printf("Too low! Try again.\n");
            } else if (guess > secretNumber) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You've guessed the number %d in %d tries!\n", secretNumber, tries);
                break;
            }
        }

        if (tries == MAX_TRIES) {
            printf("Sorry, you've run out of tries! The secret number was %d.\n", secretNumber);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        playAgain = tolower(playAgain); // Convert to lowercase for easier comparison
    }

    printf("Thank you for playing! Have a great day!\n");
    return 0;
}