//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

void init_player(Player* player) {
    strcpy(player->name, "Player");
    player->score = 0;
}

void print_player(const Player* player) {
    printf("%s: %d\n", player->name, player->score);
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter number of players (1-10): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
    }

    int current_player = 0;
    while (1) {
        printf("\n%s's turn:\n", players[current_player].name);
        int choice;
        printf("1. Roll dice\n2. Change name\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                int dice_roll = rand() % 6 + 1;
                players[current_player].score += dice_roll;
                printf("%s rolled a %d and scored %d points.\n", players[current_player].name, dice_roll, dice_roll);
                break;
            }
        case 2:
            {
                printf("Enter new name: ");
                scanf("%s", players[current_player].name);
                printf("%s is now known as %s.\n", players[current_player].name, players[current_player].name);
                break;
            }
        default:
            printf("Invalid choice.\n");
        }

        current_player = (current_player + 1) % num_players;

        if (current_player == 0) {
            for (int i = 0; i < num_players; i++) {
                print_player(&players[i]);
            }
        }
    }

    return 0;
}