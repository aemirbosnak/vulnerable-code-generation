//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of players and the number of rounds
#define NUM_PLAYERS 4
#define NUM_ROUNDS 10

// Define the maximum number of chips each player can have at any time
#define MAX_CHIPS 100

// Define the starting number of chips for each player
#define STARTING_CHIPS 10

// Define the value of a chip for each round
#define CHIP_VALUE 2

// Define a struct for a player
typedef struct Player {
    int id;
    int chips;
} Player;

// Function to initialize a player with a given ID and starting number of chips
Player initializePlayer(int id) {
    Player player;
    player.id = id;
    player.chips = STARTING_CHIPS;
    return player;
}

// Function to simulate a round of the game, where each player bets and the winner takes all
void playRound(Player* players) {
    int bets[NUM_PLAYERS];

    // Get each player's bet for this round
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d, how many chips would you like to bet (maximum %d)? ", players[i].id, players[i].chips);
        scanf("%d", &bets[i]);

        // Make sure the bet is valid (less than or equal to the player's number of chips)
        while (bets[i] > players[i].chips) {
            printf("Invalid bet, please enter a value less than or equal to %d: ", players[i].chips);
            scanf("%d", &bets[i]);
        }
        players[i].chips -= bets[i];
    }

    // Determine the winner of this round
    int maxBet = 0;
    int winner = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (bets[i] > maxBet) {
            maxBet = bets[i];
            winner = i;
        }
    }

    // Distribute the chips to the winner
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (i == winner) {
            players[i].chips += maxBet * NUM_PLAYERS * CHIP_VALUE;
        }
    }
}

// Function to display the current state of the game (number of chips for each player)
void displayState(Player* players) {
    printf("Current state of the game:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d has %d chips.\n", players[i].id, players[i].chips);
    }
}

int main() {
    Player players[NUM_PLAYERS];

    // Initialize the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i] = initializePlayer(i + 1);
    }

    // Play the rounds of the game
    for (int i = 0; i < NUM_ROUNDS; i++) {
        printf("\nRound %d:\n", i + 1);
        playRound(players);
        displayState(players);
    }

    // Determine the winner and display the final state of the game
    int winner = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].chips > players[winner].chips) {
            winner = i;
        }
    }
    printf("\nPlayer %d is the winner with %d chips!\n", players[winner].id, players[winner].chips);

    return 0;
}