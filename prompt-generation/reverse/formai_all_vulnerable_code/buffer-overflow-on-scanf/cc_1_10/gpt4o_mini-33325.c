//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define EMPTY '.'
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int current_turn;
} Game;

void initialize_game(Game *game) {
    // Initialize an empty board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    
    // Place pieces in a post-apocalyptic fashion
    game->board[0][0] = WHITE;
    game->board[0][1] = WHITE;
    game->board[0][2] = WHITE;
    game->board[1][1] = BLACK;
    game->board[1][2] = BLACK;

    game->current_turn = WHITE;
}

void print_board(Game *game) {
    printf("\nPost-Apocalyptic Chess Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int move_piece(Game *game, int start_row, int start_col, int end_row, int end_col) {
    if (start_row < 0 || start_col < 0 || end_row < 0 || end_col < 0 || 
        start_row >= BOARD_SIZE || start_col >= BOARD_SIZE || 
        end_row >= BOARD_SIZE || end_col >= BOARD_SIZE) {
        return 0; // Out of bounds
    }

    char piece = game->board[start_row][start_col];
    if (piece == EMPTY || piece != game->current_turn) {
        return 0; // Invalid move
    }

    // Move piece assuming straight line in this simple version
    if (game->board[end_row][end_col] == EMPTY) {
        game->board[end_row][end_col] = piece;
        game->board[start_row][start_col] = EMPTY;
        return 1; // Move successful
    }

    return 0; // Can't move to an occupied space
}

void switch_turn(Game *game) {
    game->current_turn = (game->current_turn == WHITE) ? BLACK : WHITE;
}

void game_loop() {
    Game game;
    initialize_game(&game);
    print_board(&game);

    while (1) {
        printf("\n%s's turn. Enter move (start_row start_col end_row end_col): ", 
               game.current_turn == WHITE ? "WHITE" : "BLACK");
        
        int start_row, start_col, end_row, end_col;
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

        if (move_piece(&game, start_row, start_col, end_row, end_col)) {
            print_board(&game);
            switch_turn(&game);
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Chess Engine!\n");
    game_loop();
    return 0;
}