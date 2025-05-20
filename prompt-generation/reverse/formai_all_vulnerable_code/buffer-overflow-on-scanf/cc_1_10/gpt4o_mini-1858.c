//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK -1
#define EMPTY 0

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn; // WHITE or BLACK
} GameState;

void initialize_board(GameState *state) {
    // Initialize all squares to EMPTY
    memset(state->board, EMPTY, sizeof(state->board));

    // Place pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        state->board[1][i] = WHITE; // white pawns
        state->board[6][i] = BLACK; // black pawns
    }

    // Place other pieces
    state->board[0][0] = state->board[0][7] = WHITE; // rooks
    state->board[0][1] = state->board[0][6] = WHITE; // knights
    state->board[0][2] = state->board[0][5] = WHITE; // bishops
    state->board[0][3] = WHITE; // queen
    state->board[0][4] = WHITE; // king

    state->board[7][0] = state->board[7][7] = BLACK; // rooks
    state->board[7][1] = state->board[7][6] = BLACK; // knights
    state->board[7][2] = state->board[7][5] = BLACK; // bishops
    state->board[7][3] = BLACK; // queen
    state->board[7][4] = BLACK; // king

    state->turn = WHITE;
}

void print_board(GameState *state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = '.';
            if (state->board[i][j] == WHITE) piece = 'P';
            if (state->board[i][j] == BLACK) piece = 'p';
            printf("%c ", piece);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(GameState *state, int start_x, int start_y, int end_x, int end_y) {
    // Check if coordinates are in range
    if (start_x < 0 || start_x >= BOARD_SIZE || start_y < 0 || start_y >= BOARD_SIZE ||
        end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) {
        return 0; // Invalid coordinates
    }

    int moving_piece = state->board[start_x][start_y];
    if (moving_piece == EMPTY || moving_piece != state->turn) {
        return 0; // No piece or wrong turn
    }

    // Simple move validation for pawns only (no actual rules applied here)
    if (moving_piece == WHITE) {
        if (start_x + 1 == end_x && start_y == end_y && state->board[end_x][end_y] == EMPTY) {
            return 1; // Valid move
        }
        if (start_x + 1 == end_x && abs(start_y - end_y) == 1 && state->board[end_x][end_y] == BLACK) {
            return 1; // Capture
        }
    } else {
        if (start_x - 1 == end_x && start_y == end_y && state->board[end_x][end_y] == EMPTY) {
            return 1; // Valid move
        }
        if (start_x - 1 == end_x && abs(start_y - end_y) == 1 && state->board[end_x][end_y] == WHITE) {
            return 1; // Capture
        }
    }

    return 0; // Invalid move
}

void make_move(GameState *state, int start_x, int start_y, int end_x, int end_y) {
    if (is_valid_move(state, start_x, start_y, end_x, end_y)) {
        state->board[end_x][end_y] = state->board[start_x][start_y];
        state->board[start_x][start_y] = EMPTY;
        state->turn = -state->turn; // Switch turn
    }
}

int main() {
    GameState state;
    initialize_board(&state);
    print_board(&state);

    int start_x, start_y, end_x, end_y;
    while (1) {
        printf("Enter move (start_x start_y end_x end_y): ");
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        make_move(&state, start_x, start_y, end_x, end_y);
        print_board(&state);
    }

    return 0;
}