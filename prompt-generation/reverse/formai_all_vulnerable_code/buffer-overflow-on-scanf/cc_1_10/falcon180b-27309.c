//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
    int wins;
    int losses;
    int ties;
} Player;

void swap(Player* a, Player* b) {
    Player temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    const Player* playerA = a;
    const Player* playerB = b;

    if (playerA->score > playerB->score) {
        return -1;
    } else if (playerA->score < playerB->score) {
        return 1;
    } else {
        return 0;
    }
}

void printPlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d (%d-%d-%d)\n", players[i].name, players[i].score, players[i].wins, players[i].losses, players[i].ties);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    while (numPlayers < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", players[numPlayers].name);
        numPlayers++;
    }

    int numRounds = 0;
    while (numRounds < MAX_ROUNDS) {
        int roundWins[MAX_PLAYERS] = {0};

        for (int i = 0; i < numPlayers - 1; i++) {
            for (int j = i + 1; j < numPlayers; j++) {
                int player1Score = rand() % 21 + 1;
                int player2Score = rand() % 21 + 1;

                if (player1Score > player2Score) {
                    players[i].score++;
                    players[j].score--;
                } else if (player2Score > player1Score) {
                    players[j].score++;
                    players[i].score--;
                } else {
                    players[i].ties++;
                    players[j].ties++;
                }

                roundWins[i]++;
            }
        }

        numRounds++;

        printf("Round %d results:\n", numRounds);
        for (int i = 0; i < numPlayers; i++) {
            printf("%s: %d (%d-%d-%d)\n", players[i].name, players[i].score, players[i].wins, players[i].losses, players[i].ties);
        }

        qsort(players, numPlayers, sizeof(Player), compare);

        printf("Current standings:\n");
        printPlayers(players, numPlayers);

        for (int i = 0; i < numPlayers; i++) {
            roundWins[i] = 0;
        }
    }

    return 0;
}