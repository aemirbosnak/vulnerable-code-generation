//GPT-4o-mini DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

// Function to display welcome message
void displayWelcome() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d attempts to guess the correct number.\n", MAX_ATTEMPTS);
}

// Function to generate a random number within a specified range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to get the user's guess
int getUserGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

// Function to check the guessed number against the generated number
void checkGuess(int guess, int randomNumber, int attempt) {
    if (guess > randomNumber) {
        printf("Too high! Try again.\n");
    } else if (guess < randomNumber) {
        printf("Too low! Try again.\n");
    } else {
        printf("Congratulations! You've guessed the correct number: %d\n", randomNumber);
    }
}

// Function to start the game
void startGame(int min, int max) {
    int randomNumber = generateRandomNumber(min, max);
    int guess;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        guess = getUserGuess();
        attempts++;
        checkGuess(guess, randomNumber, attempts);
        if (guess == randomNumber) {
            break;
        }
    }
    
    if (guess != randomNumber) {
        printf("Sorry, you've used all your attempts. The correct number was: %d\n", randomNumber);
    }
}

// Main function
int main() {
    int min = 1, max = 100;
    char playAgain;

    // Seed the random number generator
    srand(time(NULL));

    do {
        displayWelcome();
        startGame(min, max);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}