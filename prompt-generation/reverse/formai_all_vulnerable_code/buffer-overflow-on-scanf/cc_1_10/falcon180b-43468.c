//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    int id;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void *play_game(void *arg) {
    int player_id = *(int *) arg;
    char input[MAX_NAME_LENGTH];
    bool running = true;

    printf("Player %d, enter your name:\n", player_id);
    fgets(input, MAX_NAME_LENGTH, stdin);
    strcpy(players[player_id].name, input);

    while (running) {
        printf("Player %d, press enter to roll the dice:\n", player_id);
        fgets(input, MAX_NAME_LENGTH, stdin);

        int dice_roll = rand() % 6 + 1;
        printf("Player %d rolled a %d!\n", player_id, dice_roll);

        players[player_id].score += dice_roll;
        if (players[player_id].score >= 100) {
            running = false;
            printf("Player %d wins!\n", player_id);
        }
    }

    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    int num_threads;
    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Player %d, enter your name:\n", i);
        fgets(players[i].name, MAX_NAME_LENGTH, stdin);
    }

    pthread_t threads[num_players];
    for (int i = 0; i < num_players; i++) {
        pthread_create(&threads[i], NULL, play_game, (void *) &i);
    }

    for (int i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}