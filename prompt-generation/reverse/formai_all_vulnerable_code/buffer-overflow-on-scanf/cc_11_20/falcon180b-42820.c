//Falcon-180B DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(0));

    // Define game variables
    int playerScore = 0;
    int computerScore = 0;
    int round = 0;

    // Define game settings
    const int MAX_ROUNDS = 10;
    const int WIN_SCORE = 5;

    // Print game instructions
    printf("Welcome to the Rock-Paper-Scissors Game!\n");
    printf("You will play against the computer.\n");
    printf("The first player to reach %d points wins!\n", WIN_SCORE);

    // Play game
    while (round < MAX_ROUNDS) {
        // Computer's turn
        int computerPlay = rand() % 3;
        printf("Computer plays: ");
        if (computerPlay == 0) {
            printf("Rock\n");
        } else if (computerPlay == 1) {
            printf("Paper\n");
        } else {
            printf("Scissors\n");
        }

        // Player's turn
        int playerPlay;
        do {
            printf("Player, enter your play (0 for Rock, 1 for Paper, 2 for Scissors): ");
            scanf("%d", &playerPlay);
        } while (playerPlay < 0 || playerPlay > 2);

        // Determine winner
        if (playerPlay == computerPlay) {
            printf("It's a tie! Try again.\n");
        } else if ((playerPlay == 0 && computerPlay == 2) ||
                   (playerPlay == 1 && computerPlay == 0) ||
                   (playerPlay == 2 && computerPlay == 1)) {
            printf("You win! You get 1 point.\n");
            playerScore++;
        } else {
            printf("Computer wins! Computer gets 1 point.\n");
            computerScore++;
        }

        // Print scores
        printf("\nScore: Player - %d, Computer - %d\n", playerScore, computerScore);

        // Check for game over
        if (playerScore == WIN_SCORE) {
            printf("\nCongratulations! You win the game!\n");
            break;
        } else if (computerScore == WIN_SCORE) {
            printf("\nSorry, you lose the game.\n");
            break;
        }

        // Increment round
        round++;
    }

    // Print final scores
    printf("\nFinal score: Player - %d, Computer - %d\n", playerScore, computerScore);

    return 0;
}