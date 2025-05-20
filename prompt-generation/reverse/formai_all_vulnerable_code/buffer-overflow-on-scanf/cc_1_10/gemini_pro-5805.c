//GEMINI-pro DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 32
#define MAX_PLAYERS 4

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} player_t;

typedef struct game {
    player_t players[MAX_PLAYERS];
    int num_players;
    int current_player;
    int winning_score;
} game_t;

void print_game(game_t *game) {
    printf("Current game:\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("Player %d: %s, Score: %d\n", i + 1, game->players[i].name, game->players[i].score);
    }
    printf("Current player: %d\n", game->current_player + 1);
    printf("Winning score: %d\n", game->winning_score);
}

bool is_valid_move(game_t *game, int player, int move) {
    if (player < 0 || player >= game->num_players) {
        return false;
    }
    if (move < 1 || move > 6) {
        return false;
    }
    return true;
}

void make_move(game_t *game, int player, int move) {
    if (!is_valid_move(game, player, move)) {
        return;
    }
    game->players[player].score += move;
    game->current_player = (game->current_player + 1) % game->num_players;
}

bool is_game_over(game_t *game) {
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].score >= game->winning_score) {
            return true;
        }
    }
    return false;
}

void print_winner(game_t *game) {
    int winning_player = -1;
    int max_score = -1;
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].score > max_score) {
            winning_player = i;
            max_score = game->players[i].score;
        }
    }
    printf("The winner is: %s\n", game->players[winning_player].name);
}

int main() {
    game_t game;
    game.num_players = 0;
    while (game.num_players < 2 || game.num_players > MAX_PLAYERS) {
        printf("Enter the number of players (2-4): ");
        scanf("%d", &game.num_players);
    }
    for (int i = 0; i < game.num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", game.players[i].name);
        game.players[i].score = 0;
    }
    printf("Enter the winning score: ");
    scanf("%d", &game.winning_score);
    game.current_player = 0;
    print_game(&game);
    while (!is_game_over(&game)) {
        int player = game.current_player;
        int move;
        while (true) {
            printf("Player %s, enter your move (1-6): ", game.players[player].name);
            scanf("%d", &move);
            if (is_valid_move(&game, player, move)) {
                break;
            }
            printf("Invalid move, try again.\n");
        }
        make_move(&game, player, move);
        print_game(&game);
    }
    print_winner(&game);
    return 0;
}