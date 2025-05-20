//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void display_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I've picked a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n", MAX_ATTEMPTS);
    printf("Try to guess the number!\n");
}

int main() {
    int target_number, guess, attempts = 0;
    char play_again;

    // Seed random number generator
    srand((unsigned int)time(NULL));

    do {
        target_number = rand() % 100 + 1; // Random number between 1 and 100
        attempts = 0;
        display_instructions();

        while (attempts < MAX_ATTEMPTS) {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess < 1 || guess > 100) {
                printf("Please guess a number within the range!\n");
                attempts--; // Don't count this as a valid attempt
                continue;
            }

            if (guess < target_number) {
                printf("Too low! Try again.\n");
            } else if (guess > target_number) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You've guessed the right number: %d\n", target_number);
                printf("It took you %d attempts.\n", attempts);
                break;
            }

            if (attempts == MAX_ATTEMPTS) {
                printf("Sorry, you've used all your attempts! The number was: %d\n", target_number);
            }
        }

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);  // adding a space before %c to consume newline

    } while(play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}