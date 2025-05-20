//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void print_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have to guess a number between 1 and 100.\n");
    printf("You have %d attempts to guess the number.\n", MAX_ATTEMPTS);
}

int main() {
    int target, guess, attempts = 0;
    char play_again;
    
    srand(time(NULL)); // Seed for random number generation

    do {
        target = rand() % 100 + 1; // Generate a random number between 1 and 100
        attempts = 0;

        print_instructions();

        while (attempts < MAX_ATTEMPTS) {
            printf("Attempt %d: Enter your guess: ", attempts + 1);
            scanf("%d", &guess);

            if (guess < 1 || guess > 100) {
                printf("Please guess a number between 1 and 100.\n");
                continue;
            }

            attempts++;

            if (guess < target) {
                printf("Too low! Try again.\n");
            } else if (guess > target) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You've guessed the number %d in %d attempts!\n", target, attempts);
                break;
            }
        }

        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry, you've used all your attempts! The number was %d.\n", target);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}