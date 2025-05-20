//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
    int player_turn;
} Game;

void initialize_game(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    
    // Place Player 1 pieces
    for (int i = 0; i < 3; i++) {
        for (int j = (i % 2); j < SIZE; j += 2) {
            game->board[i][j] = PLAYER1;
        }
    }
    
    // Place Player 2 pieces
    for (int i = 5; i < SIZE; i++) {
        for (int j = (i % 2); j < SIZE; j += 2) {
            game->board[i][j] = PLAYER2;
        }
    }
    
    game->player_turn = 1; // Player 1 starts
}

void print_board(Game *game) {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == EMPTY) {
                printf(". ");
            } else if (game->board[i][j] == PLAYER1) {
                printf("1 ");
            } else {
                printf("2 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(Game *game, int start_row, int start_col, int end_row, int end_col) {
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;

    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) return 0; // Out of bounds
    if (game->board[end_row][end_col] != EMPTY) return 0; // Destination not empty

    if (game->player_turn == 1 && row_diff == 1 && (col_diff == -1 || col_diff == 1)) {
        return 1; // Regular move for Player 1
    } else if (game->player_turn == 2 && row_diff == -1 && (col_diff == -1 || col_diff == 1)) {
        return 1; // Regular move for Player 2
    } else {
        return 0; // Invalid move
    }
}

void switch_player(Game *game) {
    game->player_turn = (game->player_turn == 1) ? 2 : 1;
}

int main() {
    Game game;
    initialize_game(&game);
    char start_col, end_col;
    int start_row, end_row;

    while (1) {
        print_board(&game);
        printf("Player %d's turn. Enter move (e.g., A3 B4): ", game.player_turn);
        scanf(" %c%d %c%d", &start_col, &start_row, &end_col, &end_row);
        
        start_col -= 'A'; start_row = SIZE - start_row; // Convert input to array index
        end_col -= 'A'; end_row = SIZE - end_row; // Convert input to array index
        
        if (is_valid_move(&game, start_row, start_col, end_row, end_col)) {
            game.board[end_row][end_col] = game.board[start_row][start_col];
            game.board[start_row][start_col] = EMPTY;
            switch_player(&game);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}