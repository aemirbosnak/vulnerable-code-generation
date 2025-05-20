//GPT-4o-mini DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5
#define MIN_NUMBER 1
#define MAX_NUMBER 100

void printWelcomeMessage() {
    printf("***********************************************\n");
    printf("          Welcome to the Number Guessing Game! \n");
    printf("***********************************************\n");
    printf("Try to guess the number I'm thinking of between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("You have %d tries to get it right.\n", MAX_TRIES);
}

int getRandomNumber() {
    return (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
}

int getUserGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

void evaluateGuess(int guess, int secretNumber, int attempt) {
    if (guess < secretNumber) {
        printf("Your guess is too low. Attempt %d of %d.\n", attempt, MAX_TRIES);
    } else if (guess > secretNumber) {
        printf("Your guess is too high. Attempt %d of %d.\n", attempt, MAX_TRIES);
    } else {
        printf("Congratulations! You've guessed the number %d correctly!\n", secretNumber);
    }
}

void playGame() {
    int secretNumber = getRandomNumber();
    int guess;
    int attempts = 0;

    while (attempts < MAX_TRIES) {
        guess = getUserGuess();
        attempts++;
        evaluateGuess(guess, secretNumber, attempts);
        if (guess == secretNumber) {
            return;  // Exit the game loop if the guess is correct
        }
    }
    printf("Sorry! You've used all your attempts. The correct number was %d.\n", secretNumber);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char continuePlaying = 'y';

    printWelcomeMessage();

    while (continuePlaying == 'y' || continuePlaying == 'Y') {
        playGame();
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &continuePlaying);
    }

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}