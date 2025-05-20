//FormAI DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generateRandomNumber();
int startGame(int chosenNumber, int attempts);

int main() {
    int chosenNumber = generateRandomNumber(); // generate random number
    int attempts = 0;
    printf("\nWelcome to the number guessing game!\n");
    printf("You have 5 attempts to guess a number between 1 and 100\n");

    int result = startGame(chosenNumber, attempts); // start the game and get result

    if (result == 0) {
        printf("\nSorry, better luck next time!\n");
    } else {
        printf("\nCongratulations! You guessed the number!\n");
    }
    return 0;
}

// function to generate random number
int generateRandomNumber() {
    srand(time(0)); // seed for random function
    int randomNumber = (rand() % 100) + 1; // generate number between 1 and 100
    return randomNumber;
}

// function to start the game
int startGame(int chosenNumber, int attempts) {
    int guess = 0;
    while (attempts < 5) {
        printf("Attempt %d. Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        if (guess == chosenNumber) {
            return 1; // guessed the number
        } else {
            printf("Incorrect guess. ");
            if (guess < chosenNumber) {
                printf("Try a higher number\n\n");
            } else {
                printf("Try a lower number\n\n");
            }
            attempts++; // increment attempts counter
        }
    }
    return 0; // could not guess the number within 5 attempts
}