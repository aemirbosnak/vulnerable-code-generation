//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
    int red_count;
    int black_count;
} GameState;

void initialize_game(GameState *game) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            game->board[i][j] = EMPTY;
    
    for (int j = 0; j < SIZE; j += 2)
        game->board[0][j] = BLACK;
    for (int j = 1; j < SIZE; j += 2)
        game->board[1][j] = BLACK;
    for (int j = 0; j < SIZE; j += 2)
        game->board[2][j] = BLACK;
        
    for (int j = 1; j < SIZE; j += 2)
        game->board[5][j] = RED;
    for (int j = 0; j < SIZE; j += 2)
        game->board[6][j] = RED;
    for (int j = 1; j < SIZE; j += 2)
        game->board[7][j] = RED;

    game->red_count = 12;
    game->black_count = 12;
}

void print_board(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == RED) printf(" R ");
            else if (game->board[i][j] == BLACK) printf(" B ");
            else printf(" . ");
        }
        printf("\n");
    }
}

bool is_valid_move(GameState *game, int start_row, int start_col, int end_row, int end_col, Piece player) {
    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE)
        return false;
    if (game->board[end_row][end_col] != EMPTY)
        return false;
    
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;

    if (player == RED && row_diff == 1 && abs(col_diff) == 1)
        return true;
    if (player == BLACK && row_diff == -1 && abs(col_diff) == 1)
        return true;

    if (abs(row_diff) == 2 && abs(col_diff) == 2) {
        int jumped_row = (start_row + end_row) / 2;
        int jumped_col = (start_col + end_col) / 2;
        if (game->board[jumped_row][jumped_col] != EMPTY && game->board[jumped_row][jumped_col] != player)
            return true;
    }
    
    return false;
}

void make_move(GameState *game, int start_row, int start_col, int end_row, int end_col) {
    game->board[end_row][end_col] = game->board[start_row][start_col];
    game->board[start_row][start_col] = EMPTY;

    if (abs(end_row - start_row) == 2) {
        int jumped_row = (start_row + end_row) / 2;
        int jumped_col = (start_col + end_col) / 2;
        game->board[jumped_row][jumped_col] = EMPTY;
        if (game->board[jumped_row][jumped_col] == RED) game->red_count--;
        else game->black_count--;
    }
}

void play_game() {
    GameState game;
    initialize_game(&game);
    Piece current_player = RED;
    int start_row, start_col, end_row, end_col;

    while (game.red_count > 0 && game.black_count > 0) {
        print_board(&game);
        printf("Player %s's turn. Enter move (start_row start_col end_row end_col): ", current_player == RED ? "RED" : "BLACK");
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

        if (is_valid_move(&game, start_row, start_col, end_row, end_col, current_player)) {
            make_move(&game, start_row, start_col, end_row, end_col);
            current_player = (current_player == RED) ? BLACK : RED;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    print_board(&game);
    printf("Player %s wins!\n", game.red_count > 0 ? "RED" : "BLACK");
}

int main() {
    play_game();
    return 0;
}