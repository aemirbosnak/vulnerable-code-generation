//Falcon-180B DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define MAX_PLAYER_NAME_LENGTH 20
#define MAX_ROUND_NUM 3
#define MAX_ROUND_SCORE 100

typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
} Player;

int main() {
    int num_players;
    char input[MAX_PLAYER_NAME_LENGTH];
    Player players[MAX_PLAYERS];
    int i, j, k;
    int round_num = 1;
    srand(time(NULL));

    printf("Welcome to the game!\n");
    printf("Please enter the number of players (1-4): ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Please enter the name of player %d: ", i + 1);
        scanf("%s", input);
        strcpy(players[i].name, input);
        players[i].score = 0;
    }

    for (i = 0; i < MAX_ROUNDS; i++) {
        printf("\nRound %d\n", i + 1);
        for (j = 0; j < num_players; j++) {
            printf("Player %d's score: %d\n", j + 1, players[j].score);
        }
        for (k = 0; k < MAX_ROUND_NUM; k++) {
            int roll = rand() % 6 + 1;
            printf("Player %d rolled a %d.\n", j + 1, roll);
            players[j].score += roll;
        }
        for (j = 0; j < num_players; j++) {
            printf("Player %d's final score for this round: %d\n", j + 1, players[j].score);
        }
        for (j = 0; j < num_players; j++) {
            if (players[j].score >= MAX_ROUND_SCORE) {
                printf("Player %d wins the round!\n", j + 1);
                break;
            }
        }
        if (j == num_players) {
            printf("Tie!\n");
        }
        printf("\n");
    }

    for (i = 0; i < num_players; i++) {
        printf("Final score for player %s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}