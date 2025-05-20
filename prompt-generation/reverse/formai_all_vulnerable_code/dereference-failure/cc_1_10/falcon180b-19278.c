//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_TURN_TIME 10

typedef struct {
    int id;
    char name[20];
    int score;
} Player;

void init_player(Player *player, int id, char *name) {
    player->id = id;
    strncpy(player->name, name, 20);
    player->score = 0;
}

int main() {
    srand(time(NULL));

    int num_players = rand() % MAX_PLAYERS + 1;
    Player *players = malloc(num_players * sizeof(Player));

    for (int i = 0; i < num_players; i++) {
        int id = i + 1;
        char name[20];
        sprintf(name, "Player %d", id);
        init_player(&players[i], id, name);
    }

    int current_player = 0;
    int turn_time = MAX_TURN_TIME;

    while (turn_time > 0) {
        printf("Turn %d (%ds)\n", current_player + 1, turn_time);
        for (int i = 0; i < num_players; i++) {
            if (i == current_player) {
                printf("%s (You)\n", players[i].name);
            } else {
                printf("%s\n", players[i].name);
            }
        }

        int choice;
        scanf("%d", &choice);

        if (choice < 1 || choice > num_players) {
            printf("Invalid choice.\n");
            continue;
        }

        if (choice!= current_player) {
            players[current_player].score++;
        }

        current_player = (current_player + 1) % num_players;
        turn_time--;
    }

    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    free(players);
    return 0;
}