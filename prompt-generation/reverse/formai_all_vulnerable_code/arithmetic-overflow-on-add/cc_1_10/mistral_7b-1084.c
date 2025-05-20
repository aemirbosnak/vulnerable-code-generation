//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_ROUNDS 10
#define MIN_ROLL 1
#define MAX_ROLL 6

typedef struct {
    int player_num;
    int total_score;
} player_t;

void roll_dice(int *dice, int num_dice) {
    int i;
    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % (MAX_ROLL + 1) + MIN_ROLL;
    }
}

void print_scores(player_t players[]) {
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: %d\n", players[i].player_num, players[i].total_score);
    }
}

int main() {
    srand(time(NULL));
    player_t players[NUM_PLAYERS];
    int i, j, round;

    for (i = 0; i < NUM_PLAYERS; i++) {
        players[i].player_num = i + 1;
        players[i].total_score = 0;
    }

    for (round = 0; round < NUM_ROUNDS; round++) {
        int dice[NUM_PLAYERS];
        for (i = 0; i < NUM_PLAYERS; i++) {
            roll_dice(dice, 1);
            players[i].total_score += dice[i];
        }

        printf("Round %d:\n", round + 1);
        print_scores(players);
    }

    printf("\nGame Over! Player %d wins with a total score of %d.\n",
        players[find_max_score(players, NUM_PLAYERS)].player_num,
        players[find_max_score(players, NUM_PLAYERS)].total_score);

    return 0;
}

int find_max_score(player_t players[], int num_players) {
    int max_index = 0;
    int max_score = players[0].total_score;

    for (int i = 1; i < num_players; i++) {
        if (players[i].total_score > max_score) {
            max_score = players[i].total_score;
            max_index = i;
        }
    }

    return max_index;
}