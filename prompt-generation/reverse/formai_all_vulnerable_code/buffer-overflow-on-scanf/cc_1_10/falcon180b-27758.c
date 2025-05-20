//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void init_player(Player *p) {
    strcpy(p->name, "Player");
    p->score = 0;
}

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    Player *new_player = &players[num_players];
    init_player(new_player);
    num_players++;
}

int main() {
    int choice;

    printf("Welcome to the game!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add player\n");
        printf("2. View players\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_player();
            break;

        case 2:
            printf("\nPlayers:\n");
            for (int i = 0; i < num_players; i++) {
                printf("%s - Score: %d\n", players[i].name, players[i].score);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}