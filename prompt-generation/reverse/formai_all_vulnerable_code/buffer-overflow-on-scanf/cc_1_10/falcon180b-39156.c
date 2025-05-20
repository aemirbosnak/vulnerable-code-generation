//Falcon-180B DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

typedef struct {
    char name[20];
    int score;
} player_t;

void print_scoreboard(player_t players[], int num_players) {
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s: %d\n", i+1, players[i].name, players[i].score);
    }
}

int roll_dice() {
    return rand() % 6 + 1;
}

void play_round(player_t players[], int num_players) {
    int dice_roll;
    int max_roll = 0;
    int max_player_index = 0;

    for (int i = 0; i < num_players; i++) {
        printf("%s's turn:\n", players[i].name);
        dice_roll = roll_dice();
        printf("Rolled %d\n", dice_roll);

        if (dice_roll > max_roll) {
            max_roll = dice_roll;
            max_player_index = i;
        }
    }

    printf("Max roll was %d by %s\n", max_roll, players[max_player_index].name);
    players[max_player_index].score++;
}

int main() {
    srand(time(NULL));

    player_t players[MAX_PLAYERS] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}, {"Dave", 0}};
    int num_players = 3;

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name:\n", i+1);
        scanf("%s", players[i].name);
    }

    for (int i = 0; i < MAX_ROUNDS; i++) {
        play_round(players, num_players);
        print_scoreboard(players, num_players);
    }

    return 0;
}