//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define TARGET_NUMBER 50

// Function to guess the number
void guessNumber(int player, int guess, int *secretNumber, int turns) {
    if (turns > 0) {
        if (guess == *secretNumber) {
            printf("Player %d guessed the correct number: %d!\n", player + 1, *secretNumber);
        } else {
            if (guess < *secretNumber) {
                printf("Player %d guessed %d. Too low! (%d turns left)\n", player + 1, guess, turns - 1);
            } else {
                printf("Player %d guessed %d. Too high! (%d turns left)\n", player + 1, guess, turns - 1);
            }

            // Allow next player to guess
            int nextPlayer = (player + 1) % MAX_PLAYERS;
            int nextGuess;

            printf("Player %d, it's your turn! Please enter your guess: ", nextPlayer + 1);
            scanf("%d", &nextGuess);
            guessNumber(nextPlayer, nextGuess, secretNumber, turns - 1);
        }
    } else {
        printf("Player %d ran out of turns! The secret number was %d.\n", player + 1, *secretNumber);
    }
}

// Function to initiate the game
void startGame() {
    int secretNumber = rand() % TARGET_NUMBER + 1;
    int turns = 5;
    int firstPlayer = 0;
    int firstGuess;

    printf("Welcome to the Multiplayer Number Guessing Game!\n");
    printf("There are %d players. The secret number is between 1 and %d.\n", MAX_PLAYERS, TARGET_NUMBER);
    printf("Player %d, please enter your guess: ", firstPlayer + 1);
    scanf("%d", &firstGuess);

    guessNumber(firstPlayer, firstGuess, &secretNumber, turns);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    startGame();
    
    return 0;
}