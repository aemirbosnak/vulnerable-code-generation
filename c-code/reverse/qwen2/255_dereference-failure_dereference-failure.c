#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Move;

typedef enum { EMPTY, WHITE_PAWN, WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING,
              BLACK_PAWN, BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING } Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int turn; // 0 for white, 1 for black
} GameState;

void initializeBoard(GameState *state) {
    memset(state->board, EMPTY, sizeof(state->board));
    state->turn = 0;
}

int isMoveValid(GameState *state, Move from, Move to) {
    if (from.row < 0 || from.row >= BOARD_SIZE || from.col < 0 || from.col >= BOARD_SIZE ||
        to.row < 0 || to.row >= BOARD_SIZE || to.col < 0 || to.col >= BOARD_SIZE) {
        return 0;
    }
    Piece piece = state->board[from.row][from.col];
    if (piece == EMPTY || (state->turn == 0 && piece < WHITE_PAWN) || (state->turn == 1 && piece > BLACK_PAWN)) {
        return 0;
    }
    // Add more specific rules for each piece type here
    return 1;
}

void makeMove(GameState *state, Move from, Move to) {
    if (isMoveValid(state, from, to)) {
        state->board[to.row][to.col] = state->board[from.row][from.col];
        state->board[from.row][from.col] = EMPTY;
        state->turn = 1 - state->turn;
    }
}

// Implement minimax with alpha-beta pruning here

int main() {
    GameState state;
    initializeBoard(&state);
    // Example move: move pawn from e2 to e4
    Move from = {1, 4};
    Move to = {3, 4};
    makeMove(&state, from, to);
    // Continue game loop and AI logic here
    return 0;
}
