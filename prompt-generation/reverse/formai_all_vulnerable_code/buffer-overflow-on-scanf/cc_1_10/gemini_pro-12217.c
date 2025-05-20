//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define BOARD_SIZE 3
#define NUM_MOVES BOARD_SIZE * BOARD_SIZE

// Data Structures
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int num_moves;
} game_state;

// Function Declarations
void print_board(game_state game);
int get_move(game_state game);
int check_win(game_state game);
void make_move(game_state *game, int move, char player);

// Main Function
int main() {
    // Initialize game state
    game_state game;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game.board[i][j] = ' ';
        }
    }
    game.num_moves = 0;

    // Play game
    while (true) {
        // Get player move
        int move = get_move(game);

        // Make player move
        make_move(&game, move, 'X');

        // Check for win
        int win_status = check_win(game);
        if (win_status != -1) {
            if (win_status == 0) {
                printf("Tie game!\n");
            } else {
                printf("Player %c wins!\n", win_status);
            }
            break;
        }

        // Get AI move
        move = get_move(game);

        // Make AI move
        make_move(&game, move, 'O');

        // Check for win
        win_status = check_win(game);
        if (win_status != -1) {
            if (win_status == 0) {
                printf("Tie game!\n");
            } else {
                printf("Player %c wins!\n", win_status);
            }
            break;
        }
    }

    return 0;
}

// Function Definitions
void print_board(game_state game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", game.board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }
}

int get_move(game_state game) {
    int move;
    while (true) {
        printf("Enter your move (1-%d): ", NUM_MOVES);
        scanf("%d", &move);
        if (move < 1 || move > NUM_MOVES) {
            printf("Invalid move!\n");
        } else if (game.board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ') {
            printf("Space already occupied!\n");
        } else {
            break;
        }
    }
    return move - 1;
}

int check_win(game_state game) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game.board[i][0] != ' ' && game.board[i][0] == game.board[i][1] && game.board[i][1] == game.board[i][2]) {
            return game.board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game.board[0][i] != ' ' && game.board[0][i] == game.board[1][i] && game.board[1][i] == game.board[2][i]) {
            return game.board[0][i];
        }
    }

    // Check diagonals
    if (game.board[0][0] != ' ' && game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2]) {
        return game.board[0][0];
    }
    if (game.board[2][0] != ' ' && game.board[2][0] == game.board[1][1] && game.board[1][1] == game.board[0][2]) {
        return game.board[2][0];
    }

    // Check tie
    if (game.num_moves == NUM_MOVES) {
        return 0;
    }

    // No win or tie
    return -1;
}

void make_move(game_state *game, int move, char player) {
    game->board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
    game->num_moves++;
}