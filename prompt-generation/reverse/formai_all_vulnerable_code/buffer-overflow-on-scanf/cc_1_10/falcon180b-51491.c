//Falcon-180B DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
} Player;

void generateRandomName(char* name) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 5; i++) {
        name[i] = letters[rand() % 26];
    }
    name[5] = '\0';
}

void playRound(Player players[], int numPlayers) {
    int playerIndex = rand() % numPlayers;
    printf("Round %d winner: %s\n", numPlayers - 1, players[playerIndex].name);
    players[playerIndex].score++;
}

int main() {
    srand(time(NULL));
    int numPlayers;
    printf("How many players? (1-4): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        generateRandomName(players[i].name);
        players[i].score = 0;
    }
    int rounds = rand() % MAX_ROUNDS + 1;
    printf("Playing %d rounds...\n", rounds);
    for (int i = 0; i < rounds; i++) {
        playRound(players, numPlayers);
    }
    printf("Game over!\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    return 0;
}