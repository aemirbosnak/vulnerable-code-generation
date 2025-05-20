//GPT-4o-mini DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5 // Maximum number of tries allowed

void playGame() {
    int numberToGuess, userGuess, tries = 0;
    // Generate random number between 1 and 100
    numberToGuess = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Challenge!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d tries to guess it. Good luck!\n", MAX_TRIES);

    while (tries < MAX_TRIES) {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);

        tries++;

        if (userGuess < 1 || userGuess > 100) {
            printf("Please guess a number between 1 and 100.\n");
            tries--; // Don't count invalid guess
            continue;
        }

        if (userGuess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else if (userGuess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d tries!\n", numberToGuess, tries);
            return;
        }
    }
    
    printf("Sorry! You've used all your tries. The number was %d.\n", numberToGuess);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char playAgain;

    do {
        playGame();
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Bye!\n");
    return 0;
}