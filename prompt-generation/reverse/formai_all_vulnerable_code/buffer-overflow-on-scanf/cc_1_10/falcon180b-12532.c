//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void *start_game(void *arg) {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i, players[i].name);
        players[i].score = 0;
    }
    while (num_players > 1) {
        usleep(100000);
        int highest_score = 0;
        int highest_score_index = 0;
        int j;
        for (j = 0; j < num_players; j++) {
            if (players[j].score > highest_score) {
                highest_score = players[j].score;
                highest_score_index = j;
            }
        }
        if (highest_score_index!= 0) {
            players[0].score++;
            printf("Player %d wins!\n", 0);
            num_players--;
        } else {
            printf("Tie game.\n");
            num_players--;
        }
    }
    pthread_exit(0);
}

int main() {
    int i, j;
    char input[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", input);
    strcpy(players[num_players].name, input);
    num_players++;
    pthread_t threads[num_players - 1];
    for (i = 1; i < num_players; i++) {
        pthread_create(&threads[i-1], NULL, start_game, NULL);
    }
    start_game(NULL);
    for (i = 0; i < num_players - 1; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}