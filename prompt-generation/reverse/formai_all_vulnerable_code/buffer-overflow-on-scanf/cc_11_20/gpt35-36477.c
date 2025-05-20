//FormAI DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define HAND_SIZE 5

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Declare variables
    int players, i, j, k;
    char suits[4] = {'H', 'D', 'C', 'S'};
    char card_values[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int deck_size = 52;
    int deck[52];
    int player_hands[MAX_PLAYERS][HAND_SIZE];
    int player_scores[MAX_PLAYERS];

    // Get number of players
    printf("How many players? (1-10): ");
    scanf("%d", &players);

    // Validate input
    if (players < 1 || players > 10) {
        printf("Invalid number of players.\n");
        return 1;
    }

    // Initialize deck
    for (i = 0; i < deck_size; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    for (i = 0; i < deck_size; i++) {
        j = rand() % deck_size;
        k = deck[i];
        deck[i] = deck[j];
        deck[j] = k;
    }

    // Deal cards
    for (i = 0; i < players; i++) {
        printf("Player %d's hand:\n", i+1);
        for (j = 0; j < HAND_SIZE; j++) {
            player_hands[i][j] = deck[i*HAND_SIZE+j];
            printf("%c%c ", card_values[player_hands[i][j]%13], suits[player_hands[i][j]/13]);
        }
        printf("\n");
    }

    // Calculate scores
    for (i = 0; i < players; i++) {
        player_scores[i] = 0;
        for (j = 0; j < HAND_SIZE; j++) {
            player_scores[i] += player_hands[i][j]%13 + 1;
        }
    }

    // Print scores
    printf("Scores:\n");
    for (i = 0; i < players; i++) {
        printf("Player %d: %d\n", i+1, player_scores[i]);
    }

    // Determine winner
    int max_score = player_scores[0];
    int winner = 1;
    for (i = 1; i < players; i++) {
        if (player_scores[i] > max_score) {
            max_score = player_scores[i];
            winner = i+1;
        }
    }
    printf("Player %d wins!\n", winner);

    return 0;
}