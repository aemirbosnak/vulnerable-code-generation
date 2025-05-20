//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants and variables
const int MAGIC_NUMBER = 42;
int secret_number = 0;
int guess = 0;
int attempts = 0;

// Function to generate a random number between 1 and 10
int random_number() {
    return (rand() % 10) + 1;
}

// Function to check if the user's guess is correct
int is_correct(int guess) {
    return (guess == secret_number);
}

// Main program
int main() {
    // Generate a random secret number
    secret_number = random_number();

    // Print the secret number and challenge the user to guess it
    printf("I'm thinking of a number between 1 and 10... can you guess it?\n");
    printf("The secret number is: %d\n", secret_number);

    // Loop until the user correctly guesses the number
    while (1) {
        // Ask the user for their guess
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (is_correct(guess)) {
            break;
        }

        // If the guess is incorrect, print a hint and try again
        else {
            printf("Too high! Try again...\n");
            attempts++;
        }
    }

    // If the user correctly guessed the number, print a success message
    if (is_correct(guess)) {
        printf("Congratulations! You guessed the secret number in %d attempts!\n", attempts);
    }

    // If the user failed to guess the number, print a failure message
    else {
        printf("Sorry, you didn't guess the secret number... it took you %d attempts\n", attempts);
    }

    return 0;
}