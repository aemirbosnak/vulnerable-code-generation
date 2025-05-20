//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
    char current_player;
} Game;

void initialize_game(Game* game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1) { // Only setting up black squares
                if (i < 3) {
                    game->board[i][j] = 'x'; // Player 1
                } else if (i > 4) {
                    game->board[i][j] = 'o'; // Player 2
                } else {
                    game->board[i][j] = '.'; // Empty square
                }
            } else {
                game->board[i][j] = ' '; // Not playable
            }
        }
    }
    game->current_player = 'x'; // Player 1 starts
}

void print_board(const Game* game) {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Game* game, int start_row, int start_col, int end_row, int end_col) {
    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) {
        return 0; // Out of bounds
    }
    if (game->board[end_row][end_col] != '.') {
        return 0; // Target square is not empty
    }
    int direction = (game->current_player == 'x') ? 1 : -1;
    if ((end_row - start_row == direction) && (abs(end_col - start_col) == 1)) {
        return 1; // Normal move
    }
    if ((end_row - start_row == 2 * direction) && (abs(end_col - start_col) == 2)) {
        int jump_row = start_row + direction;
        int jump_col = (end_col + start_col) / 2;
        if (game->board[jump_row][jump_col] != '.' && 
            game->board[jump_row][jump_col] != game->current_player) {
            return 1; // Jump move
        }
    }
    return 0; // Invalid move
}

void make_move(Game* game, int start_row, int start_col, int end_row, int end_col) {
    game->board[end_row][end_col] = game->board[start_row][start_col];
    game->board[start_row][start_col] = '.';
    
    // Check for capturing
    if (abs(end_row - start_row) == 2) {
        int jump_row = (start_row + end_row) / 2;
        int jump_col = (start_col + end_col) / 2;
        game->board[jump_row][jump_col] = '.'; // Remove captured piece
    }
}

void switch_player(Game* game) {
    game->current_player = (game->current_player == 'x') ? 'o' : 'x';
}

int main() {
    Game game;
    initialize_game(&game);
    int start_row, start_col, end_row, end_col;
    char col_from, col_to;

    while (1) {
        print_board(&game);
        printf("Current player: %c\n", game.current_player);
        printf("Enter your move (e.g., A2 B3): ");
        scanf(" %c%d %c%d", &col_from, &start_row, &col_to, &end_row);
        
        start_row--; // Adjust for 0-indexing
        end_row--;
        start_col = col_from - 'A';
        end_col = col_to - 'A';
        
        if (is_valid_move(&game, start_row, start_col, end_row, end_col)) {
            make_move(&game, start_row, start_col, end_row, end_col);
            switch_player(&game);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    
    return 0;
}