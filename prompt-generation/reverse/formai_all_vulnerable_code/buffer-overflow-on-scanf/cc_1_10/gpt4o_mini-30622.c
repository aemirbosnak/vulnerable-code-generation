//GPT-4o-mini DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage();
int generateRandomNumber(int lower, int upper);
int getUserGuess();
int checkGuess(int guess, int actual);

int main() {
    int numberToGuess, userGuess, attempts = 0;
    const int LOWER_LIMIT = 1;
    const int UPPER_LIMIT = 100;

    // Print welcome message
    printWelcomeMessage();

    // Seed the random number generator
    srand(time(0));

    // Generate the random number
    numberToGuess = generateRandomNumber(LOWER_LIMIT, UPPER_LIMIT);

    // Game loop
    do {
        userGuess = getUserGuess();
        attempts++;

        if (checkGuess(userGuess, numberToGuess) == 0) {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", numberToGuess, attempts);
        }
    } while (userGuess != numberToGuess);

    return 0;
}

void printWelcomeMessage() {
    printf("Welcome to 'Guess the Number' Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");
}

int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int getUserGuess() {
    int guess;

    printf("Please enter your guess: ");
    while (scanf("%d", &guess) != 1) {
        printf("Invalid input! Please enter a valid integer: ");
        while (getchar() != '\n'); // clear invalid input
    }
    
    return guess;
}

int checkGuess(int guess, int actual) {
    if (guess < actual) {
        printf("Too low! Try again.\n");
        return -1;
    } else if (guess > actual) {
        printf("Too high! Try again.\n");
        return 1;
    } else {
        return 0; // correct guess
    }
}