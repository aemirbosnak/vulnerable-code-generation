//Falcon-180B DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 100

struct player {
    char name[50];
    int health;
};

void init_player(struct player *player) {
    strcpy(player->name, "Player");
    player->health = 100;
}

void display_player(const struct player *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS || num_players < 2) {
        printf("Invalid number of players.\n");
        return 1;
    }

    struct player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
    }

    int round = 1;
    while (round <= MAX_ROUNDS && num_players > 1) {
        printf("\nRound %d:\n", round);
        for (int i = 0; i < num_players; i++) {
            display_player(&players[i]);
        }

        int attack_player;
        printf("Enter the player you want to attack: ");
        scanf("%d", &attack_player);

        if (attack_player < 0 || attack_player >= num_players) {
            printf("Invalid player.\n");
            continue;
        }

        int defender_health = players[attack_player].health;
        players[attack_player].health -= rand() % 10 + 1;

        if (players[attack_player].health <= 0) {
            printf("Player %s has been eliminated.\n", players[attack_player].name);
            num_players--;
        }

        printf("\nPlayer %s's health: %d\n", players[attack_player].name, defender_health);

        round++;
    }

    if (num_players == 1) {
        printf("Player %s is the winner!\n", players[0].name);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}