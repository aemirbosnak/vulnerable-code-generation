//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'w'
#define BLACK 'b'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} Game;

void init_board(Game *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    game->board[0][0] = game->board[0][1] = game->board[0][2] = game->board[0][3] = 'R';
    game->board[0][4] = 'K';
    game->board[0][5] = game->board[0][6] = game->board[0][7] = 'N';
    game->board[1][0] = game->board[1][1] = game->board[1][2] = game->board[1][3] = 'P';

    game->board[7][0] = game->board[7][1] = game->board[7][2] = game->board[7][3] = 'r';
    game->board[7][4] = 'k';
    game->board[7][5] = game->board[7][6] = game->board[7][7] = 'n';
    game->board[6][0] = game->board[6][1] = game->board[6][2] = game->board[6][3] = 'p';

    game->turn = WHITE;
}

void print_board(Game *game) {
    printf("\n     a  b  c  d  e  f  g  h\n");
    printf("   ------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", game->board[i][j]);
        }
        printf("\n   ------------------------\n");
    }
}

int is_valid_move(char piece, int start_row, int start_col, int end_row, int end_col) {
    // Shockingly simple move validation
    if (piece == EMPTY) return 0; // Not a valid piece
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE) return 0;
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) return 0;
    return 1; // For now, just say it’s valid
}

void make_move(Game *game, int start_row, int start_col, int end_row, int end_col) {
    char piece = game->board[start_row][start_col];
    if (is_valid_move(piece, start_row, start_col, end_row, end_col)) {
        game->board[end_row][end_col] = piece;
        game->board[start_row][start_col] = EMPTY;
    } else {
        printf("Whoa! That's not a valid move!\n");
    }
}

void change_turn(Game *game) {
    game->turn = (game->turn == WHITE) ? BLACK : WHITE;
}

void play_game() {
    Game game;
    init_board(&game);
    int start_row, start_col, end_row, end_col;

    while (1) {
        print_board(&game);
        printf("Turn for %s! Enter move (e.g., e2 e4): ", (game.turn == WHITE) ? "White" : "Black");
        char start[3], end[3];
        scanf("%s %s", start, end);
        
        start_col = start[0] - 'a';
        start_row = 8 - (start[1] - '0');
        end_col = end[0] - 'a';
        end_row = 8 - (end[1] - '0');
        
        make_move(&game, start_row, start_col, end_row, end_col);
        change_turn(&game);
    }
}

int main() {
    printf("Welcome to the Shockingly Simple Chess Engine!\n");
    play_game();
    return 0;
}