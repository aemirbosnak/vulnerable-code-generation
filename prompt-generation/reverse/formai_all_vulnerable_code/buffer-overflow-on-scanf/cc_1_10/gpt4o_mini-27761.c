//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK -1
#define EMPTY 0

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} GameState;

void initialize_game(GameState *game) {
    int initial_board[BOARD_SIZE][BOARD_SIZE] = {
        { -1, -1, -1, -1, -1, -1, -1, -1 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
    };

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            game->board[i][j] = initial_board[i][j];

    game->turn = WHITE;
}

void display_board(GameState *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == WHITE)
                printf("W ");
            else if (game->board[i][j] == BLACK)
                printf("B ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool is_move_valid(GameState *game, int from_row, int from_col, int to_row, int to_col) {
    if (from_row < 0 || from_row >= BOARD_SIZE || from_col < 0 || from_col >= BOARD_SIZE ||
        to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE)
        return false;
    
    int moving_piece = game->board[from_row][from_col];
    // Check if moving the player's piece
    if (moving_piece != game->turn)
        return false;

    // Example movement rules: Pieces can only move one step forward
    if (game->turn == WHITE) {
        if (to_row == from_row + 1 && to_col == from_col && game->board[to_row][to_col] == EMPTY)
            return true;
    } else if (game->turn == BLACK) {
        if (to_row == from_row - 1 && to_col == from_col && game->board[to_row][to_col] == EMPTY)
            return true;
    }

    return false;
}

void make_move(GameState *game, int from_row, int from_col, int to_row, int to_col) {
    if (is_move_valid(game, from_row, from_col, to_row, to_col)) {
        game->board[to_row][to_col] = game->board[from_row][from_col];
        game->board[from_row][from_col] = EMPTY;
        game->turn = -game->turn; // Switch turns
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    GameState game;
    initialize_game(&game);
    display_board(&game);

    while (true) {
        int from_row, from_col, to_row, to_col;
        printf("Current turn: %s. Enter move (from_row from_col to_row to_col): ", 
               (game.turn == WHITE) ? "White" : "Black");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        make_move(&game, from_row, from_col, to_row, to_col);
        display_board(&game);
    }

    return 0;
}