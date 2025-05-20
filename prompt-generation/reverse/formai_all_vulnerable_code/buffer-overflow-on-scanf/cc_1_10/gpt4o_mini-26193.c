//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You need to guess a number between 1 and 100.\n");
    printf("You have 7 attempts to guess the correct number.\n");
    printf("Let's see if you can beat the odds!\n\n");
}

int main() {
    int secret_number, guess, attempts = 0, max_attempts = 7;
    char play_again;

    // Seed the random number generator
    srand(time(0));

    do {
        // Generate a secret number between 1 and 100
        secret_number = (rand() % 100) + 1;
        attempts = 0;

        print_instructions();

        while (attempts < max_attempts) {
            printf("Attempt %d: Enter your guess: ", attempts + 1);
            scanf("%d", &guess);

            if (guess < 1 || guess > 100) {
                printf("Please guess a number between 1 and 100.\n");
                continue; // Skip to the next iteration
            }

            attempts++;

            if (guess < secret_number) {
                printf("Too low! Try again.\n");
            } else if (guess > secret_number) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You guessed the number %d in %d attempts!\n", secret_number, attempts);
                break;
            }

            if (attempts == max_attempts) {
                printf("Sorry, you've used all your attempts! The number was %d.\n", secret_number);
            }
        }

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}