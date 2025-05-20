//GPT-4o-mini DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define NUMBER_RANGE 100

void print_intro() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d attempts to guess the correct number (between 1 and %d).\n", MAX_ATTEMPTS, NUMBER_RANGE);
    printf("Good luck!\n\n");
}

int generate_random_number(int max) {
    return (rand() % max) + 1; // Ensure the number is between 1 and max (inclusive)
}

void play_game() {
    int number_to_guess, user_guess;
    int attempts_left = MAX_ATTEMPTS;

    // Generate a random number
    number_to_guess = generate_random_number(NUMBER_RANGE);

    while (attempts_left > 0) {
        printf("You have %d attempts left. Enter your guess: ", attempts_left);
        scanf("%d", &user_guess);

        if (user_guess < 1 || user_guess > NUMBER_RANGE) {
            printf("Please enter a valid number between 1 and %d.\n", NUMBER_RANGE);
            continue; // Skip the rest of the loop and ask for input again
        }

        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n\n");
        } else {
            printf("Congratulations! You've guessed the right number: %d\n\n", number_to_guess);
            return; // Exit the function to end the game
        }

        attempts_left--; // Deduct an attempt
    }

    printf("Sorry, you're out of attempts! The correct number was: %d\n\n", number_to_guess);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char play_again;

    do {
        print_intro();
        play_game();

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again); // Space before %c to consume newline
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}