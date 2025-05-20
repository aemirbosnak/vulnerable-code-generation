//Falcon-180B DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players, wins, losses;
    int player1Score, player2Score;
    char player1Name[20], player2Name[20];
    int choice;
    int i;

    // Initialize random seed
    srand(time(NULL));

    // Ask user for number of players
    printf("How many players are there? ");
    scanf("%d", &players);

    if (players < 2) {
        printf("There must be at least two players.\n");
        return 1;
    }

    // Ask user for player names
    for (i = 1; i <= players; i++) {
        printf("Enter player %d's name: ", i);
        scanf("%s", (player1Name + (i - 1) * 20));
    }

    // Ask user for game length
    printf("How many rounds do you want to play? ");
    scanf("%d", &wins);

    if (wins < 1) {
        printf("There must be at least one round.\n");
        return 1;
    }

    // Initialize scores
    for (i = 0; i < players; i++) {
        player1Score = 0;
        player2Score = 0;
    }

    // Play the game
    for (i = 1; i <= wins; i++) {
        printf("\nRound %d:\n", i);

        // Randomly select two players
        do {
            choice = rand() % players;
        } while (choice == 0);

        int player1 = (choice - 1) % players + 1;
        int player2 = (player1 + 1) % players;

        printf("Player 1: %s\n", player1Name + (player1 - 1) * 20);
        printf("Player 2: %s\n", player2Name + (player2 - 1) * 20);

        // Randomly select a winner
        int winner;
        do {
            winner = rand() % 2;
        } while (winner == 0);

        if (winner == 1) {
            printf("Player 1 wins!\n");
            player1Score++;
        } else {
            printf("Player 2 wins!\n");
            player2Score++;
        }
    }

    // Print final scores
    printf("\nFinal scores:\n");
    for (i = 1; i <= players; i++) {
        printf("Player %d: %d wins\n", i, player1Score);
    }

    return 0;
}