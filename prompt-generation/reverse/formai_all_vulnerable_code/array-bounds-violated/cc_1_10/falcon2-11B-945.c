//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int board[ROWS][COLS];
    char player;
} Game;

int get_player(Game *game) {
    if (strcmp(game->player, "X") == 0) {
        return 1;
    } else if (strcmp(game->player, "O") == 0) {
        return -1;
    } else {
        return 0;
    }
}

void print_board(Game *game) {
    printf("  1 | 2 | 3\n");
    printf(" +---+---+\n");
    printf("| %c | %c | %c |\n", game->board[0][0], game->board[0][1], game->board[0][2]);
    printf("| %c | %c | %c |\n", game->board[1][0], game->board[1][1], game->board[1][2]);
    printf("| %c | %c | %c |\n", game->board[2][0], game->board[2][1], game->board[2][2]);
    printf(" +---+---+\n");
    printf("  4 | 5 | 6\n");
    printf(" +---+---+\n");
    printf("| %c | %c | %c |\n", game->board[0][3], game->board[0][4], game->board[0][5]);
    printf("| %c | %c | %c |\n", game->board[1][3], game->board[1][4], game->board[1][5]);
    printf("| %c | %c | %c |\n", game->board[2][3], game->board[2][4], game->board[2][5]);
    printf(" +---+---+\n");
    printf("  7 | 8 | 9\n");
    printf(" +---+---+\n");
}

int is_game_over(Game *game) {
    bool is_tie = true;
    bool is_win = false;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (game->board[i][j] == 0) {
                is_tie = false;
                break;
            }
        }
        if (!is_tie) {
            break;
        }
    }

    if (is_tie) {
        return 0;
    } else if (game->board[0][0] == game->board[0][1] && game->board[0][1] == game->board[0][2]) {
        is_win = true;
    } else if (game->board[1][0] == game->board[1][1] && game->board[1][1] == game->board[1][2]) {
        is_win = true;
    } else if (game->board[2][0] == game->board[2][1] && game->board[2][1] == game->board[2][2]) {
        is_win = true;
    } else if (game->board[0][0] == game->board[1][0] && game->board[1][0] == game->board[2][0]) {
        is_win = true;
    } else if (game->board[0][1] == game->board[1][1] && game->board[1][1] == game->board[2][1]) {
        is_win = true;
    } else if (game->board[0][2] == game->board[1][2] && game->board[1][2] == game->board[2][2]) {
        is_win = true;
    } else if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2]) {
        is_win = true;
    } else if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0]) {
        is_win = true;
    }

    return is_win;
}

int choose_move(Game *game) {
    int move = 0;
    int best_move = 0;
    int best_score = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (game->board[i][j] == 0) {
                if (is_valid_move(game, i, j)) {
                    int score = get_score(game, i, j);

                    if (score > best_score) {
                        best_score = score;
                        best_move = i * COLS + j;
                    }
                }
            }
        }
    }

    move = best_move;
    game->board[move / COLS][move % COLS] = get_player(game);

    return move;
}

int is_valid_move(Game *game, int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && game->board[row][col] == 0);
}

int get_score(Game *game, int row, int col) {
    int score = 0;

    if (game->board[row][col] == -1) {
        score = 10;
    } else if (game->board[row][col] == 1) {
        score = -10;
    }

    return score;
}

int main() {
    Game game;
    game.player = "X";
    game.board[0][0] = 0;
    game.board[0][1] = 0;
    game.board[0][2] = 0;
    game.board[1][0] = 0;
    game.board[1][1] = 0;
    game.board[1][2] = 0;
    game.board[2][0] = 0;
    game.board[2][1] = 0;
    game.board[2][2] = 0;
    game.board[0][3] = 0;
    game.board[0][4] = 0;
    game.board[0][5] = 0;
    game.board[1][3] = 0;
    game.board[1][4] = 0;
    game.board[1][5] = 0;
    game.board[2][3] = 0;
    game.board[2][4] = 0;
    game.board[2][5] = 0;

    while (!is_game_over(&game)) {
        int move = choose_move(&game);
        game.board[move / COLS][move % COLS] = get_player(&game);

        if (get_player(&game) == -1) {
            print_board(&game);
            printf("\n");
            break;
        }

        if (get_player(&game) == 1) {
            print_board(&game);
            printf("\n");
            break;
        }
    }

    if (is_game_over(&game)) {
        printf("%c wins!\n", get_player(&game));
    }

    return 0;
}