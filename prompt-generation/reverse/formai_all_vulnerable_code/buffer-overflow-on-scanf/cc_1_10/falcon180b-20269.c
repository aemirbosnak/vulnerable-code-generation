//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_PLAYER_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
} Player;

void initPlayer(Player* player) {
    strcpy(player->name, "");
    player->score = 0;
}

void printPlayer(Player player) {
    printf("Player: %s - Score: %d\n", player.name, player.score);
}

int main() {
    int numPlayers, playerIndex;
    char playerName[MAX_PLAYER_NAME_LENGTH];
    Player players[MAX_PLAYERS];
    bool endGame = false;

    printf("Welcome to the C Cat Language Translator multiplayer game!\n");
    printf("Please enter the number of players (1-4): ");
    scanf("%d", &numPlayers);

    for (playerIndex = 0; playerIndex < numPlayers; playerIndex++) {
        printf("Enter player %d's name: ", playerIndex + 1);
        scanf("%s", playerName);
        strcpy(players[playerIndex].name, playerName);
        players[playerIndex].score = 0;
    }

    while (!endGame) {
        char input[100];
        int inputLength;
        char* token;
        int i;

        printf("Enter a sentence to translate: ");
        fgets(input, 100, stdin);
        inputLength = strlen(input);

        for (playerIndex = 0; playerIndex < numPlayers; playerIndex++) {
            players[playerIndex].score = 0;
        }

        token = strtok(input, " ");
        while (token!= NULL) {
            for (i = 0; i < numPlayers; i++) {
                if (strcasecmp(token, players[i].name) == 0) {
                    players[i].score++;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }

        for (playerIndex = 0; playerIndex < numPlayers; playerIndex++) {
            printPlayer(players[playerIndex]);
        }

        endGame = true;
        for (playerIndex = 0; playerIndex < numPlayers; playerIndex++) {
            if (players[playerIndex].score == 0) {
                endGame = false;
                break;
            }
        }
    }

    printf("Game over!\n");

    return 0;
}