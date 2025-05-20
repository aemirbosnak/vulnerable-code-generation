//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int lower, int upper) {
    int num = rand() % (upper - lower + 1) + lower;
    return num;
}

int main() {
    int difficultyLevel, randomNumber, userGuess, maxGuessesAllowed;
    int numGuesses = 0;

    printf("Welcome to the Number Guessing Game!\n\n");

    // Set the difficulty level
    printf("Enter the difficulty level (1, 2, or 3):\n");
    scanf("%d", &difficultyLevel);

    // Set the maximum number of guesses based on the chosen difficulty level
    if (difficultyLevel == 1) {
        maxGuessesAllowed = 10;
    } else if (difficultyLevel == 2) {
        maxGuessesAllowed = 7;
    } else if (difficultyLevel == 3) {
        maxGuessesAllowed = 5;
    } else {
        printf("Invalid difficulty level!\n");
        return 0;
    }

    // Generate a random number within the specified range
    srand(time(0));
    int lower = 1, upper = 100;
    randomNumber = generateRandomNumber(lower, upper);

    printf("\nGuess a number between %d and %d\n", lower, upper);

    // Loop until the user guesses the correct number or reaches the maximum number of guesses
    while (numGuesses < maxGuessesAllowed) {
        printf("Guess #%d: ", numGuesses + 1);
        scanf("%d", &userGuess);
        numGuesses++;

        if (userGuess == randomNumber) {
            printf("\nCongratulations! You guessed the number in %d tries.\n", numGuesses);
            return 0;
        } else if (userGuess < randomNumber) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
    }

    // If the loop terminates, the user did not guess the number within the allowed attempts
    printf("\nSorry, you ran out of guesses. The correct number was %d.\n", randomNumber);
    return 0;
}