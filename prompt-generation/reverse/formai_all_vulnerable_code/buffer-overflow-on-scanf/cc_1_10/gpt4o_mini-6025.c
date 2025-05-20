//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

void displayInstructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess the number.\n", MAX_TRIES);
    printf("Good luck!\n\n");
}

int main() {
    int numberToGuess, userGuess, tries = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    printf("Do you want to play the Number Guessing Game? (y/n): ");
    scanf(" %c", &playAgain);

    while (playAgain == 'y' || playAgain == 'Y') {
        // Select a random number between 1 and 100
        numberToGuess = rand() % 100 + 1;

        // Display game instructions
        displayInstructions();

        // Start guessing loop
        while (tries < MAX_TRIES) {
            printf("Enter your guess (%d attempts left): ", MAX_TRIES - tries);
            scanf("%d", &userGuess);
            tries++;

            if (userGuess > numberToGuess) {
                printf("Too high! Try again.\n\n");
            } else if (userGuess < numberToGuess) {
                printf("Too low! Try again.\n\n");
            } else {
                printf("Congratulations! You guessed the number %d in %d tries!\n", numberToGuess, tries);
                break;
            }
        }

        if (tries == MAX_TRIES) {
            printf("Sorry! You've used all your attempts. The number was %d.\n", numberToGuess);
        }

        // Ask if the player wants to play again
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        tries = 0; // Reset tries for the next game
    }

    printf("Thank you for playing!\n");
    return 0;
}