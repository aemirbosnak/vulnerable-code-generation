//FormAI DATASET v1.0 Category: Table Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seeding the random number generator with the current time

    int board[10]; // The board of the game will have 10 slots
    for (int i = 0; i < 10; ++i) {
        board[i] = i; // Filling the board with number from 0 to 9
    }

    int player_turn = rand() % 2; // Randomly selecting which player will start first
    int player_scores[2] = {0}; // Initializing the players scores to 0

    while (1) { // The game loop
        printf("Player %d, it's your turn!\n", player_turn);

        int selected_slot;
        do {
            printf("Choose a slot to play (0-9): ");
            scanf("%d", &selected_slot);
        } while (selected_slot < 0 || selected_slot > 9);

        int score = (rand() % 10) + 1; // Randomly selecting a score for the player
        printf("You scored %d points!\n", score);

        // Updating the board and the player's score
        player_scores[player_turn] += score;
        board[selected_slot] = player_turn;
        printf("Player %d's score: %d\n", player_turn, player_scores[player_turn]);

        // Checking if there's a winner
        int winner = -1;
        for (int i = 0; i < 10; ++i) {
            if (board[i] != i) {
                winner = board[i];
                break;
            }
        }
        if (winner != -1) {
            printf("Player %d wins with a score of %d!\n", winner, player_scores[winner]);
            break;
        }

        // Switching turns
        player_turn = !player_turn;
    }

    return 0;
}