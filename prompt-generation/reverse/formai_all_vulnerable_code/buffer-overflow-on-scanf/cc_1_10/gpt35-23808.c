//FormAI DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Configurable Variables
#define MAX_GUESSES 5
#define MAX_RANGE 50

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate random number between 1 and MAX_RANGE
    int numberToGuess = rand() % MAX_RANGE + 1;

    // Print welcome message
    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and %d.\n", MAX_RANGE);

    // Begin game loop
    int numGuesses = 0;
    while (numGuesses < MAX_GUESSES) {
        // Prompt user for guess
        printf("Guess #%d: ", numGuesses + 1);
        int guess;
        scanf("%d", &guess);

        // Check if guess was correct
        if (guess == numberToGuess) {
            printf("Congratulations! You guessed correctly.\n");
            break;
        } else if (guess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        // Increment guess counter
        numGuesses++;
    }

    // Check if user ran out of guesses
    if (numGuesses == MAX_GUESSES) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", numberToGuess);
    }

    // End game
    printf("Thanks for playing!\n");
    return 0;
}