//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int secret_number, user_guess, tries = 0;
    char play_again;

    // Initialize random number generator
    srand(time(NULL));

    // Introduction
    printf("Welcome to the Guessing Game!\n");

    do {
        // Generate secret number
        secret_number = rand() % 101;

        // Reset tries count
        tries = 0;

        // Game loop
        while (1) {
            // Get user guess
            printf("Please enter your guess (between 0 and 100): ");
            scanf("%d", &user_guess);

            // Check if guess is within range
            if (user_guess < 0 || user_guess > 100) {
                printf("Your guess is out of range. Please try again.\n");
                continue;
            }

            // Increment tries count
            tries++;

            // Check if guess is correct
            if (user_guess == secret_number) {
                printf("Congratulations! You guessed the secret number in %d tries!\n", tries);
                break;
            } else if (user_guess < secret_number) {
                printf("Your guess is too low. Please try again.\n");
            } else {
                printf("Your guess is too high. Please try again.\n");
            }
        }

        // Play again?
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &play_again);

    } while (play_again == 'y');

    // Exit message
    printf("Thanks for playing! Goodbye.\n");

    return 0;
}