//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_PLAYER_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
} Player;

void init_player(Player *player) {
    strcpy(player->name, "Player");
    player->score = 0;
}

int compare_players(const void *a, const void *b) {
    const Player *player_a = (const Player *)a;
    const Player *player_b = (const Player *)b;

    if (player_a->score > player_b->score) {
        return -1;
    } else if (player_a->score < player_b->score) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to the multiplayer game!\n");
    while (num_players < MAX_PLAYERS) {
        printf("Enter your name (max %d characters): ", MAX_PLAYER_NAME_LENGTH - 1);
        scanf("%s", players[num_players].name);
        players[num_players].score = 0;
        num_players++;
    }

    qsort(players, num_players, sizeof(Player), compare_players);

    for (int i = 0; i < num_players; i++) {
        printf("%d. %s: %d points\n", i + 1, players[i].name, players[i].score);
    }

    return 0;
}