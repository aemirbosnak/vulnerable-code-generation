//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player1;
    char player2;
    char current_player;
} Game;

void initialize_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {  // Only fill odd squares
                if (i < 3) {
                    game->board[i][j] = game->player1;  // Player 1's pieces
                } else if (i > 4) {
                    game->board[i][j] = game->player2;  // Player 2's pieces
                } else {
                    game->board[i][j] = ' ';  // Empty square
                }
            } else {
                game->board[i][j] = ' ';  // Empty square
            }
        }
    }
    game->current_player = game->player1;
}

void print_board(Game *game) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Game *game, int start_row, int start_col, int end_row, int end_col) {
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE)
        return 0;  // Out of bounds
    if (game->board[end_row][end_col] != ' ')
        return 0;  // Destination must be empty

    // Piece movement rules
    if (game->current_player == game->player1) {
        if (start_row - end_row != 1 || abs(start_col - end_col) != 1) {
            return 0;  // Valid move for Player 1
        }
    } else {
        if (end_row - start_row != 1 || abs(start_col - end_col) != 1) {
            return 0;  // Valid move for Player 2
        }
    }
    
    return 1; // Move is valid
}

void switch_player(Game *game) {
    game->current_player = (game->current_player == game->player1) ? game->player2 : game->player1;
}

void make_move(Game *game, int start_row, int start_col, int end_row, int end_col) {
    game->board[end_row][end_col] = game->current_player;
    game->board[start_row][start_col] = ' ';
}

int main() {
    Game game;
    game.player1 = 'x';
    game.player2 = 'o';
    
    initialize_board(&game);
    
    while (1) {
        print_board(&game);
        
        printf("Current Player: %c\n", game.current_player);
        int start_row, start_col, end_row, end_col;

        printf("Enter move (start_row start_col end_row end_col): ");
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

        if (is_valid_move(&game, start_row, start_col, end_row, end_col)) {
            make_move(&game, start_row, start_col, end_row, end_col);
            switch_player(&game);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}