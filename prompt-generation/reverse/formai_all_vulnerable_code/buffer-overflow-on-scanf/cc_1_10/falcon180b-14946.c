//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4

typedef struct {
    char name[20];
    int score;
    double conversion_rate;
} Player;

void initialize_players(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
        players[i].conversion_rate = 1.0;
    }
}

int main() {
    Player players[MAX_PLAYERS];
    initialize_players(players);

    int num_players;
    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    char input[50];
    while (1) {
        printf("\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s's turn: ", players[i].name);
            scanf("%s", input);

            if (strcmp(input, "convert") == 0) {
                printf("Enter the value to convert: ");
                scanf("%lf", &players[i].conversion_rate);
            } else if (strcmp(input, "score") == 0) {
                printf("Your score is: %d\n", players[i].score);
            } else {
                printf("Invalid command.\n");
            }
        }
    }

    return 0;
}