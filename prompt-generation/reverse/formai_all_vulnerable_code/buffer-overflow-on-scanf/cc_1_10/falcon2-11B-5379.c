//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4

typedef struct {
    int player_id;
    int score;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
} Game;

void init_game(Game* game) {
    game->num_players = 0;
    memset(game->players, 0, sizeof(Player) * MAX_PLAYERS);
}

void add_player(Game* game, int player_id) {
    if (game->num_players >= MAX_PLAYERS) {
        printf("Game is full. Cannot add more players.\n");
        return;
    }

    game->players[game->num_players].player_id = player_id;
    game->players[game->num_players].score = 0;
    game->num_players++;
}

void start_game(Game* game) {
    int i;
    for (i = 0; i < game->num_players; i++) {
        printf("Player %d's score is %d.\n", game->players[i].player_id, game->players[i].score);
    }
}

void play_game(Game* game) {
    int player_id, choice, score;
    int i;
    for (i = 0; i < game->num_players; i++) {
        printf("Player %d, please make a choice (1, 2, 3, 4): ", game->players[i].player_id);
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                score = rand() % 10 + 1;
                break;
            case 2:
                score = (rand() % 10 + 1) * 2;
                break;
            case 3:
                score = (rand() % 10 + 1) * 3;
                break;
            case 4:
                score = (rand() % 10 + 1) * 4;
                break;
        }

        game->players[i].score += score;
        printf("Player %d's new score is %d.\n", game->players[i].player_id, game->players[i].score);
    }
}

int main() {
    Game game;
    init_game(&game);

    int player_id;
    do {
        printf("Enter player's ID: ");
        scanf("%d", &player_id);
        add_player(&game, player_id);
    } while (player_id!= -1);

    start_game(&game);
    play_game(&game);

    return 0;
}