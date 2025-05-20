//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_DICE 10
#define DICE_SIDES 6

typedef struct Player {
    char name[20];
    int dice[MAX_DICE];
} Player;

void roll_dice(int *dice, int num_dice, int sides) {
    int i;
    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % sides + 1;
    }
}

void print_player_dice(Player *player) {
    int i;
    printf("%s rolled:\n", player->name);
    for (i = 0; i < MAX_DICE; i++) {
        printf("Dice %d: %d\n", i + 1, player->dice[i]);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Too many players. Max allowed is %d.\n", MAX_PLAYERS);
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("\nPlayer %d:\n", i + 1);
        scanf("%s", players[i].name);

        roll_dice(players[i].dice, MAX_DICE, DICE_SIDES);
    }

    for (int i = 0; i < num_players; i++) {
        print_player_dice(&players[i]);
    }

    return 0;
}