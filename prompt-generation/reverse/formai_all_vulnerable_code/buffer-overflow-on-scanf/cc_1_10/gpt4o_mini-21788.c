//GPT-4o-mini DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

void print_welcome_message() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess it correctly!\n", MAX_TRIES);
    printf("Good luck!\n\n");
}

int get_guess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

void give_hint(int number, int guess) {
    if (guess < number) {
        printf("Your guess is too low! Try again.\n");
    } else if (guess > number) {
        printf("Your guess is too high! Try again.\n");
    } else {
        printf("Congratulations! You've guessed the number!\n");
    }
}

int main() {
    int number, guess, tries = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));
    number = rand() % 100 + 1;  // Generate a number between 1 and 100

    // Print welcome message
    print_welcome_message();

    // Main game loop
    while (tries < MAX_TRIES) {
        guess = get_guess();       // Get user's guess
        tries++;                   // Increase the number of tries
        give_hint(number, guess);  // Provide feedback on the guess

        // Check if the guess is correct
        if (guess == number) {
            break;  // Exit the loop if guessed correctly
        }

        // Notify the user about remaining attempts
        if (tries < MAX_TRIES) {
            printf("You have %d attempts left.\n\n", MAX_TRIES - tries);
        }
    }

    // Final message
    if (guess == number) {
        printf("You won! The number was %d.\n", number);
    } else {
        printf("Sorry, you've used all your attempts! The number was %d.\n", number);
    }

    return 0;
}