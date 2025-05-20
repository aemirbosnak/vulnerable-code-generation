//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_ROUNDS 5

void display_rules() {
    printf("Welcome to 'Mystic Dice Adventure'! 🎲\n");
    printf("Each player takes turns to roll the dice (1-6).\n");
    printf("Earn points according to the number you roll! Points are:\n");
    printf("1: 1pt | 2: 2pt | 3: 3pt | 4: 4pt | 5: 5pt | 6: 6pt\n");
    printf("The player with the most points after %d rounds wins!\n\n", MAX_ROUNDS);
}

void roll_dice(int *results, int player_count) {
    for (int i = 0; i < player_count; i++) {
        results[i] = (rand() % 6) + 1; // Random number between 1 and 6
    }
}

void display_scores(int *scores, char players[MAX_PLAYERS][MAX_NAME_LENGTH], int player_count) {
    printf("\nScoreboard:\n");
    for (int i = 0; i < player_count; i++) {
        printf("%s: %d points\n", players[i], scores[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int player_count, rounds = MAX_ROUNDS;
    char players[MAX_PLAYERS][MAX_NAME_LENGTH];
    int scores[MAX_PLAYERS] = {0};

    display_rules();

    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    if(player_count < 2 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    // Get player names
    for (int i = 0; i < player_count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i]);
    }

    for (int round = 1; round <= rounds; round++) {
        printf("\n--- Round %d ---\n", round);

        int results[MAX_PLAYERS] = {0};
        roll_dice(results, player_count);

        for (int i = 0; i < player_count; i++) {
            printf("%s rolled a %d!\n", players[i], results[i]);
            scores[i] += results[i]; // Update scores
        }

        display_scores(scores, players, player_count);
    }

    // Determine Winner
    int highest_score = -1;
    int winner_index = -1;
    for (int i = 0; i < player_count; i++) {
        if (scores[i] > highest_score) {
            highest_score = scores[i];
            winner_index = i;
        }
    }

    printf("\n🎉 The winner is %s with %d points! 🎉\n", players[winner_index], highest_score);

    return 0;
}