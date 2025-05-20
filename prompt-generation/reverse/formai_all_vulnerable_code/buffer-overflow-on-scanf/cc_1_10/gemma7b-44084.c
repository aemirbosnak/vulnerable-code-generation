//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_NUM_Players 4

typedef struct Player {
    char name[20];
    int score;
    int spaceUsed;
} Player;

void calculateSpaceUsed(Player *player) {
    struct stat stat_buf;
    stat(player->name, &stat_buf);
    player->spaceUsed = stat_buf.st_size;
}

int main() {
    Player players[MAX_NUM_Players];
    int numPlayers = 0;

    // Initialize players
    for (int i = 0; i < MAX_NUM_Players; i++) {
        players[i].name[0] = '\0';
        players[i].score = 0;
        players[i].spaceUsed = 0;
    }

    // Get number of players
    printf("Enter the number of players (up to %d): ", MAX_NUM_Players);
    scanf("%d", &numPlayers);

    // Populate players
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Calculate space used for each player
    for (int i = 0; i < numPlayers; i++) {
        calculateSpaceUsed(&players[i]);
    }

    // Print results
    printf("Here are the results:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s has used %d bytes of space.\n", players[i].name, players[i].spaceUsed);
    }

    return 0;
}