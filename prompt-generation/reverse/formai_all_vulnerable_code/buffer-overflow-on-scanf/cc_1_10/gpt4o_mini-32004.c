//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, BLACK, WHITE } Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} CheckersGame;

void initialize_game(CheckersGame *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    // Set up initial positions for black and white pieces
    for (int i = 0; i < 3; i++) {
        for (int j = (i % 2); j < BOARD_SIZE; j += 2) {
            game->board[i][j] = BLACK;
        }
    }
    for (int i = 5; i < 8; i++) {
        for (int j = (i % 2); j < BOARD_SIZE; j += 2) {
            game->board[i][j] = WHITE;
        }
    }
}

void print_board(CheckersGame *game) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == BLACK) {
                printf("B ");
            } else if (game->board[i][j] == WHITE) {
                printf("W ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(CheckersGame *game, int start_row, int start_col, int end_row, int end_col, Piece player) {
    // Check if the move is diagonal
    if (abs(start_row - end_row) == 1 && abs(start_col - end_col) == 1 && game->board[end_row][end_col] == EMPTY) {
        return 1; // Regular move
    } 
    // Check for jump move
    else if (abs(start_row - end_row) == 2 && abs(start_col - end_col) == 2) {
        int mid_row = (start_row + end_row) / 2;
        int mid_col = (start_col + end_col) / 2;
        if (game->board[mid_row][mid_col] != EMPTY && game->board[mid_row][mid_col] != player) {
            return 2; // Jump move
        }
    }
    return 0; // Invalid move
}

void make_move(CheckersGame *game, int start_row, int start_col, int end_row, int end_col, Piece player) {
    game->board[end_row][end_col] = player;
    game->board[start_row][start_col] = EMPTY;
    // Handle jumping over a piece
    if (abs(start_row - end_row) == 2) {
        int mid_row = (start_row + end_row) / 2;
        int mid_col = (start_col + end_col) / 2;
        game->board[mid_row][mid_col] = EMPTY;
    }
}

int main() {
    CheckersGame game;
    initialize_game(&game);
    Piece current_player = BLACK;

    while (1) {
        print_board(&game);
        int start_row, start_col, end_row, end_col;

        printf("Current Player: %s\n", current_player == BLACK ? "Black" : "White");
        printf("Enter your move (start_row start_col end_row end_col): ");
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

        if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
            end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
            printf("Invalid move range! Please be careful next time.\n");
            continue;
        }

        if (game.board[start_row][start_col] != current_player) {
            printf("Not your piece! Try again.\n");
            continue;
        }

        int move_type = is_valid_move(&game, start_row, start_col, end_row, end_col, current_player);
        if (move_type == 1 || move_type == 2) {
            make_move(&game, start_row, start_col, end_row, end_col, current_player);
            current_player = (current_player == BLACK) ? WHITE : BLACK;
        } else {
            printf("Oops! That move is not valid. Think again!\n");
        }
    }

    return 0;
}