//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

struct player {
    char name[MAX_NAME_LENGTH];
    int score;
};

int main() {
    struct player players[MAX_PLAYERS];
    int numPlayers;
    int round = 1;
    int i, j, k;
    int n = 1;

    srand(time(0)); // seed for random number generator

    /**
     * Get number of players
     */
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 2 || numPlayers > 4) {
        printf("Please enter a valid number of players (2-4): ");
        scanf("%d", &numPlayers);
    }

    /**
     * Get player names
     */
    for (i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    /**
     * Play the game
     */
    while (round <= 10) {
        printf("========================\n");
        printf("        Round %d\n", round);
        printf("========================\n");

        for (i = 0; i < numPlayers; i++) {
            printf("%s's turn.\n", players[i].name);
            printf("Press enter to roll.\n");
            getchar(); // flush input buffer
            getchar();
            int roll = rand() % 6 + 1;

            printf("\n%s rolled a %d.\n", players[i].name, roll);

            if (roll == 1) {
                printf("%s's turn is over.\n", players[i].name);
            } else {
                players[i].score += roll;
                printf("%s's score is now %d.\n", players[i].name, players[i].score);
            }
        }

        /**
         * Sort players by score (uses bubble sort)
         */
        for (j = 0; j < numPlayers - 1; j++) {
            for (k = 0; k < numPlayers - j - 1; k++) {
                if (players[k].score < players[k + 1].score) {
                    struct player temp = players[k];
                    players[k] = players[k + 1];
                    players[k + 1] = temp;
                }
            }
        }

        /**
         * Display scoreboard
         */
        printf("\n========================\n");
        printf("       Scoreboard\n");
        printf("========================\n");
        for (i = 0; i < numPlayers; i++) {
            printf("%d. %s - %d\n", i + 1, players[i].name, players[i].score);
        }
        printf("\n");

        round++;
    }

    /**
     * Declare winner
     */
    printf("The winner is %s with a score of %d!\n", players[0].name, players[0].score);

    return 0;
}