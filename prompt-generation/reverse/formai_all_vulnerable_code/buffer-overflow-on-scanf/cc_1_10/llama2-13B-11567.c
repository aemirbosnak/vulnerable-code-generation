//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants and variables
const int MAGIC_NUMBER = 42;
const int MIN_NUMBER = -100;
const int MAX_NUMBER = 100;
int randomNumber = 0;
int userGuess = 0;
int correctGuesses = 0;

// Function to generate a random number between MIN_NUMBER and MAX_NUMBER
void generateRandomNumber() {
    srand(time(NULL));
    randomNumber = rand() % (MAX_NUMBER - MIN_NUMBER) + MIN_NUMBER;
}

// Function to check if the user's guess is correct
void checkGuess(int guess) {
    if (guess == randomNumber) {
        correctGuesses++;
        printf("Correct! You guessed %d, the correct answer is %d\n", guess, randomNumber);
    } else {
        printf("Incorrect. The correct answer is %d, you guessed %d\n", randomNumber, guess);
    }
}

int main() {
    // Generate a random number to start with
    generateRandomNumber();

    // Ask the user for their first guess
    printf("Guess a number between %d and %d: ", MIN_NUMBER, MAX_NUMBER);
    scanf("%d", &userGuess);

    // Check if the user's guess is correct
    checkGuess(userGuess);

    // Keep asking the user for guesses until they get it right
    while (correctGuesses < 10) {
        generateRandomNumber();
        printf("You guessed %d, but that's not correct. Keep trying!\n", userGuess);
        scanf("%d", &userGuess);
        checkGuess(userGuess);
    }

    // Print the final result
    printf("You guessed correctly %d times out of 10 attempts\n", correctGuesses);

    return 0;
}