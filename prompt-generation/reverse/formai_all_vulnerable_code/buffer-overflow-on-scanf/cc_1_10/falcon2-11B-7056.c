//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn;
    int moves;
    int winner;
} Game;

Game create_game() {
    Game game;
    memset(game.board, '.', sizeof(game.board));
    game.turn = 0;
    game.moves = 0;
    game.winner = 0;
    return game;
}

int check_winner(Game game) {
    if (game.board[0][0]!= '.' && game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2]) {
        return 1; // Black wins
    } else if (game.board[7][0]!= '.' && game.board[7][0] == game.board[6][1] && game.board[6][1] == game.board[5][2]) {
        return 2; // White wins
    } else if (game.board[0][0]!= '.' && game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2] && game.board[2][2] == game.board[3][3] && game.board[3][3] == game.board[4][4] && game.board[4][4] == game.board[5][5] && game.board[5][5] == game.board[6][6] && game.board[6][6] == game.board[7][7]) {
        return 3; // Draw
    } else {
        return 0; // No winner
    }
}

int make_move(Game game, int row, int col) {
    if (row < 0 || row > 7 || col < 0 || col > 7 || game.board[row][col]!= '.') {
        return -1; // Invalid move
    }
    game.board[row][col] = game.turn + '0';
    if (check_winner(game)!= 0) {
        return 1; // Game over
    }
    game.moves++;
    game.turn = 1 - game.turn;
    return 0;
}

int main() {
    Game game = create_game();

    printf("Welcome to Retro Checkers!\n");
    while (game.moves < MAX_SIZE * 4) {
        printf("Current board:\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c", game.board[i][j]);
            }
            printf("\n");
        }
        printf("Turn: %d\n", game.turn);
        int row, col;
        scanf("%d %d", &row, &col);
        int result = make_move(game, row - 1, col - 1);
        if (result == 1) {
            printf("Game over!\n");
            break;
        }
        printf("Move accepted.\n");
    }

    if (check_winner(game) == 1) {
        printf("Black wins!\n");
    } else if (check_winner(game) == 2) {
        printf("White wins!\n");
    } else if (check_winner(game) == 3) {
        printf("Draw!\n");
    } else {
        printf("No winner!\n");
    }

    return 0;
}