//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MIN_DICE 1
#define MAX_DICE 6
#define MIN_POINTS 1
#define MAX_POINTS 100

typedef struct player {
    char name[30];
    int score;
} player_t;

void roll_dice(int *dice, int num_dice) {
    int i, roll;

    for (i = 0; i < num_dice; i++) {
        roll = rand() % (MAX_DICE + 1) + MIN_DICE;
        dice[i] = roll;
    }
}

void print_dice(int *dice, int num_dice) {
    int i;

    printf("\nRolled Dice:\n");

    for (i = 0; i < num_dice; i++) {
        printf("Dice %d: %d\n", i + 1, dice[i]);
    }
}

void calculate_score(int *dice, int num_dice, int *score) {
    int sum = 0;

    for (int i = 0; i < num_dice; i++) {
        sum += dice[i];
    }

    *score = sum;
}

int main() {
    int num_players, i, j, dice[MAX_DICE], player_score, winner = 0;
    player_t players[MAX_PLAYERS];
    srand(time(NULL));

    printf("Welcome to Roll the Dice Game!\n");
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("\nPlayer %d:\n", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    while (1) {
        for (i = 0; i < num_players; i++) {
            roll_dice(dice, MIN_DICE);
            calculate_score(dice, MIN_DICE, &player_score);
            players[i].score += player_score;

            printf("\nPlayer %s rolled the dice and got a score of %d.\n", players[i].name, player_score);
            printf("Current score of %s: %d\n", players[i].name, players[i].score);

            if (players[i].score >= MAX_POINTS) {
                printf("%s wins the game!\n", players[i].name);
                winner = i;
                break;
            }
        }

        if (winner != 0) {
            break;
        }
    }

    print_dice(dice, MIN_DICE);

    return 0;
}