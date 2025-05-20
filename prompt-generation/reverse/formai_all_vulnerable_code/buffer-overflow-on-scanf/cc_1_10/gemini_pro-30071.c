//GEMINI-pro DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// Define the player types
typedef enum {
    PLAYER_X,
    PLAYER_O,
    EMPTY
} Player;

// Define the game state
typedef struct {
    Player board[BOARD_SIZE][BOARD_SIZE];
    Player current_player;
    bool game_over;
} GameState;

// Initialize the game state
void init_game(GameState *state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            state->board[i][j] = EMPTY;
        }
    }

    state->current_player = PLAYER_X;
    state->game_over = false;
}

// Print the game state
void print_game(GameState *state) {
    printf("Current player: %s\n", state->current_player == PLAYER_X ? "X" : "O");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (state->board[i][j]) {
                case PLAYER_X:
                    printf("X ");
                    break;
                case PLAYER_O:
                    printf("O ");
                    break;
                case EMPTY:
                    printf(". ");
                    break;
            }
        }

        printf("\n");
    }
}

// Check if a player has won
bool check_win(GameState *state) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (state->board[i][0] != EMPTY && state->board[i][0] == state->board[i][1] && state->board[i][1] == state->board[i][2]) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (state->board[0][j] != EMPTY && state->board[0][j] == state->board[1][j] && state->board[1][j] == state->board[2][j]) {
            return true;
        }
    }

    // Check diagonals
    if (state->board[0][0] != EMPTY && state->board[0][0] == state->board[1][1] && state->board[1][1] == state->board[2][2]) {
        return true;
    }

    if (state->board[0][2] != EMPTY && state->board[0][2] == state->board[1][1] && state->board[1][1] == state->board[2][0]) {
        return true;
    }

    // No winner yet
    return false;
}

// Check if the game is over
bool check_game_over(GameState *state) {
    return check_win(state) || !state->game_over;
}

// Ask the player for a move
void get_move(GameState *state) {
    int row, column;

    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &column);

    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE || state->board[row][column] != EMPTY) {
        printf("Invalid move. Please try again.\n");
        get_move(state);
    } else {
        // Place the player's move on the board
        state->board[row][column] = state->current_player;

        // Check if the player has won
        if (check_win(state)) {
            printf("Player %s has won!\n", state->current_player == PLAYER_X ? "X" : "O");
            state->game_over = true;
        } else {
            // Switch the current player
            state->current_player = state->current_player == PLAYER_X ? PLAYER_O : PLAYER_X;

            // Check if the game is over
            if (check_game_over(state)) {
                printf("Draw!\n");
                state->game_over = true;
            }
        }
    }
}

int main() {
    GameState state;

    init_game(&state);

    while (!state.game_over) {
        print_game(&state);

        get_move(&state);
    }

    return 0;
}