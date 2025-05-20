//GPT-4o-mini DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printInstructions() {
    printf("Welcome to 'Guess the Number'!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Your task is to guess the number.\n");
    printf("I will give you hints if your guess is too high or too low.\n");
    printf("You can exit the game at any time by entering -1.\n");
    printf("Let's begin!\n\n");
}

int main() {
    int numberToGuess, playerGuess;
    int attempts = 0;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    numberToGuess = rand() % 100 + 1;

    // Print game instructions
    printInstructions();

    // Main game loop
    while (1) {
        printf("Enter your guess (1-100 or -1 to exit): ");
        scanf("%d", &playerGuess);

        // Check for exit condition
        if (playerGuess == -1) {
            printf("Thank you for playing! The number was %d.\n", numberToGuess);
            break;
        }

        // Validate player input
        if (playerGuess < 1 || playerGuess > 100) {
            printf("Please enter a valid number between 1 and 100.\n");
            continue;
        }

        attempts++;

        // Check the guess
        if (playerGuess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else if (playerGuess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts!\n", numberToGuess, attempts);
            break;
        }
    }

    return 0;
}