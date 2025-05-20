//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

int main() {
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int current_player = 0;
    while (1) {
        for (int i = 0; i < num_players; i++) {
            if (players[i].score >= 10) {
                printf("Player %s wins!\n", players[i].name);
                return 0;
            }
        }

        int choice;
        printf("Player %s's turn.\n", players[current_player].name);
        printf("1. Roll dice\n2. Pass turn\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int dice_roll = rand() % 6 + 1;
            printf("Player %s rolled a %d.\n", players[current_player].name, dice_roll);

            if (dice_roll == 6) {
                printf("Player %s gets another turn.\n", players[current_player].name);
            } else {
                current_player = (current_player + 1) % num_players;
            }
        } else {
            current_player = (current_player + 1) % num_players;
        }
    }

    return 0;
}