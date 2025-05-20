//GPT-4o-mini DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

void print_instructions() {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I've picked a random number between 1 and 100.\n");
    printf("You have %d tries to guess it. Good luck!\n", MAX_TRIES);
}

int main() {
    int random_number, guess;
    int tries = 0;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));
    random_number = rand() % 100 + 1; // Random number between 1 and 100

    print_instructions();

    while (tries < MAX_TRIES && game_over == 0) {
        printf("Enter your guess: ");
        
        // Validate user input
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        tries++;

        if (guess < 1 || guess > 100) {
            printf("Please guess a number within the range of 1 to 100.\n");
            tries--; // decrement tries for invalid input
            continue;
        }

        if (guess < random_number) {
            printf("Too low! Try again.\n");
        } else if (guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d tries.\n", random_number, tries);
            game_over = 1; // End the game
        }

        // Prompt user for remaining tries
        if (tries < MAX_TRIES && game_over == 0) {
            printf("You have %d tries left.\n", MAX_TRIES - tries);
        }
    }

    if (!game_over) {
        printf("Sorry, you've used all your tries. The number was %d. Better luck next time!\n", random_number);
    }

    printf("Thank you for playing the Guess the Number Game!\n");

    return 0;
}