//Falcon-180B DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5
#define MAX_NAME_LENGTH 20
#define MAX_ROUND_SCORE 100

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score[MAX_ROUNDS];
} Player;

void generate_round_score(int *score) {
    for (int i = 0; i < MAX_ROUNDS; i++) {
        score[i] = rand() % MAX_ROUND_SCORE;
    }
}

void print_score(int *score) {
    printf("Score: ");
    for (int i = 0; i < MAX_ROUNDS; i++) {
        printf("%d ", score[i]);
    }
    printf("\n");
}

void play_game(Player *players, int num_players) {
    int scores[MAX_ROUNDS];
    for (int i = 0; i < num_players; i++) {
        generate_round_score(scores + i * MAX_ROUNDS);
    }
    for (int i = 0; i < MAX_ROUNDS; i++) {
        for (int j = 0; j < num_players; j++) {
            printf("%s: %d\n", players[j].name, scores[i * num_players + j]);
        }
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players = 0;
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    for (int i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }
    play_game(players, num_players);
    return 0;
}