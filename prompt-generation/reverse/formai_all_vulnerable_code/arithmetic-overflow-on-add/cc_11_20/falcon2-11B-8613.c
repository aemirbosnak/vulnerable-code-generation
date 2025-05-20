//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Initializing variables
    int player1Score = 0;
    int player2Score = 0;
    int player1Answer = 0;
    int player2Answer = 0;
    int player1Guess = 0;
    int player2Guess = 0;
    int difficulty = 1;
    int correctAnswer = 0;
    int player1Correct = 0;
    int player2Correct = 0;
    int player1Wins = 0;
    int player2Wins = 0;
    int player1Turn = 1;

    // Main loop
    while (1) {
        // Prompt players to enter their answers
        printf("Player 1, enter your answer: ");
        scanf("%d", &player1Answer);
        printf("Player 2, enter your answer: ");
        scanf("%d", &player2Answer);

        // Check answers and update scores
        correctAnswer = (player1Answer + player2Answer) / 2;
        player1Correct = correctAnswer == player1Answer? 1 : 0;
        player2Correct = correctAnswer == player2Answer? 1 : 0;

        // Update scores
        if (player1Correct) {
            player1Score++;
            if (player1Score == 5) {
                player1Wins++;
            }
        }
        if (player2Correct) {
            player2Score++;
            if (player2Score == 5) {
                player2Wins++;
            }
        }

        // Determine difficulty level
        if (player1Correct && player2Correct) {
            difficulty++;
        }
        else if (player1Correct &&!player2Correct) {
            difficulty--;
        }
        else if (!player1Correct && player2Correct) {
            difficulty--;
        }

        // Print scores and determine winner
        printf("Player 1: %d, Player 2: %d\n", player1Score, player2Score);
        if (player1Wins > player2Wins) {
            printf("Player 1 wins!\n");
        }
        else if (player2Wins > player1Wins) {
            printf("Player 2 wins!\n");
        }
        else {
            printf("It's a tie!\n");
        }

        // Determine next player's turn
        if (player1Turn == 1) {
            player1Turn = 0;
        }
        else {
            player1Turn = 1;
        }
    }
    return 0;
}