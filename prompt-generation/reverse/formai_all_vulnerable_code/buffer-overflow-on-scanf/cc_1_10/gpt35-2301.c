//FormAI DATASET v1.0 Category: Random ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare a function to generate a random integer between two given values
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Declare variables for the minimum and maximum values of the range
    int minRange = 1;
    int maxRange = 10;

    // Declare a variable to hold the user's guess
    int guess;

    // Declare a variable to hold the number of attempts
    int attempts = 0;

    // Generate a random number between the minimum and maximum values
    int random = randomInt(minRange, maxRange);

    printf("Welcome to the Random Number Guessing Game!\n\n");
    printf("I'm thinking of a number between %d and %d.\n", minRange, maxRange);

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        attempts++;

        // Check if the user's guess is correct, higher or lower than the random number
        if (guess == random) {
            printf("Congratulations! You guessed the number in %d attempts.\n\n", attempts);
            printf("Do you want to play again? (Y/N): ");
            char playAgain;
            scanf(" %c", &playAgain);

            // Check if the user wants to play again
            if (playAgain == 'Y' || playAgain == 'y') {
                // Reset the variables and generate a new random number
                attempts = 0;
                random = randomInt(minRange, maxRange);
                printf("I'm thinking of a number between %d and %d.\n", minRange, maxRange);
            } 
        } else if (guess < random) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }
    } while (1);

    return 0;
}