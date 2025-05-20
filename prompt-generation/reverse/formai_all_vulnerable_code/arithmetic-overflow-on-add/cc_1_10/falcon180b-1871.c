//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_PLAYER_NAME_LENGTH 20
#define MAX_NUM_DICE 10
#define MAX_NUM_SIDES 100

typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    int numDice;
    int numSides;
} Player;

void rollDice(int numDice, int numSides) {
    int i;
    for (i = 0; i < numDice; i++) {
        int roll = rand() % numSides + 1;
        printf("Player %d rolled %d\n", i+1, roll);
    }
}

int main() {
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    if (numPlayers > MAX_PLAYERS) {
        printf("Error: Maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }

    Player players[numPlayers];
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);

        printf("Enter the number of dice for player %s: ", players[i].name);
        scanf("%d", &players[i].numDice);

        printf("Enter the number of sides for player %s: ", players[i].name);
        scanf("%d", &players[i].numSides);
    }

    srand(time(NULL));

    int winner = 0;
    int highestRoll = 0;

    while (1) {
        rollDice(players[winner].numDice, players[winner].numSides);

        if (winner == numPlayers-1) {
            winner = 0;
        } else {
            winner++;
        }

        int rollSum = 0;
        int j;
        for (j = 0; j < players[winner].numDice; j++) {
            rollSum += rand() % players[winner].numSides + 1;
        }

        if (rollSum > highestRoll) {
            highestRoll = rollSum;
        }
    }

    printf("The winner is %s with a roll of %d!\n", players[winner].name, highestRoll);

    return 0;
}