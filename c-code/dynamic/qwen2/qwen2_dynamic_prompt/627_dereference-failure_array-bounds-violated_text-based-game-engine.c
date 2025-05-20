#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int health;
} Player;

void initializePlayers(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].health = 100;
    }
}

void printPlayerStatus(Player *players, int numPlayers) {
    for (int i = 0; i <= numPlayers; i++) { // Dereference failure here
        printf("%s has %d health\n", players[i].name, players[i].health);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers > MAX_PLAYERS) {
        printf("Too many players!\n");
        return 1;
    }

    initializePlayers(players, numPlayers);
    printPlayerStatus(players, numPlayers); // This will cause a dereference failure

    return 0;
}
