//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define some constants and variables
#define MAGIC_NUMBER 42
#define MAX_GUESS 100
#define MIN_GUESS 1
#define GUESS_DIFF 5

// Function to generate a random number between MIN_GUESS and MAX_GUESS
int random_guess() {
    return (rand() % (MAX_GUESS - MIN_GUESS)) + MIN_GUESS;
}

// Function to check if the user's guess is correct
int check_guess(int guess) {
    return (guess == MAGIC_NUMBER) ? 1 : 0;
}

// Function to print the game over screen
void game_over(int correct) {
    if (correct) {
        printf("Congratulations! You guessed the magic number %d correctly! \n", MAGIC_NUMBER);
    } else {
        printf("Better luck next time! The magic number was %d. \n", MAGIC_NUMBER);
    }
}

int main() {
    int guess, correct = 0;

    // Print the game start screen
    printf("Welcome to the Magic Number Game! \n");
    printf("I'm thinking of a number between 1 and 100... \n");

    // Generate a random number and print it
    int magic_number = random_guess();
    printf("The magic number is %d. \n", magic_number);

    // Start the game loop
    while (1) {
        // Get the user's guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        // Check if the user's guess is correct
        correct = check_guess(guess);

        // Update the game state
        if (correct) {
            game_over(correct);
            break;
        }

        // Print the game over screen if the user runs out of guesses
        if (guess > MAX_GUESS) {
            game_over(0);
        }

        // Print the feedback message
        printf("Too high! The magic number is lower than %d. \n", guess);
        if (guess < MIN_GUESS) {
            printf("Too low! The magic number is higher than %d. \n", guess);
        }
    }

    return 0;
}