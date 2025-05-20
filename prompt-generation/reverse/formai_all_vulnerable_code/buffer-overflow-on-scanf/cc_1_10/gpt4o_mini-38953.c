//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int secretNumber, int attempts);

void printInstructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Your goal is to guess the number within a certain number of attempts.\n");
    printf("If your guess is too high or too low, I will let you know.\n");
    printf("Let's see if you can guess it!\n\n");
}

void playGame(int secretNumber, int attempts) {
    int guess;

    if (attempts <= 0) {
        printf("Sorry, you've run out of attempts! The secret number was %d.\n", secretNumber);
        return;
    }

    printf("You have %d attempts left. Please enter your guess: ", attempts);
    scanf("%d", &guess);

    if (guess < 1 || guess > 100) {
        printf("Your guess must be between 1 and 100. Please try again.\n");
        playGame(secretNumber, attempts);
    } else if (guess < secretNumber) {
        printf("Too low! Try again.\n");
        playGame(secretNumber, attempts - 1);
    } else if (guess > secretNumber) {
        printf("Too high! Try again.\n");
        playGame(secretNumber, attempts - 1);
    } else {
        printf("Congratulations! You've guessed the number %d correctly!\n", secretNumber);
    }
}

int main() {
    int secretNumber, attempts = 10;

    srand(time(NULL));  // Seed the random number generator
    secretNumber = rand() % 100 + 1;  // Generate secret number between 1 - 100

    printInstructions();
    playGame(secretNumber, attempts);

    return 0;
}