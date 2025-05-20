//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_ITEMS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    int value;
    int index;
} Item;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void printPlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %s (%d points)\n", i+1, players[i].name, players[i].score);
    }
}

void initializeItems(Item items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        items[i].value = rand() % 100;
        items[i].index = i;
    }
}

void printItems(Item items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: %d points\n", i+1, items[i].value);
    }
}

void distributeItems(Item items[], int numItems, Player players[], int numPlayers) {
    for (int i = 0; i < numItems; i++) {
        int maxScore = 0;
        int maxPlayerIndex = -1;
        for (int j = 0; j < numPlayers; j++) {
            if (players[j].score > maxScore) {
                maxScore = players[j].score;
                maxPlayerIndex = j;
            }
        }
        players[maxPlayerIndex].score += items[i].value;
        items[i].index = maxPlayerIndex;
    }
}

void main() {
    int numPlayers, numItems;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return;
    }
    printf("Enter number of items: ");
    scanf("%d", &numItems);
    if (numItems < 2 || numItems > MAX_ITEMS) {
        printf("Invalid number of items.\n");
        return;
    }

    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);

    Item items[MAX_ITEMS];
    initializeItems(items, numItems);

    printf("\nPlayers:\n");
    printPlayers(players, numPlayers);

    printf("\nItems:\n");
    printItems(items, numItems);

    distributeItems(items, numItems, players, numPlayers);

    printf("\nPlayers after distribution:\n");
    printPlayers(players, numPlayers);
}