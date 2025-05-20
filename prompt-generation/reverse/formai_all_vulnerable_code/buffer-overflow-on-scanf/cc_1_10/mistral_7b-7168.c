//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY '_'

typedef struct {
    char board[SIZE][SIZE];
    int player;
} Game;

void print_board(Game game) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf(" %c ", game.board[i][j]);
        }
        printf("\n");
    }
}

int check_win(Game game, char symbol) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        if ((game.board[i][0] == symbol && game.board[i][1] == symbol && game.board[i][2] == symbol) ||
            (game.board[0][i] == symbol && game.board[1][i] == symbol && game.board[2][i] == symbol)) {
            return 1;
        }
    }

    if (game.board[0][0] == symbol && game.board[1][1] == symbol && game.board[2][2] == symbol) {
        return 1;
    }

    if (game.board[0][2] == symbol && game.board[1][1] == symbol && game.board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

int main() {
    Game game = {{{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}, 1};
    int row, col, winner;

    srand(time(NULL));

    do {
        print_board(game);
        printf("Player %d, enter row and column: ", game.player);
        scanf("%d%d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || game.board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        game.board[row][col] = game.player == 1 ? PLAYER1 : PLAYER2;

        winner = check_win(game, game.player == 1 ? PLAYER1 : PLAYER2);

        if (winner) {
            print_board(game);
            printf("Player %d wins!\n", game.player);
            break;
        }

        if (game.player == 1) {
            game.player = 2;
        } else {
            int random_row, random_col;

            do {
                random_row = rand() % SIZE;
                random_col = rand() % SIZE;
            } while (game.board[random_row][random_col] != EMPTY);

            game.board[random_row][random_col] = PLAYER2;
            game.player = 1;
        }
    } while (!winner);

    return 0;
}