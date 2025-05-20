//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define MIN_ROLL 1
#define MAX_ROLL 6
#define WIN_NUM 67

typedef struct player {
    int position;
    char name[20];
} player;

void print_players(player players[]) {
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %s is at position %d\n", players[i].name, players[i].position);
    }
}

int roll_dice() {
    int roll;
    roll = rand() % (MAX_ROLL + 1);
    return roll;
}

int main() {
    int i, player_index, roll;
    player players[NUM_PLAYERS];
    int current_player = 0;

    srand(time(NULL));

    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player name %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
    }

    while (1) {
        print_players(players);
        roll = roll_dice();
        printf("Player %s rolled a %d\n", players[current_player].name, roll);

        players[current_player].position += roll;
        if (players[current_player].position >= WIN_NUM) {
            printf("%s has won!\n", players[current_player].name);
            break;
        }

        current_player = (current_player + 1) % NUM_PLAYERS;
    }

    return 0;
}