//Falcon-180B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define MAX_BETS 100

typedef struct {
    char name[20];
    int money;
} Player;

void initPlayers(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].money = 100;
    }
}

void displayPlayers(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s has $%d\n", players[i].name, players[i].money);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    initPlayers(players);
    displayPlayers(players);

    int numPlayers = 0;
    while (numPlayers < MAX_PLAYERS) {
        printf("Enter your name: ");
        scanf("%s", players[numPlayers].name);
        numPlayers++;
    }

    int currentRound = 1;
    int currentBet = 1;
    while (currentRound <= MAX_ROUNDS) {
        printf("Round %d - Bet: $%d\n", currentRound, currentBet);

        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].money <= 0) {
                printf("%s is out of money.\n", players[i].name);
                continue;
            }

            printf("%s, do you want to bet? (y/n): ", players[i].name);
            char choice;
            scanf(" %c", &choice);

            if (choice == 'y') {
                if (players[i].money >= currentBet) {
                    players[i].money -= currentBet;
                    printf("%s bets $%d.\n", players[i].name, currentBet);
                } else {
                    printf("%s doesn't have enough money to bet.\n", players[i].name);
                }
            } else {
                printf("%s chooses not to bet.\n", players[i].name);
            }
        }

        if (currentRound == MAX_ROUNDS) {
            for (int i = 0; i < MAX_PLAYERS; i++) {
                printf("%s has $%d.\n", players[i].name, players[i].money);
            }
        } else {
            currentBet *= 2;
        }

        currentRound++;
    }

    return 0;
}