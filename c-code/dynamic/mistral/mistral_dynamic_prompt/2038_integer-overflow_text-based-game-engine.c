#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 256
#define MAX_LEVEL 100

typedef struct Player {
    char name[MAX_NAME_LEN];
    int level;
    int exp;
} Player;

int main() {
    Player players[MAX_PLAYERS];

    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; ++i) {
        printf("\nEnter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].level = 1;
        players[i].exp = i * 100;
        printf("Player %s has been created at level %d with %d EXP.\n", players[i].name, players[i].level, players[i].exp);
    }

    int input;
    while (1) {
        printf("\nChoose an action:\n1. Fight Monster\n2. Train\n3. Quit\n");
        scanf("%d", &input);

        if (input == 3) {
            printf("Thanks for playing! Goodbye.\n");
            break;
        }

        for (int i = 0; i < num_players; ++i) {
            players[i].exp += input * input * 5;
            if (players[i].exp >= players[i].level * players[i].level * 10) {
                players[i].exp -= players[i].level * players[i].level * 10;
                players[i].level++;
                printf("%s has reached level %d.\n", players[i].name, players[i].level);
            }
        }
    }

    return 0;
}
