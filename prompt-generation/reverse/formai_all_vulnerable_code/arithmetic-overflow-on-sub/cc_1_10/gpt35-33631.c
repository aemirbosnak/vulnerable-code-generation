//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define BOARD_SIZE 3
#define EMPTY_CELL '-'
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

pthread_mutex_t mutex;
bool game_over = false;

struct game_state {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player_turn;
};

void initialize_board(struct game_state *game) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY_CELL;
        }
    }
    game->player_turn = PLAYER_ONE;
}

void print_board(const struct game_state *game) {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_move(const struct game_state *game, int i, int j) {
    return game->board[i][j] == EMPTY_CELL;
}

bool is_winner(const struct game_state *game, char player) {
    int i, j;
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] == player && game->board[i][1] == player && game->board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (game->board[0][j] == player && game->board[1][j] == player && game->board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (game->board[0][0] == player && game->board[1][1] == player && game->board[2][2] == player) {
        return true;
    }
    if (game->board[0][2] == player && game->board[1][1] == player && game->board[2][0] == player) {
        return true;
    }
    return false;
}

bool is_full_game(const struct game_state *game) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == EMPTY_CELL) {
                return false;
            }
        }
    }
    return true;
}

bool is_game_over(const struct game_state *game, char player) {
    if (is_winner(game, player)) {
        printf("Player %c wins!\n", player);
        return true;
    } else if (is_full_game(game)) {
        printf("Game is a draw!\n");
        return true;
    }
    return false;
}

void make_move(struct game_state *game, int i, int j) {
    game->board[i][j] = game->player_turn;
    game->player_turn = (game->player_turn == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
}

bool get_move(struct game_state *game, int *i, int *j) {
    printf("Player %c's turn.\n", game->player_turn);
    printf("Enter row number (1-3): ");
    scanf("%d", i);
    (*i)--;
    printf("Enter column number (1-3): ");
    scanf("%d", j);
    (*j)--;
    if (*i >= BOARD_SIZE || *i < 0 || *j >= BOARD_SIZE || *j < 0) {
        printf("Invalid row or column number.\n");
        return false;
    }
    if (!is_valid_move(game, *i, *j)) {
        printf("Selected cell is already occupied.\n");
        return false;
    }
    return true;
}

void *play(void *arg) {
    struct game_state *game = (struct game_state *) arg;
    int i, j;
    while (!game_over) {
        pthread_mutex_lock(&mutex);
        if (get_move(game, &i, &j)) {
            make_move(game, i, j);
            print_board(game);
            if (is_game_over(game, game->player_turn)) {
                game_over = true;
            }
        }
        pthread_mutex_unlock(&mutex);
        usleep(500000); // Slow down the game for better visibility
    }
    return NULL;
}

int main() {
    struct game_state game;
    initialize_board(&game);
    print_board(&game);
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, play, &game);
    while (!game_over) {
        // Block main thread
    }
    pthread_join(thread, NULL);
    return 0;
}