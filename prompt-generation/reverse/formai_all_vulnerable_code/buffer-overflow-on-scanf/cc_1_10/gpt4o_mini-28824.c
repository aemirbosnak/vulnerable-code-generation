//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void playerGuess(int secretNumber, int playerNumber);
int getValidGuess(int playerNumber);

int main() {
    srand(time(NULL)); // Seed random number generator
    int secretNumber1, secretNumber2;

    printf("Player 1, please enter a number between 1 and %d: ", MAX_NUMBER);
    scanf("%d", &secretNumber1);
    while (secretNumber1 < 1 || secretNumber1 > MAX_NUMBER) {
        printf("Invalid number! Please enter a number between 1 and %d: ", MAX_NUMBER);
        scanf("%d", &secretNumber1);
    }

    printf("Player 2, please enter a number between 1 and %d: ", MAX_NUMBER);
    scanf("%d", &secretNumber2);
    while (secretNumber2 < 1 || secretNumber2 > MAX_NUMBER) {
        printf("Invalid number! Please enter a number between 1 and %d: ", MAX_NUMBER);
        scanf("%d", &secretNumber2);
    }

    printf("\nBoth players have set their secret numbers. Let's start the game!\n\n");

    // Player 1 guesses Player 2's secret number
    printf("Player 1's turn:\n");
    playerGuess(secretNumber2, 1);

    // Player 2 guesses Player 1's secret number
    printf("\nPlayer 2's turn:\n");
    playerGuess(secretNumber1, 2);

    return 0;
}

void playerGuess(int secretNumber, int playerNumber) {
    int guess = getValidGuess(playerNumber);
    
    if (guess == secretNumber) {
        printf("Congratulations Player %d! You've guessed the number %d correctly!\n", playerNumber, secretNumber);
    } else {
        if (guess < secretNumber) {
            printf("Player %d, your guess is too low. Try again.\n", playerNumber);
        } else {
            printf("Player %d, your guess is too high. Try again.\n", playerNumber);
        }
        // Recursively call playerGuess until correct guess
        playerGuess(secretNumber, playerNumber);
    }
}

int getValidGuess(int playerNumber) {
    int guess;
    printf("Player %d, enter your guess: ", playerNumber);
    scanf("%d", &guess);
    
    while (guess < 1 || guess > MAX_NUMBER) {
        printf("Invalid guess! Please enter a number between 1 and %d: ", MAX_NUMBER);
        scanf("%d", &guess);
    }
    
    return guess;
}