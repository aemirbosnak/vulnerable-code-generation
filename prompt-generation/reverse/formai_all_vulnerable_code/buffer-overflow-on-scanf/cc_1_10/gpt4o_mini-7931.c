//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

void startGame(int player1[], int player2[], int secretNumber);
void displayScores(int player1[], int player2[]);

int main() {
    int player1[2] = {0, 0}; // holds [attempts, score]
    int player2[2] = {0, 0}; // holds [attempts, score]
    int secretNumber;

    // Seed the random number generator
    srand(time(NULL));
    // Generate a secret number between 1 and 100
    secretNumber = rand() % 100 + 1;

    printf("Welcome to Number Guessing Duel!\n");
    printf("Two players will take turns to guess the secret number between 1 and 100.\n");
    
    startGame(player1, player2, secretNumber);
    return 0;
}

void startGame(int player1[], int player2[], int secretNumber) {
    int guess;
    int currentPlayer = 1; // 1 for player 1, 2 for player 2
    int attempts = 0;

    while (attempts < MAX_TRIES) {
        printf("\nPlayer %d's turn. You have %d attempts remaining.\n", currentPlayer, MAX_TRIES - attempts);
        printf("Enter your guess: ");
        
        // User input validation
        while (scanf("%d", &guess) != 1) {
            while(getchar() != '\n'); // clear invalid input
            printf("Invalid input. Please enter an integer between 1 and 100: ");
        }

        // Increment attempt count for the current player
        if (currentPlayer == 1) {
            player1[0]++;
        } else {
            player2[0]++;
        }
        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Please guess a number between 1 and 100.\n");
            continue;
        }

        if (guess == secretNumber) {
            printf("Player %d wins! The secret number was %d.\n", currentPlayer, secretNumber);
            if (currentPlayer == 1) {
                player1[1]++;
            } else {
                player2[1]++;
            }
            displayScores(player1, player2);
            return;
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    printf("Game over! The secret number was %d. No one guessed it in time.\n", secretNumber);
    displayScores(player1, player2);
}

void displayScores(int player1[], int player2[]) {
    printf("\nFinal Scores:\n");
    printf("Player 1: Attempts = %d, Wins = %d\n", player1[0], player1[1]);
    printf("Player 2: Attempts = %d, Wins = %d\n", player2[0], player2[1]);
    printf("Thank you for playing Number Guessing Duel!\n");
}