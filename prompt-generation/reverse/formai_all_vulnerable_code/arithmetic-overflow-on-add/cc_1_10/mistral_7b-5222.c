//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define DICE_SIDES 6

typedef struct player {
    int name;
    int rolls[3];
    int total;
} player;

void roll_dice(int *dice, int sides) {
    int i;
    for (i = 0; i < 3; i++) {
        dice[i] = rand() % sides + 1;
    }
}

void print_results(player players[], int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("\nPlayer %d:\n", players[i].name + 1);
        printf("Rolls: ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", players[i].rolls[j]);
        }
        printf("\nTotal: %d\n", players[i].total);
    }
}

int main() {
    srand(time(NULL));

    player players[NUM_PLAYERS];

    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].name = i;
        roll_dice(players[i].rolls, DICE_SIDES);
        for (int j = 0; j < 3; j++) {
            players[i].total += players[i].rolls[j];
        }
    }

    print_results(players, NUM_PLAYERS);

    int highest_total = players[0].total;
    int index_highest_total = 0;

    for (int i = 1; i < NUM_PLAYERS; i++) {
        if (players[i].total > highest_total) {
            highest_total = players[i].total;
            index_highest_total = i;
        }
    }

    printf("\nPlayer %d wins with a total of %d!\n", players[index_highest_total].name + 1, highest_total);

    return 0;
}