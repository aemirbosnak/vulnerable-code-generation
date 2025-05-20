//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5
#define MIN_NUMBER 1
#define MAX_NUMBER 100

typedef struct {
    char name[20];
    int score;
} player_t;

void generate_number(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

int get_answer(player_t *player, int number) {
    printf("Player %s, what is %d + %d?\n", player->name, number, player->score);
    int answer;
    scanf("%d", &answer);
    return answer;
}

int main() {
    srand(time(NULL));
    int players = 2;
    player_t players_data[MAX_PLAYERS];
    for (int i = 0; i < players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players_data[i].name);
        players_data[i].score = 0;
    }

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("Round %d:\n", round);
        for (int i = 0; i < players; i++) {
            int number = 0;
            generate_number(&number);
            int answer = get_answer(&players_data[i], number);
            if (answer == number + players_data[i].score) {
                printf("Correct answer! %s earns 1 point.\n", players_data[i].name);
                players_data[i].score++;
            } else {
                printf("Incorrect answer. Better luck next time, %s.\n", players_data[i].name);
            }
        }
    }

    printf("Game over.\n");
    for (int i = 0; i < players; i++) {
        printf("Final score for %s: %d\n", players_data[i].name, players_data[i].score);
    }

    return 0;
}