//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 8
#define MAX_MOVES 200

struct player {
    char name[32];
    int wins;
    int losses;
    int ties;
    int turn;
    int pieces;
    int board[BOARD_SIZE][BOARD_SIZE];
};

struct game {
    struct player players[MAX_PLAYERS];
    int current_player;
    int board[BOARD_SIZE][BOARD_SIZE];
    int winner;
    int loser;
    int moves;
};

struct thread_data {
    struct game *game;
    int player_index;
};

void print_board(struct game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int check_win(struct game *game) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == game->players[game->current_player].pieces) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return game->current_player;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[j][i] == game->players[game->current_player].pieces) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return game->current_player;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == j && game->board[i][j] == game->players[game->current_player].pieces) {
                count++;
            }
        }
    }
    if (count == BOARD_SIZE) {
        return game->current_player;
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = BOARD_SIZE - 1; j >= 0; j--) {
            if (i + j == BOARD_SIZE - 1 && game->board[i][j] == game->players[game->current_player].pieces) {
                count++;
            }
        }
    }
    if (count == BOARD_SIZE) {
        return game->current_player;
    }

    return -1;
}

void *player_thread(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    struct game *game = data->game;
    int player_index = data->player_index;

    while (1) {
        if (game->winner != -1) {
            break;
        }

        if (game->current_player != player_index) {
            continue;
        }

        int move_x, move_y;
        printf("Player %s's turn:\n", game->players[player_index].name);
        printf("Enter the coordinates of your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        if (move_x < 0 || move_x >= BOARD_SIZE || move_y < 0 || move_y >= BOARD_SIZE) {
            printf("Invalid move. Please enter a valid coordinate.\n");
            continue;
        }

        if (game->board[move_x][move_y] != 0) {
            printf("That space is already occupied. Please enter a valid move.\n");
            continue;
        }

        game->board[move_x][move_y] = game->players[player_index].pieces;
        game->moves++;

        int winner = check_win(game);
        if (winner != -1) {
            game->winner = winner;
            game->loser = (winner + 1) % MAX_PLAYERS;
            printf("Player %s wins!\n", game->players[winner].name);
            break;
        }

        game->current_player = (game->current_player + 1) % MAX_PLAYERS;
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    struct game game;
    memset(&game, 0, sizeof(struct game));

    // Initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", game.players[i].name);
        game.players[i].pieces = 'X' + i;
    }

    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game.board[i][j] = 0;
        }
    }

    // Create threads for each player
    pthread_t player_threads[MAX_PLAYERS];
    struct thread_data thread_data[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        thread_data[i].game = &game;
        thread_data[i].player_index = i;
        if (pthread_create(&player_threads[i], NULL, player_thread, &thread_data[i]) != 0) {
            perror("pthread_create() failed");
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (pthread_join(player_threads[i], NULL) != 0) {
            perror("pthread_join() failed");
            return EXIT_FAILURE;
        }
    }

    print_board(&game);

    return EXIT_SUCCESS;
}