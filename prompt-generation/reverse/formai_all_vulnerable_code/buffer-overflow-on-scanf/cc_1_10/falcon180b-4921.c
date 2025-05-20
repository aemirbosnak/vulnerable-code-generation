//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_CHAT_MSG_LEN 100

typedef struct {
    char name[20];
    int score;
    int health;
} Player;

Player players[MAX_PLAYERS];

void updatePlayer(Player *player, char *name, int score, int health) {
    strcpy(player->name, name);
    player->score = score;
    player->health = health;
}

void sendChatMsg(Player *sender, char *msg) {
    printf("Chat from %s: %s\n", sender->name, msg);
}

int main() {
    int numPlayers;
    char playerNames[MAX_PLAYERS][20];
    int playerScores[MAX_PLAYERS];
    int playerHealths[MAX_PLAYERS];

    srand(time(NULL));

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", playerNames[i]);
        updatePlayer(&players[i], playerNames[i], rand() % 100, rand() % 100);
    }

    while (true) {
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d: Name - %s, Score - %d, Health - %d\n", i + 1, players[i].name, players[i].score, players[i].health);
        }

        char msg[MAX_CHAT_MSG_LEN];
        printf("Enter chat message: ");
        scanf("%s", msg);
        sendChatMsg(&players[0], msg);

        for (int i = 0; i < numPlayers; i++) {
            if (players[i].health <= 0) {
                printf("Player %d has been eliminated!\n", i + 1);
                break;
            }
        }

        if (numPlayers == 1) {
            printf("Player %d is the winner!\n", 1);
            break;
        }
    }

    return 0;
}