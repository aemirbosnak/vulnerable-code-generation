//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants and variables
const int MAGIC_NUMBER = 42;
const int MIN_VALUE = -100;
const int MAX_VALUE = 100;
int randomValue = 0;
int guess = 0;
int attempts = 0;

// Function to generate a random number between MIN_VALUE and MAX_VALUE
int getRandomNumber() {
    return rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
}

// Function to check if the guess is correct
int isCorrect(int guess) {
    return guess == randomValue;
}

// Function to print the result and ask for another guess
void printResult(int result) {
    if (result == 0) {
        printf("You won! The random number was %d\n", randomValue);
    } else {
        printf("You lost. The random number was %d\n", randomValue);
    }
    printf("Do you want to play again? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        // Another game, let's get a new random number
        randomValue = getRandomNumber();
        guess = 0;
        attempts++;
    } else {
        // User doesn't want to play again, so exit the program
        printf("Goodbye! You played %d games\n", attempts);
        return;
    }
}

int main() {
    srand(time(NULL)); // Initialize the random number generator

    // Play the game until the user doesn't want to play again
    while (1) {
        // Generate a new random number
        randomValue = getRandomNumber();

        // Ask the user to guess the number
        printf("Guess a number between %d and %d: ", MIN_VALUE, MAX_VALUE);
        scanf(" %d", &guess);

        // Check if the guess is correct
        if (isCorrect(guess)) {
            printResult(1);
        } else {
            printResult(0);
        }
    }

    return 0;
}