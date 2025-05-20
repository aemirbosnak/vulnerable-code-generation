//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

// Function to display the introduction
void displayIntro() {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I've selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess it correctly!\n", MAX_ATTEMPTS);
    printf("Good luck and have fun!\n\n");
}

// Function to get a random number between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to get user input
int getUserInput() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

// Function to evaluate the user's guess
void evaluateGuess(int guess, int secretNumber, int *attemptsLeft) {
    if (guess < 1 || guess > 100) {
        printf("Your guess is out of bounds! Please guess a number between 1 and 100.\n\n");
    } else if (guess < secretNumber) {
        printf("Too low! Try guessing higher.\n\n");
        (*attemptsLeft)--;
    } else if (guess > secretNumber) {
        printf("Too high! Try guessing lower.\n\n");
        (*attemptsLeft)--;
    } else {
        printf("Congratulations! You've guessed the number %d correctly!\n", secretNumber);
    }
}

// Function to display attempts left
void displayAttemptsLeft(int attemptsLeft) {
    if (attemptsLeft > 0) {
        printf("You have %d attempt(s) left.\n", attemptsLeft);
    } else {
        printf("No attempts left! Better luck next time.\n");
    }
}

// Main game logic
int main() {
    srand(time(NULL)); // Seed the random number generator
    int secretNumber = getRandomNumber(1, 100);
    int attemptsLeft = MAX_ATTEMPTS;
    int guess = 0;

    // Show the introduction
    displayIntro();
    
    // The game loop
    while (attemptsLeft > 0 && guess != secretNumber) {
        guess = getUserInput();
        evaluateGuess(guess, secretNumber, &attemptsLeft);
        displayAttemptsLeft(attemptsLeft);
    }

    if (guess != secretNumber) {
        printf("The secret number was %d. Better luck next time!\n", secretNumber);
    }

    printf("Thank you for playing! Hope you had a good time!\n");

    return 0;
}