//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUMBER 100

void print_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and %d.\n", MAX_NUMBER);
    printf("You have %d chances to guess it.\n\n", MAX_GUESSES);
}

int main() {
    int target_number, guess, attempts = 0;
    char play_again;

    srand(time(NULL));

    do {
        target_number = (rand() % MAX_NUMBER) + 1; // Random number between 1 and MAX_NUMBER
        attempts = 0;

        print_instructions();

        while (attempts < MAX_GUESSES) {
            printf("Enter your guess: ");
            scanf("%d", &guess);

            if (guess < 1 || guess > MAX_NUMBER) {
                printf("Out of bounds! Please guess a number between 1 and %d.\n", MAX_NUMBER);
                continue;
            }

            attempts++;

            if (guess < target_number) {
                printf("Too low! Try again.\n");
            } else if (guess > target_number) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You've guessed the number %d in %d attempts!\n", target_number, attempts);
                break;
            }

            if (attempts == MAX_GUESSES) {
                printf("Sorry! You've used all your attempts. The number was %d.\n", target_number);
            }
        }

        printf("Do you want to play again? (y/n): ");
        while (getchar() != '\n'); // Clear the input buffer
        scanf("%c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}