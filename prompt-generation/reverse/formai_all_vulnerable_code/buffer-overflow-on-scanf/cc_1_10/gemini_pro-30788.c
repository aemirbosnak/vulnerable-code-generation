//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_NUMBERS 100

typedef struct player {
    int id;
    int score;
    int position;
    pthread_t thread;
} player_t;

typedef struct game {
    player_t players[MAX_PLAYERS];
    int current_player;
    int sequence[MAX_NUMBERS];
    int sequence_length;
    pthread_mutex_t lock;
} game_t;

void *player_thread(void *arg) {
    game_t *game = (game_t *)arg;
    int player_id = ((player_t *)arg)->id;

    while (1) {
        pthread_mutex_lock(&game->lock);
        if (game->current_player != player_id) {
            pthread_mutex_unlock(&game->lock);
            continue;
        }

        int guess;
        printf("Player %d, guess the next number in the sequence: ", player_id);
        scanf("%d", &guess);

        if (guess == game->sequence[game->sequence_length]) {
            game->players[player_id].score++;
            game->sequence_length++;
            printf("Player %d guessed correctly!\n", player_id);
        } else {
            printf("Player %d guessed incorrectly.\n", player_id);
        }

        game->current_player = (game->current_player + 1) % MAX_PLAYERS;
        pthread_mutex_unlock(&game->lock);
    }

    return NULL;
}

int main() {
    game_t game;

    memset(&game, 0, sizeof(game_t));
    pthread_mutex_init(&game.lock, NULL);

    game.sequence[0] = 0;
    game.sequence[1] = 1;
    game.sequence_length = 2;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        game.players[i].id = i;
        pthread_create(&game.players[i].thread, NULL, player_thread, &game.players[i]);
    }

    while (1) {
        sleep(1);

        pthread_mutex_lock(&game.lock);
        printf("Current sequence: ");
        for (int i = 0; i < game.sequence_length; i++) {
            printf("%d ", game.sequence[i]);
        }
        printf("\n");
        pthread_mutex_unlock(&game.lock);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(game.players[i].thread, NULL);
    }

    pthread_mutex_destroy(&game.lock);

    return 0;
}