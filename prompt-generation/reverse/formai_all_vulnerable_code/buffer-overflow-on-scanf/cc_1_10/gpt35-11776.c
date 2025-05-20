//FormAI DATASET v1.0 Category: Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PLAYERS 8
#define MAX_NAME_LENGTH 20

void* player_thread(void* arg);

struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
};

struct Player players[MAX_PLAYERS];
int num_players = 0;
int max_score = 100;
pthread_mutex_t score_lock;

int main() {
    int i;
    pthread_t threads[MAX_PLAYERS];

    printf("Welcome to the multiplayer game!\n");
    printf("Please enter the maximum score to play to: ");
    scanf("%d", &max_score);

    while (num_players < MAX_PLAYERS) {
        printf("Enter a player name (or 'done' to start the game): ");
        scanf("%s", players[num_players].name);

        if (strcmp(players[num_players].name, "done") == 0) {
            if (num_players < 2) {
                printf("Error: need at least 2 players to start the game.\n");
                continue;
            }
            else {
                break;
            }
        }
        else {
            num_players++;
        }
    }

    printf("Starting game with %d players!\n", num_players);

    pthread_mutex_init(&score_lock, NULL);

    for (i = 0; i < num_players; i++) {
        pthread_create(&threads[i], NULL, player_thread, (void*) &players[i]);
    }

    for (i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&score_lock);

    printf("Game over!\n");
    return 0;
}

void* player_thread(void* arg) {
    struct Player* player = (struct Player*) arg;

    while (player->score < max_score) {
        int score;

        usleep(rand() % 1000000);

        score = rand() % 10 + 1;

        pthread_mutex_lock(&score_lock);
        player->score += score;
        printf("%s scores %d (total score: %d)\n", player->name, score, player->score);
        pthread_mutex_unlock(&score_lock);
    }

    printf("%s wins the game with a score of %d!\n", player->name, player->score);

    return NULL;
}