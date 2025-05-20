//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10
#define MAX_PLAYERS 4

typedef struct player {
    char name[50];
    int score;
} player_t;

typedef struct game {
    player_t players[MAX_PLAYERS];
    int turn;
    int round;
} game_t;

void init_game(game_t *game);
void handle_turn(game_t *game);
void print_score(game_t *game);
void roll_dice(game_t *game);

int main() {
    srand(time(NULL));

    game_t game;
    init_game(&game);

    while (1) {
        handle_turn(&game);
    }

    return 0;
}

void init_game(game_t *game) {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        game->players[i].score = 0;
        strcpy(game->players[i].name, "Player ");
        game->players[i].name[strlen(game->players[i].name) - 1] = i + '1';
    }

    game->turn = 0;
    game->round = 0;
}

void handle_turn(game_t *game) {
    int player_num = game->turn % MAX_PLAYERS;
    player_t *player = &game->players[player_num];

    if (player->score == 0) {
        roll_dice(game);
    }

    if (player->score == 0) {
        player->score = 100;
    } else {
        player->score -= 10;
    }

    game->turn++;

    if (game->turn == MAX_PLAYERS) {
        game->turn = 0;
        game->round++;
    }

    print_score(game);
}

void roll_dice(game_t *game) {
    int die1, die2;

    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;

    if (die1 > die2) {
        game->players[game->turn - 1].score += die1;
    } else {
        game->players[game->turn - 1].score += die2;
    }
}

void print_score(game_t *game) {
    int i;

    printf("Round %d:\n", game->round);

    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("%d. %s: %d\n", i + 1, game->players[i].name, game->players[i].score);
    }

    printf("\n");
}