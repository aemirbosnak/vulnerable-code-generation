//Falcon-180B DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current date and time
void printDateTime() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s", asctime(t));
}

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to play a simple number guessing game
void playNumberGuessingGame() {
    int min = 1;
    int max = 100;
    int guess;
    int correctGuess = 0;

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between %d and %d. Can you guess it?\n", min, max);

    while (correctGuess == 0) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < min || guess > max) {
            printf("Invalid guess. Please enter a number between %d and %d.\n", min, max);
        } else if (guess == generateRandomNumber(min, max)) {
            printf("Congratulations! You guessed the correct number: %d\n", guess);
            correctGuess = 1;
        } else if (guess < generateRandomNumber(min, max)) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Your guess is too high. Try again.\n");
        }
    }
}

int main() {
    printf("Current date and time: ");
    printDateTime();

    playNumberGuessingGame();

    return 0;
}