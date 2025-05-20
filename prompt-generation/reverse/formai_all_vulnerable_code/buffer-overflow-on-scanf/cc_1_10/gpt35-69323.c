//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random number generator
    srand(time(NULL));

    // Set up game variables
    int guess_count = 0;
    int number_of_guesses = 5;
    int secret_number = rand() % 100 + 1;
    int guessed_number;

    // Print instructions
    printf("Welcome to the Guessing Game!\n");
    printf("Guess a secret number between 1 and 100.\n");
    printf("You have %d guesses to find the number.\n", number_of_guesses);

    // Loop until the user guesses the correct number or runs out of guesses
    while (guess_count < number_of_guesses) {

        // Get user guess
        printf("Guess %d: ", guess_count + 1);
        scanf("%d", &guessed_number);

        // Check if guess is correct
        if (guessed_number == secret_number) {
            printf("Congratulations! You guessed the secret number in %d tries!\n", guess_count + 1);
            return 0;
        }

        // Check if guess is too high or too low
        else if (guessed_number < secret_number) {
            printf("Too low! Try again.\n");
        }
        else {
            printf("Too high! Try again.\n");
        }

        // Increment guess count
        guess_count++;
    }

    // If the user runs out of guesses, display the secret number
    printf("Sorry, you ran out of guesses! The secret number was %d.\n", secret_number);

    return 0;
}