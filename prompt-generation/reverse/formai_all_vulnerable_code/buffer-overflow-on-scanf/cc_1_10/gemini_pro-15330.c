//GEMINI-pro DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 9
#define NUM_PLAYERS 2
#define EMPTY_CELL ' '
#define PLAYER1_CELL 'X'
#define PLAYER2_CELL 'O'
#define WIN_CHECK_MASK 0b111111111

typedef struct {
    char cells[BOARD_SIZE];
    int current_player;
    int winner;
} game_state;

void print_board(game_state *state) {
    printf("+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 3 == 0) {
            printf("| ");
        }
        printf("%c | ", state->cells[i]);
        if (i % 3 == 2) {
            printf("\n+---+---+---+\n");
        }
    }
}

int check_win(game_state *state) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        int row_mask = WIN_CHECK_MASK << (i * 3);
        int col_mask = WIN_CHECK_MASK << i;
        if ((state->cells[i] != EMPTY_CELL) && ((state->cells[i] << (i * 3)) & row_mask) == row_mask) {
            return state->cells[i];
        }
        if ((state->cells[i] != EMPTY_CELL) && ((state->cells[i] << i) & col_mask) == col_mask) {
            return state->cells[i];
        }
    }

    // Check diagonals
    if ((state->cells[0] != EMPTY_CELL) && ((state->cells[0] << 0) & WIN_CHECK_MASK) == WIN_CHECK_MASK) {
        return state->cells[0];
    }
    if ((state->cells[2] != EMPTY_CELL) && ((state->cells[2] << 2) & WIN_CHECK_MASK) == WIN_CHECK_MASK) {
        return state->cells[2];
    }

    // No winner
    return 0;
}

int main() {
    // Initialize game state
    game_state state = {
        .cells = {EMPTY_CELL},
        .current_player = 1,
        .winner = 0
    };

    // Game loop
    while (state.winner == 0) {
        // Print the board
        print_board(&state);

        // Get player move
        int move;
        printf("Player %d, choose a move (1-9): ", state.current_player);
        scanf("%d", &move);

        // Validate and apply move
        if (move < 1 || move > BOARD_SIZE || state.cells[move - 1] != EMPTY_CELL) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        state.cells[move - 1] = state.current_player == 1 ? PLAYER1_CELL : PLAYER2_CELL;

        // Check for win
        state.winner = check_win(&state);

        // Switch players
        state.current_player = state.current_player == 1 ? 2 : 1;
    }

    // Print the winner
    if (state.winner == PLAYER1_CELL) {
        printf("Player 1 wins!\n");
    } else if (state.winner == PLAYER2_CELL) {
        printf("Player 2 wins!\n");
    } else {
        printf("Draw!\n");
    }

    return 0;
}