//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
// Tic Tac Toe AI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// Board data structure
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} TicTacToe;

// Initialize board
void init_board(TicTacToe* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = ' ';
        }
    }
    game->turn = 0;
}

// Display board
void display_board(TicTacToe* game) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

// Check if game is over
int game_over(TicTacToe* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Make a move
void make_move(TicTacToe* game, int row, int col) {
    if (game->board[row][col] == ' ') {
        if (game->turn == 0) {
            game->board[row][col] = 'X';
            game->turn = 1;
        } else {
            game->board[row][col] = 'O';
            game->turn = 0;
        }
    }
}

// Check if a player has won
int check_win(TicTacToe* game) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2]) {
        return 1;
    } else if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0]) {
        return 1;
    }

    return 0;
}

// AI logic
void ai_move(TicTacToe* game) {
    // Check for winning move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                game->board[i][j] = game->turn == 0 ? 'X' : 'O';
                if (check_win(game)) {
                    return;
                }
                game->board[i][j] = ' ';
            }
        }
    }

    // Check for blocking move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                game->board[i][j] = game->turn == 0 ? 'O' : 'X';
                if (check_win(game)) {
                    return;
                }
                game->board[i][j] = ' ';
            }
        }
    }

    // Make random move
    srand(time(NULL));
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;
    game->board[row][col] = game->turn == 0 ? 'X' : 'O';
}

// Main function
int main() {
    TicTacToe game;
    init_board(&game);

    while (1) {
        display_board(&game);

        if (game_over(&game)) {
            printf("Game over!\n");
            break;
        }

        if (game.turn == 0) {
            printf("Player 1's turn: ");
            int row, col;
            scanf("%d %d", &row, &col);
            make_move(&game, row, col);
        } else {
            ai_move(&game);
        }
    }

    return 0;
}