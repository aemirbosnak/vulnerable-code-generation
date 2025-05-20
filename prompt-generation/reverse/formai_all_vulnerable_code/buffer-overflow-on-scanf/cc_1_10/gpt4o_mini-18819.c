//GPT-4o-mini DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUMBER 100

void greetUser() {
    printf("Welcome to 'Guess the Number' Game!\n");
    printf("You have to guess a number between 1 and %d.\n", MAX_NUMBER);
    printf("You get %d attempts to find the correct number.\n", MAX_GUESSES);
    printf("Let's see if you can beat the odds!\n\n");
}

int getRandomNumber() {
    // Seed the random number generator
    srand(time(NULL));
    return rand() % MAX_NUMBER + 1; // Generates number between 1 and MAX_NUMBER
}

int promptUserForGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

void evaluateGuess(int userGuess, int correctNumber, int attempt) {
    if (userGuess < correctNumber) {
        printf("Attempt %d: Your guess is too low!\n", attempt);
    } else if (userGuess > correctNumber) {
        printf("Attempt %d: Your guess is too high!\n", attempt);
    } else {
        printf("Congratulations! You've guessed the correct number: %d\n", correctNumber);
    }
}

void playGame() {
    int correctNumber = getRandomNumber();
    int userGuess;
    int attempt;

    for (attempt = 1; attempt <= MAX_GUESSES; attempt++) {
        userGuess = promptUserForGuess();
        evaluateGuess(userGuess, correctNumber, attempt);

        if (userGuess == correctNumber) {
            return; // Exit if guessed correctly
        }
    }
    printf("Sorry, you've used all your attempts! The correct number was: %d\n", correctNumber);
}

int main() {
    char playAgain;

    do {
        greetUser();
        playGame();

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        printf("\n");

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing 'Guess the Number'. Goodbye!\n");
    return 0;
}