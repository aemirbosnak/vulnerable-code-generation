//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("--------------------------------------------------\n");
    printf("          Welcome to the Number Guessing Game     \n");
    printf("--------------------------------------------------\n");
    printf("Try to guess the secret number within the given range!\n");
    printf("You will receive hints after each guess.\n");
    printf("Good luck!\n");
    printf("--------------------------------------------------\n");
}

int get_user_guess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

void give_feedback(int guess, int secret_number) {
    if (guess < secret_number) {
        printf("Too low! Try again.\n");
    } else if (guess > secret_number) {
        printf("Too high! Try again.\n");
    }
}

int main() {
    int lower_bound, upper_bound, secret_number, guess;
    int max_attempts, attempts = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Display welcome message
    print_welcome_message();
    
    // Get user-defined range for guessing
    printf("Set the lower bound of the guessing range: ");
    scanf("%d", &lower_bound);
    printf("Set the upper bound of the guessing range: ");
    scanf("%d", &upper_bound);

    // Choose a secret number within the defined range
    secret_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;

    // Get user-defined max attempts
    printf("Set the maximum number of attempts allowed: ");
    scanf("%d", &max_attempts);

    // Begin guessing game
    printf("You have %d attempts to guess the number between %d and %d.\n", max_attempts, lower_bound, upper_bound);

    while (attempts < max_attempts) {
        guess = get_user_guess();
        attempts++;

        // Compare guess with the secret number
        if (guess == secret_number) {
            printf("Congratulations! You've guessed the secret number %d in %d attempts!\n", secret_number, attempts);
            break;
        } else {
            give_feedback(guess, secret_number);
            printf("Attempts left: %d\n", max_attempts - attempts);
        }

        // Give hint if max attempts reached
        if (attempts == max_attempts) {
            printf("You've used all your attempts! The secret number was %d.\n", secret_number);
        }
    }
    
    // End of game message
    printf("Thank you for playing the Number Guessing Game!\n");
    printf("--------------------------------------------------\n");

    return 0;
}