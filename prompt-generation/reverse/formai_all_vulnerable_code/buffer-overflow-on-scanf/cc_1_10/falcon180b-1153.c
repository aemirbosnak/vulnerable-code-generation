//Falcon-180B DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define MAX_SCORE 100

typedef struct {
    char name[20];
    int score;
} player_t;

void generate_name(char* name) {
    int i = 0;
    while (i < 20) {
        name[i] = rand() % 26 + 'a';
        i++;
    }
    name[i] = '\0';
}

int main() {
    srand(time(NULL));

    player_t players[MAX_PLAYERS];
    int num_players;
    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i+1);
        scanf("%s", players[i].name);
        generate_name(players[i].name);
        players[i].score = 0;
    }

    int rounds_played = 0;
    int current_round = 1;
    while (rounds_played < MAX_ROUNDS || rounds_played == 0) {
        rounds_played++;
        printf("\nRound %d\n", current_round);

        for (int i = 0; i < num_players; i++) {
            printf("Player %s score: %d\n", players[i].name, players[i].score);
        }

        printf("Press enter to continue...");
        getchar();

        int dice_roll;
        for (int i = 0; i < num_players; i++) {
            dice_roll = rand() % 6 + 1;
            printf("Player %s rolled %d\n", players[i].name, dice_roll);
            players[i].score += dice_roll;
        }

        current_round++;
    }

    printf("\nGame over!\n");

    for (int i = 0; i < num_players; i++) {
        printf("Final score for player %s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}