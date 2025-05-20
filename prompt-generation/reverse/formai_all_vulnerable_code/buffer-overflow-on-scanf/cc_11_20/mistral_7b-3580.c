//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY '.'
#define X 'X'
#define O 'O'

typedef struct {
    char board[SIZE][SIZE];
    int current_player;
} Game;

void print_board(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
}

int check_win(Game *game, char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if (game->board[i][0] == symbol && game->board[i][1] == symbol && game->board[i][2] == symbol)
            return 1;
        if (game->board[0][i] == symbol && game->board[1][i] == symbol && game->board[2][i] == symbol)
            return 1;
    }

    if (game->board[0][0] == symbol && game->board[1][1] == symbol && game->board[2][2] == symbol)
        return 1;
    if (game->board[0][2] == symbol && game->board[1][1] == symbol && game->board[2][0] == symbol)
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    Game game;
    int row, col;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game.board[i][j] = EMPTY;
        }
    }

    game.current_player = X;

    while (!check_win(&game, X) && !check_win(&game, O)) {
        print_board(&game);

        do {
            printf("\nPlayer %c (%s), enter the row and column: ", game.current_player, (game.current_player == X) ? "X" : "O");
            scanf("%d %d", &row, &col);

            if (row < 0 || row > SIZE - 1 || col < 0 || col > SIZE - 1 || game.board[row][col] != EMPTY) {
                printf("Invalid move. Try again.\n");
            }
        } while (row < 0 || row > SIZE - 1 || col < 0 || col > SIZE - 1 || game.board[row][col] != EMPTY);

        game.board[row][col] = game.current_player;
        game.current_player = (game.current_player == X) ? O : X;
    }

    print_board(&game);

    if (check_win(&game, X))
        printf("\nPlayer X wins!\n");
    else
        printf("\nPlayer O wins!\n");

    return 0;
}