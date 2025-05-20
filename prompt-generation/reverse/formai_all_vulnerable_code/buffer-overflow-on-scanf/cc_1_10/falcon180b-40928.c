//Falcon-180B DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 10
#define MAX_SCORES 10

typedef struct {
    char name[20];
    int score;
} Player;

void generateRandomName(char* name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        name[i] = rand() % 26 + 'a';
    }
    name[strlen(name)] = '\0';
}

int main() {
    int numPlayers, numRounds, i, j;
    Player players[MAX_PLAYERS];
    int scores[MAX_PLAYERS][MAX_ROUNDS];

    printf("Enter number of players (max %d): ", MAX_PLAYERS - 1);
    scanf("%d", &numPlayers);

    srand(time(NULL));
    for (i = 0; i < numPlayers; i++) {
        generateRandomName(players[i].name);
        players[i].score = 0;
    }

    printf("Enter number of rounds (max %d): ", MAX_ROUNDS - 1);
    scanf("%d", &numRounds);

    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < numRounds; j++) {
            scores[i][j] = rand() % 101;
            printf("%s scored %d points in round %d\n", players[i].name, scores[i][j], j + 1);
        }
    }

    for (i = 0; i < numPlayers; i++) {
        printf("Player %s scored a total of %d points\n", players[i].name, scores[i][numRounds - 1]);
    }

    return 0;
}