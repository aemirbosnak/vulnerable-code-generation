//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to simulate the turn of a player
int takeTurn(int player) {
    // Roll the dice
    int roll = rollDice();
    printf("Player %d rolled a %d\n", player, roll);

    return roll;
}

int main() {
    // Initialize the game variables
    int num_players;
    printf("How many players? ");
    scanf("%d", &num_players);

    int scores[num_players];
    for(int i=0; i<num_players; i++) {
        scores[i] = 0;
    }

    int current_player = 0;
    int max_score = 50;

    // Start the game
    printf("Starting the game!\n");

    while(1) {
        printf("Player %d's turn!\n", current_player+1);

        // Take the current player's turn
        int roll = takeTurn(current_player+1);
        scores[current_player] += roll;

        printf("Current player's score: %d\n", scores[current_player]);

        // Check if the current player has won
        if(scores[current_player] >= max_score) {
            printf("Player %d has won the game!\n", current_player+1);
            break;
        }

        // Move on to the next player
        current_player = (current_player + 1) % num_players;
    }

    return 0;
}