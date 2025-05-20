//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 100
#define MAX_NUM_DICE 100
#define MAX_NUM_SIDES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_dice;
    int num_sides;
} Player;

void roll_dice(int num_dice, int num_sides) {
    int i, result;

    for (i = 0; i < num_dice; i++) {
        result = rand() % num_sides + 1;
        printf("%d ", result);
    }
    printf("\n");
}

void play_game(Player players[], int num_players) {
    int i, j, num_dice, num_sides;

    for (i = 0; i < num_players; i++) {
        printf("Player %d, %s, how many dice do you want to roll? ", i + 1, players[i].name);
        scanf("%d", &num_dice);

        printf("Player %d, %s, how many sides do you want on each die? ", i + 1, players[i].name);
        scanf("%d", &num_sides);

        roll_dice(num_dice, num_sides);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players, i;

    srand(time(NULL));

    printf("How many players are there? ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Player %d, enter your name: ", i + 1);
        scanf("%s", players[i].name);
    }

    play_game(players, num_players);

    return 0;
}