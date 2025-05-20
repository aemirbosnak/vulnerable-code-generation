//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE ' '

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
    char winner;
} TicTacToeGame;

void print_board(TicTacToeGame* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

void init_game(TicTacToeGame* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY_SPACE;
        }
    }
    game->current_player = PLAYER_X;
    game->winner = EMPTY_SPACE;
}

int make_move(TicTacToeGame* game, int row, int col) {
    if (game->board[row][col] == EMPTY_SPACE) {
        game->board[row][col] = game->current_player;
        game->current_player = (game->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        return 1;
    }
    return 0;
}

int check_win(TicTacToeGame* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == EMPTY_SPACE) {
                return 0;
            }
        }
    }

    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2]) {
            game->winner = game->board[i][0];
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i]) {
            game->winner = game->board[0][i];
            return 1;
        }
    }

    // Check diagonals
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2]) {
        game->winner = game->board[0][0];
        return 1;
    }
    if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0]) {
        game->winner = game->board[0][2];
        return 1;
    }

    return 0;
}

void play_game(TicTacToeGame* game) {
    init_game(game);
    print_board(game);

    while (game->winner == EMPTY_SPACE) {
        if (game->current_player == PLAYER_X) {
            int row, col;
            printf("Player X, enter row and column: ");
            scanf("%d %d", &row, &col);
            make_move(game, row, col);
        } else {
            int row, col;
            printf("Player O, enter row and column: ");
            scanf("%d %d", &row, &col);
            make_move(game, row, col);
        }
        print_board(game);
        check_win(game);
    }

    printf("Winner is %c\n", game->winner);
}

int main() {
    TicTacToeGame game;
    play_game(&game);
    return 0;
}