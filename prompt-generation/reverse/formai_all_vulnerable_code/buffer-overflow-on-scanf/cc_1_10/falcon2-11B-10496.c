//Falcon2-11B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int generateRandomNumber() {
    srand(time(0));
    return rand() % 10 + 1;
}

// Function to display the current score of a player
void displayScore(int score) {
    printf("Score: %d\n", score);
}

// Function to play a game of Guess the Number
int playGame() {
    int player1Score = 0;
    int player2Score = 0;
    int randomNumber;
    
    // Generate a random number
    randomNumber = generateRandomNumber();
    
    printf("Player 1, guess a number between 1 and 10.\n");
    
    // Play the game
    while (1) {
        // Player 1's turn
        printf("Player 1, guess the number: ");
        int player1Guess;
        scanf("%d", &player1Guess);
        
        if (player1Guess == randomNumber) {
            player1Score++;
            printf("Correct! Player 1's score is %d.\n", player1Score);
        } else {
            printf("Incorrect! Player 1's score is %d.\n", player1Score);
        }
        
        // Player 2's turn
        printf("Player 2, guess the number: ");
        int player2Guess;
        scanf("%d", &player2Guess);
        
        if (player2Guess == randomNumber) {
            player2Score++;
            printf("Correct! Player 2's score is %d.\n", player2Score);
        } else {
            printf("Incorrect! Player 2's score is %d.\n", player2Score);
        }
        
        if (player1Score == 1 && player2Score == 1) {
            printf("Game over! Player 1 wins!\n");
            return 1;
        } else if (player1Score > 1 && player2Score > 1) {
            printf("Game over! Draw!\n");
            return 0;
        }
    }
}

// Main function
int main() {
    int score;
    while (1) {
        score = playGame();
        if (score == 1) {
            printf("Player 1 wins!\n");
            break;
        } else if (score == 0) {
            printf("Draw!\n");
            break;
        }
    }
    
    return 0;
}