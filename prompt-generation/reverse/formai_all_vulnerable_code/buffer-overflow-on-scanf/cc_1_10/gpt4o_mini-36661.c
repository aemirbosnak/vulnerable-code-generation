//GPT-4o-mini DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

// Function prototypes
void displayWelcomeMessage();
int getRandomNumber(int lower, int upper);
void playGame();
int getUserGuess();
int evaluateGuess(int guess, int target);

int main() {
    displayWelcomeMessage();
    playGame();
    return 0;
}

void displayWelcomeMessage() {
    printf("***********************************\n");
    printf("Welcome to the Number Guessing Game!\n");
    printf("Try to guess the number between 1 and 100.\n");
    printf("You have %d tries to get it right!\n", MAX_TRIES);
    printf("***********************************\n");
}

int getRandomNumber(int lower, int upper) {
    srand(time(0)); // Seed the random number generator
    return (rand() % (upper - lower + 1)) + lower;
}

void playGame() {
    int target = getRandomNumber(1, 100);
    int guess;
    int tries = 0;
    int result;

    while (tries < MAX_TRIES) {
        guess = getUserGuess();
        result = evaluateGuess(guess, target);
        
        if (result == 0) {
            printf("Congratulations! You've guessed the number %d correctly!\n", target);
            return;  // Exit the game if guessed correctly
        } else if (result < 0) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Your guess is too high. Try again.\n");
        }
        tries++;
        printf("You have %d tries left.\n", MAX_TRIES - tries);
    }

    printf("Sorry, you've used all your tries! The correct number was %d.\n", target);
}

int getUserGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

int evaluateGuess(int guess, int target) {
    if (guess < target) {
        return -1; // Guess is too low
    } else if (guess > target) {
        return 1; // Guess is too high
    } else {
        return 0; // Correct guess
    }
}