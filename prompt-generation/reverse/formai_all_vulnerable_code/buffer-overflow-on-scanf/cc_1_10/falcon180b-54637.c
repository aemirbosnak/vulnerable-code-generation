//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 3
#define DICE_SIDES 6
#define MAX_PLAYERS 4

typedef struct {
    int value;
    char name[20];
} player_t;

void roll_dice(int num_dice, int sides) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < num_dice; i++) {
        printf("Rolling dice %d... ", i + 1);
        for (j = 1; j <= sides; j++) {
            printf("%d ", rand() % sides + 1);
        }
        printf("\n");
    }
}

void play_game(player_t players[], int num_players) {
    int i, j, max_score = 0, max_index = 0;
    for (i = 0; i < num_players; i++) {
        printf("Player %s, your score is: ", players[i].name);
        roll_dice(NUM_DICE, DICE_SIDES);
        int score = 0;
        for (j = 0; j < NUM_DICE; j++) {
            score += rand() % DICE_SIDES + 1;
        }
        printf("%d\n", score);
        if (score > max_score) {
            max_score = score;
            max_index = i;
        }
    }
    printf("The winner is %s with a score of %d!\n", players[max_index].name, max_score);
}

int main() {
    player_t players[MAX_PLAYERS];
    int num_players;
    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_players);
    printf("Enter the names of the players:\n");
    for (int i = 0; i < num_players; i++) {
        scanf("%s", players[i].name);
    }
    play_game(players, num_players);
    return 0;
}