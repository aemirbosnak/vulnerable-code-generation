//FormAI DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LENGTH 15
#define MAX_BINARY_LENGTH 32

typedef struct {
    char name[MAX_NAME_LENGTH+1];
    int score;
} Player;

int convertToDecimal(char binary[]) {
    int decimal = 0, i;
    int binary_length = strlen(binary);
    for (i = 0; i < binary_length; i++) {
        if (binary[i] == '1') {
            decimal += (int)pow(2.0, binary_length-i-1);
        }
    }
    return decimal;
}

void printBinary(char binary[]) {
    int binary_length = strlen(binary);
    int i;
    for (i = 0; i < binary_length; i++) {
        printf("%c ", binary[i]);
    }
    printf("\n");
}

void printPlayer(Player player) {
    printf("%s: %d\n", player.name, player.score);
}

void printLeaderboard(Player players[], int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("%d. ", i+1);
        printPlayer(players[i]);
    }
}

int main() {
    int i, num_players, max_score = 0;
    Player players[MAX_PLAYERS];
    char binary[MAX_BINARY_LENGTH+1];

    printf("Welcome to the Binary Converter game!\n");

    // Get number of players
    do {
        printf("How many players? (1-%d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    } while (num_players < 1 || num_players > MAX_PLAYERS);

    // Get player names
    for (i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Start game
    printf("The game has started!\n");
    while (1) {
        // Ask for binary input
        printf("Enter a binary number (q to quit): ");
        scanf("%s", binary);

        if (!strcmp(binary, "q")) {
            break;
        }

        // Convert binary to decimal
        int decimal = convertToDecimal(binary);
        printf("Decimal equivalent: %d\n", decimal);

        // Update scores
        for (i = 0; i < num_players; i++) {
            if (!strcmp(players[i].name, "Computer")) {
                players[i].score += rand() % 100;
            } else {
                int score;
                printf("%s, enter your score: ", players[i].name);
                scanf("%d", &score);
                players[i].score += score;
            }
        }

        // Print updated leaderboard
        printLeaderboard(players, num_players);

        // Check for winner(s)
        int num_winners = 0;
        for (i = 0; i < num_players; i++) {
            if (players[i].score > max_score) {
                max_score = players[i].score;
                num_winners = 1;
            } else if (players[i].score == max_score) {
                num_winners++;
            }
        }

        if (num_winners == 1) {
            for (i = 0; i < num_players; i++) {
                if (players[i].score == max_score) {
                    printf("Winner: %s!\n", players[i].name);
                    break;
                }
            }
            break;
        } else if (num_winners > 1) {
            printf("Tie! There are %d winners.\n", num_winners);
        }
    }

    return 0;
}