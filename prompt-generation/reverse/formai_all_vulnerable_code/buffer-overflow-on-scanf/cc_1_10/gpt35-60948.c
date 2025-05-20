//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE 1     // Minimum value for generating random number
#define MAX_VALUE 100   // Maximum value for generating random number
#define MAX_GUESSES 7   // Maximum number of guesses allowed

int main() {
    int number = 0;     // The number to be guessed
    int guess = 0;      // The current guess
    int guesses = 0;    // Number of guesses so far
    int won = 0;        // Flag indicating if the game has been won or not

    srand(time(NULL));  // Initialize random number generator

    // Generate a random number to be guessed
    number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

    // Welcome message
    printf("Welcome to the number guessing game!\n");
    printf("I have selected a number between %d and %d.\n", MIN_VALUE, MAX_VALUE);
    printf("You have %d guesses to try to guess it.\n\n", MAX_GUESSES);

    // Loop until the game is won or all guesses are used up
    while(!won && guesses < MAX_GUESSES) {
        // Prompt the user for their guess
        printf("Enter your guess (guess %d): ", guesses+1);
        scanf("%d", &guess);

        // Check the guess against the number
        if (guess < MIN_VALUE || guess > MAX_VALUE) {
            // Invalid guess
            printf("Invalid guess! Your guess should be between %d and %d.\n\n", MIN_VALUE, MAX_VALUE);
        } else if (guess < number) {
            // Guess is too low
            printf("Your guess is too low!\n\n");
            guesses++;
        } else if (guess > number) {
            // Guess is too high
            printf("Your guess is too high!\n\n");
            guesses++;
        } else {
            // Guess is correct
            printf("Congratulations! You guessed the number in %d guesses!\n", guesses+1);
            won = 1;
        }
    }

    // If the game was lost, print the correct number
    if (!won) {
        printf("Sorry, you did not guess the correct number. The number was %d.\n", number);
    }

    return 0;
}