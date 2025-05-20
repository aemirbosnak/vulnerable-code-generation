//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 8
#define MAX_THREADS 8

struct player {
    char name[20];
    int score;
};

struct player players[MAX_PLAYERS];

void *player_thread(void *param) {
    int player_id = *(int *) param;
    char player_name[20];
    int player_score = 0;

    printf("Player %d, enter your name: ", player_id);
    scanf("%s", player_name);
    strcpy(players[player_id].name, player_name);

    while (1) {
        printf("Player %d, your score is: %d\n", player_id, player_score);
        fflush(stdout);
    }

    return NULL;
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Error: maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, player_thread, (void *) &i);
    }

    while (1) {
        for (int i = 0; i < num_players; i++) {
            printf("Player %d, press any key to update your score\n", i);
            fflush(stdout);
            char ch;
            scanf("%c", &ch);
            players[i].score++;
        }
    }

    return 0;
}