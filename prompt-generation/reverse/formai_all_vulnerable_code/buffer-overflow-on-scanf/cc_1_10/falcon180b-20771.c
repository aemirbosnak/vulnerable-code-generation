//Falcon-180B DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

struct player {
    char name[20];
    int score;
};

void init_players(struct player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].score = 0;
    }
}

void display_scores(struct player players[]) {
    printf("Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int roll_dice() {
    return rand() % 6 + 1;
}

int main() {
    struct player players[MAX_PLAYERS];
    char player_names[MAX_PLAYERS][20];
    int num_players;

    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);

    printf("Enter names of players:\n");
    for (int i = 0; i < num_players; i++) {
        scanf("%s", player_names[i]);
        strcpy(players[i].name, player_names[i]);
    }

    init_players(players);

    int round_num = 1;
    while (round_num <= MAX_ROUNDS) {
        printf("\nRound %d:\n", round_num);

        for (int i = 0; i < num_players; i++) {
            int player_score = 0;

            while (player_score < 100) {
                int dice_roll = roll_dice();
                if (dice_roll == 6) {
                    player_score += 10;
                } else {
                    player_score += dice_roll;
                }
                printf("%s rolled %d, score is now %d\n", players[i].name, dice_roll, player_score);
            }

            players[i].score += player_score;
        }

        display_scores(players);

        round_num++;
    }

    return 0;
}