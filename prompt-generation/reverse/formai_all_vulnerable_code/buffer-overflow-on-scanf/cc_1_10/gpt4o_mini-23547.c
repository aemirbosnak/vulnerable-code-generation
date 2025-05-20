//GPT-4o-mini DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

void print_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have to guess the number between 1 and 100.\n");
    printf("You have %d attempts to guess the number correctly.\n", MAX_GUESSES);
}

int main() {
    int lower_bound = 1;
    int upper_bound = 100;
    int random_number, guess, attempts = 0;
    char play_again;

    // Seed the random number generator
    srand(time(0));

    do {
        // Generate a random number between lower_bound and upper_bound
        random_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;

        print_instructions();

        while (attempts < MAX_GUESSES) {
            printf("Attempt %d: Enter your guess: ", attempts + 1);
            scanf("%d", &guess);
            attempts++;

            if (guess < lower_bound || guess > upper_bound) {
                printf("Please guess a number within the range of %d to %d.\n", lower_bound, upper_bound);
            } else if (guess < random_number) {
                printf("Too low! Try again.\n");
            } else if (guess > random_number) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You've guessed the number correctly!\n");
                break;
            }

            if (attempts == MAX_GUESSES) {
                printf("Sorry, you've used all your attempts. The correct number was %d.\n", random_number);
            }
        }

        // Ask the player if they want to play again
        printf("Do you want to play again? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        scanf("%c", &play_again);
        attempts = 0; // Reset attempts for new game

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing the Number Guessing Game! Goodbye!\n");
    return 0;
}