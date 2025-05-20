//GEMINI-pro DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLAYERS 4
#define NUM_ROUNDS 10

struct player {
    char name[20];
    int wins;
    int losses;
    int draws;
};

int main() {
    // Create the players
    struct player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].wins = 0;
        players[i].losses = 0;
        players[i].draws = 0;
    }

    // Play the rounds
    for (int i = 0; i < NUM_ROUNDS; i++) {
        // Get the players' choices
        int choices[NUM_PLAYERS];
        for (int j = 0; j < NUM_PLAYERS; j++) {
            printf("%s, choose rock (1), paper (2), or scissors (3): ", players[j].name);
            scanf("%d", &choices[j]);
        }

        // Determine the winners
        int winners[NUM_PLAYERS];
        for (int j = 0; j < NUM_PLAYERS; j++) {
            winners[j] = 0;
        }
        for (int j = 0; j < NUM_PLAYERS; j++) {
            for (int k = 0; k < NUM_PLAYERS; k++) {
                if (j == k) {
                    continue;
                }
                if ((choices[j] == 1 && choices[k] == 3) || (choices[j] == 2 && choices[k] == 1) || (choices[j] == 3 && choices[k] == 2)) {
                    winners[j]++;
                } else if ((choices[j] == 3 && choices[k] == 1) || (choices[j] == 1 && choices[k] == 2) || (choices[j] == 2 && choices[k] == 3)) {
                    winners[k]++;
                } else {
                    winners[j]++;
                    winners[k]++;
                }
            }
        }

        // Update the players' stats
        for (int j = 0; j < NUM_PLAYERS; j++) {
            if (winners[j] > 0) {
                players[j].wins++;
            } else if (winners[j] < 0) {
                players[j].losses++;
            } else {
                players[j].draws++;
            }
        }
    }

    // Print the results
    printf("--------------------------------------------------\n");
    printf("Player\tWins\tLosses\tDraws\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s\t%d\t%d\t%d\n", players[i].name, players[i].wins, players[i].losses, players[i].draws);
    }

    return 0;
}