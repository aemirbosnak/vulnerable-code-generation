//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

// Function prototype for recursive guessing
int guessNumber(int target, int player, int remainingGuesses);

// Function to initiate the game
void startGame() {
    // Random number generation setup
    srand(time(NULL));
    int target = rand() % 100 + 1; // Random number between 1 and 100
    printf("Welcome to the multiplayer guessing game!\n");
    printf("Two players will take turns guessing a number between 1 and 100.\n");
    printf("The first player to guess correctly wins!\n");
    
    // Start the guessing game
    guessNumber(target, 1, MAX_GUESSES);
}

// Recursive function for guessing the number
int guessNumber(int target, int player, int remainingGuesses) {
    if (remainingGuesses == 0) {
        printf("Player %d has run out of guesses! The number was %d.\n", player, target);
        return -1; // Indicating the game continues
    }

    int guess;
    printf("Player %d, you have %d guess(es) left. Make your guess: ", player, remainingGuesses);
    scanf("%d", &guess);

    if (guess < 1 || guess > 100) {
        printf("Invalid guess! Please guess a number between 1 and 100.\n");
        return guessNumber(target, player, remainingGuesses); // Ask again
    }

    if (guess == target) {
        printf("Congratulations, Player %d! You guessed the number %d correctly!\n", player, target);
        return 1; // Indicating the game has been won
    } else if (guess < target) {
        printf("Player %d, your guess %d is too low. Try again!\n", player, guess);
    } else {
        printf("Player %d, your guess %d is too high. Try again!\n", player, guess);
    }

    // Switch to the other player and decrement the remaining guesses
    return guessNumber(target, (player == 1 ? 2 : 1), remainingGuesses - 1);
}

int main() {
    startGame();
    return 0;
}