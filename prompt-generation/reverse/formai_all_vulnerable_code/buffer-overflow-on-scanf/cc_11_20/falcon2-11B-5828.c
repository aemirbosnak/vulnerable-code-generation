//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4

typedef struct Player {
    int chips;
    int hand[5];
    int pot;
    int bet;
} Player;

int main() {
    Player players[MAX_PLAYERS];
    srand(time(NULL));

    printf("Welcome to Curious Poker!\n");
    printf("Number of players: ");
    int numPlayers = scanf("%d", &players[0].chips);

    if (numPlayers > MAX_PLAYERS) {
        printf("Too many players! Maximum is %d.\n", MAX_PLAYERS);
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i + 1);
        printf("Chips: %d\n", players[i].chips);
    }

    printf("Dealing cards...\n");
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].hand[j] = rand() % 13 + 1;
        }
    }

    printf("Dealing flop...\n");
    int flop[3] = {rand() % 13 + 1, rand() % 13 + 1, rand() % 13 + 1};

    printf("Dealing turn...\n");
    int turn = rand() % 13 + 1;

    printf("Dealing river...\n");
    int river = rand() % 13 + 1;

    printf("Flop: %d, %d, %d\n", flop[0], flop[1], flop[2]);
    printf("Turn: %d\n", turn);
    printf("River: %d\n", river);

    printf("Showdown time!\n");
    for (int i = 0; i < numPlayers; i++) {
        int bestHand = 0;
        for (int j = 0; j < 5; j++) {
            if (players[i].hand[j] > bestHand) {
                bestHand = players[i].hand[j];
            }
        }

        printf("Player %d has hand: %d, %d, %d, %d, %d\n", i + 1, flop[0], flop[1], flop[2], turn, river);
        if (bestHand == flop[0] || bestHand == flop[1] || bestHand == flop[2] || bestHand == turn || bestHand == river) {
            printf("Player %d wins with straight or flush!\n", i + 1);
            players[i].chips += (bestHand == flop[0] && bestHand == flop[1] && bestHand == flop[2])? 2 : 1;
        }
        else {
            printf("Player %d wins with highest card!\n", i + 1);
            players[i].chips += (bestHand == turn && bestHand == river)? 2 : 1;
        }
    }

    printf("Final chip counts:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i + 1, players[i].chips);
    }

    return 0;
}