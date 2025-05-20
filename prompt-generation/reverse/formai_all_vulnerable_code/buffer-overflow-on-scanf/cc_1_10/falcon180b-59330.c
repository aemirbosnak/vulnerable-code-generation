//Falcon-180B DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int chips;
} Player;

typedef struct {
    int num_players;
    Player players[MAX_PLAYERS];
    int current_player;
    int current_round;
    int pot;
} Game;

void *play_round(void *arg) {
    Game *game = arg;

    printf("Round %d starting...\n", game->current_round);
    for (int i = 0; i < game->num_players; i++) {
        printf("%s's turn...\n", game->players[i].name);
        fflush(stdout);
        sleep(1);
    }
    printf("Round %d complete.\n", game->current_round);

    game->current_round++;

    if (game->current_round >= MAX_ROUNDS) {
        printf("Game over.\n");
        exit(0);
    }

    return NULL;
}

int main() {
    Game game;
    game.num_players = 0;
    game.current_player = 0;
    game.current_round = 1;
    game.pot = 0;

    pthread_t threads[MAX_PLAYERS];

    char name[20];
    int chips;

    while (game.num_players < MAX_PLAYERS) {
        printf("Enter name and starting chips for player %d:\n", game.num_players + 1);
        scanf("%s %d", name, &chips);
        strcpy(game.players[game.num_players].name, name);
        game.players[game.num_players].chips = chips;
        game.num_players++;
    }

    for (int i = 0; i < game.num_players; i++) {
        pthread_create(&threads[i], NULL, play_round, &game);
    }

    for (int i = 0; i < game.num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}