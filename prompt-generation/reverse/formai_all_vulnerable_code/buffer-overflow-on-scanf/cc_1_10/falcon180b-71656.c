//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/statvfs.h>

#define MAX_PLAYERS 4

typedef struct player {
    char name[50];
    int score;
} Player;

void menu() {
    printf("1. Start game\n");
    printf("2. Exit\n");
}

void game_over(Player players[], int winner) {
    printf("Game over!\n");
    printf("Winner: %s\n", players[winner].name);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (i == winner) {
            printf("%s: %d\n", players[i].name, players[i].score);
        } else {
            printf("%s: %d\n", players[i].name, players[i].score);
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;
    int winner;

    menu();
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
    }

    menu();
    scanf("%d", &winner);

    game_over(players, winner);

    return 0;
}