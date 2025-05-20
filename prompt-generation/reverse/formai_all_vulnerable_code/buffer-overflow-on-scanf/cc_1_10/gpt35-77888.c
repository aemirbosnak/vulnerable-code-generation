//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int getRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Function to check if the guessed number is correct
int checkGuess(int guess, int randomNumber) {
    if (guess == randomNumber) {
        printf("Congratulations! You guessed the number!\n");
        return 1;
    } else if (guess < randomNumber) {
        printf("The number is higher than your guess. Try again.\n");
    } else {
        printf("The number is lower than your guess. Try again.\n");
    }
    return 0;
}

// Main function
int main() {
    int lower = 1, upper = 100, guess;
    int randomNumber;
    int maxAttempts = 5, attempts = 0;

    // seed random number generator
    srand(time(0));

    // Generate random number
    randomNumber = getRandomNumber(lower, upper);

    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d attempts to guess the number between %d and %d\n", maxAttempts, lower, upper);

    // Loop until max attempts or correct guess
    while (attempts < maxAttempts) {
        printf("Guess the number: ");
        scanf("%d", &guess);
        attempts++;

        if (checkGuess(guess, randomNumber)) {
            break;
        }
    }

    if (attempts == maxAttempts && !checkGuess(guess, randomNumber)) {
        printf("Game Over. The number was %d.\n", randomNumber);
    }

    return 0;
}