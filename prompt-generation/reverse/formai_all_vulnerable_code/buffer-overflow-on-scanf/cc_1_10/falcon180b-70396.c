//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_SCORE_COUNT 10

struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
};

void init_player(struct Player *player) {
    strcpy(player->name, "");
    player->score = 0;
}

void print_player(struct Player player) {
    printf("Name: %s, Score: %d\n", player.name, player.score);
}

int main() {
    struct Player players[MAX_PLAYERS];
    int player_count = 0;
    int choice = 0;
    char input[100];

    do {
        system("clear");
        printf("Choose an option:\n");
        printf("1. Add player\n");
        printf("2. Display players\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (player_count == MAX_PLAYERS) {
                printf("Maximum number of players reached.\n");
            } else {
                printf("Enter player name: ");
                scanf("%s", players[player_count].name);
                init_player(&players[player_count]);
                player_count++;
            }
            break;
        case 2:
            printf("Players:\n");
            for (int i = 0; i < player_count; i++) {
                print_player(players[i]);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}