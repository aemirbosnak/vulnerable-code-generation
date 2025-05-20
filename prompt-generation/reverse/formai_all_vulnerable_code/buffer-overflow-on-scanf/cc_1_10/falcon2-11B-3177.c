//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char board[8][8];
    int current_player;
    int game_over;
} CheckersGame;

void print_board(CheckersGame *game) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

void make_move(CheckersGame *game, int from_row, int from_col, int to_row, int to_col) {
    if (game->current_player == 1) {
        if (game->board[from_row][from_col] == 'X' && game->board[to_row][to_col] == 'O') {
            game->board[from_row][from_col] = 'O';
            game->board[to_row][to_col] = 'X';
        }
    } else {
        if (game->board[from_row][from_col] == 'O' && game->board[to_row][to_col] == 'X') {
            game->board[from_row][from_col] = 'X';
            game->board[to_row][to_col] = 'O';
        }
    }
    if (game->board[to_row][to_col] == 'O') {
        game->game_over = true;
    }
    game->current_player = 1 - game->current_player;
}

void play_checkers(CheckersGame *game) {
    printf("Welcome to Checkers!\n\n");
    printf("Enter a row and column to move your piece:\n");
    int from_row, from_col, to_row, to_col;
    printf("From row: ");
    scanf("%d", &from_row);
    printf("From column: ");
    scanf("%d", &from_col);
    printf("To row: ");
    scanf("%d", &to_row);
    printf("To column: ");
    scanf("%d", &to_col);
    make_move(game, from_row, from_col, to_row, to_col);
    while (!game->game_over) {
        print_board(game);
        printf("Your turn!\n");
        printf("Enter a row and column to move your piece:\n");
        int from_row, from_col, to_row, to_col;
        printf("From row: ");
        scanf("%d", &from_row);
        printf("From column: ");
        scanf("%d", &from_col);
        printf("To row: ");
        scanf("%d", &to_row);
        printf("To column: ");
        scanf("%d", &to_col);
        make_move(game, from_row, from_col, to_row, to_col);
    }
    if (game->game_over) {
        printf("Game over! Player %d wins!\n", game->current_player);
    }
}

int main() {
    CheckersGame game;
    game.board[0][0] = 'O';
    game.board[0][1] = 'X';
    game.board[0][2] = 'O';
    game.board[0][3] = 'X';
    game.board[0][4] = 'O';
    game.board[0][5] = 'X';
    game.board[0][6] = 'O';
    game.board[0][7] = 'X';
    game.board[1][0] = 'O';
    game.board[1][1] = 'X';
    game.board[1][2] = 'O';
    game.board[1][3] = 'X';
    game.board[1][4] = 'O';
    game.board[1][5] = 'X';
    game.board[1][6] = 'O';
    game.board[1][7] = 'X';
    game.board[2][0] = 'O';
    game.board[2][1] = 'X';
    game.board[2][2] = 'O';
    game.board[2][3] = 'X';
    game.board[2][4] = 'O';
    game.board[2][5] = 'X';
    game.board[2][6] = 'O';
    game.board[2][7] = 'X';
    game.board[3][0] = 'O';
    game.board[3][1] = 'X';
    game.board[3][2] = 'O';
    game.board[3][3] = 'X';
    game.board[3][4] = 'O';
    game.board[3][5] = 'X';
    game.board[3][6] = 'O';
    game.board[3][7] = 'X';
    game.board[4][0] = 'O';
    game.board[4][1] = 'X';
    game.board[4][2] = 'O';
    game.board[4][3] = 'X';
    game.board[4][4] = 'O';
    game.board[4][5] = 'X';
    game.board[4][6] = 'O';
    game.board[4][7] = 'X';
    game.board[5][0] = 'O';
    game.board[5][1] = 'X';
    game.board[5][2] = 'O';
    game.board[5][3] = 'X';
    game.board[5][4] = 'O';
    game.board[5][5] = 'X';
    game.board[5][6] = 'O';
    game.board[5][7] = 'X';
    game.board[6][0] = 'O';
    game.board[6][1] = 'X';
    game.board[6][2] = 'O';
    game.board[6][3] = 'X';
    game.board[6][4] = 'O';
    game.board[6][5] = 'X';
    game.board[6][6] = 'O';
    game.board[6][7] = 'X';
    game.board[7][0] = 'O';
    game.board[7][1] = 'X';
    game.board[7][2] = 'O';
    game.board[7][3] = 'X';
    game.board[7][4] = 'O';
    game.board[7][5] = 'X';
    game.board[7][6] = 'O';
    game.board[7][7] = 'X';
    game.current_player = 1;
    play_checkers(&game);
    return 0;
}