//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 7

// Function prototypes
void printWelcome();
void printInstructions();
int getPlayerGuess();
void giveFeedback(int guess, int secret_number, int attempt);
void printClosingMessage(int success);

int main() {
    int secret_number, player_guess, attempts = 0;
    srand(time(NULL)); // Seed the random number generator
    secret_number = rand() % 100 + 1; // Random number between 1 and 100

    printWelcome();
    printInstructions();

    // Game loop
    while (attempts < MAX_TRIES) {
        player_guess = getPlayerGuess();
        giveFeedback(player_guess, secret_number, attempts);
        attempts++;

        if (player_guess == secret_number) {
            printClosingMessage(1);
            break;
        }
    }

    if (attempts == MAX_TRIES) {
        printClosingMessage(0);
    }

    return 0;
}

void printWelcome() {
    printf("************************************\n");
    printf("* Welcome to Guess the Number!     *\n");
    printf("************************************\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. You have %d attempts to guess a number\n", MAX_TRIES);
    printf("2. The number is between 1 and 100.\n");
    printf("3. After each guess, you will receive feedback.\n");
    printf("Enjoy the game!\n");
}

int getPlayerGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    while (guess < 1 || guess > 100) {
        printf("Invalid guess! Please enter a number between 1 and 100: ");
        scanf("%d", &guess);
    }
    return guess;
}

void giveFeedback(int guess, int secret_number, int attempt) {
    if (guess < secret_number) {
        printf("Attempt %d: Too low! Try again.\n", attempt + 1);
    } else if (guess > secret_number) {
        printf("Attempt %d: Too high! Try again.\n", attempt + 1);
    }
}

void printClosingMessage(int success) {
    if (success) {
        printf("Congratulations! You've guessed the number!\n");
    } else {
        printf("Out of attempts! Better luck next time.\n");
    }
}