//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2, PLAYER1_KING, PLAYER2_KING } Piece;
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} Game;

void initialize_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    game->board[i][j] = PLAYER1;
                } else if (i > 4) {
                    game->board[i][j] = PLAYER2;
                } else {
                    game->board[i][j] = EMPTY;
                }
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(Game *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == EMPTY) {
                printf(". ");
            } else if (game->board[i][j] == PLAYER1) {
                printf("1 ");
            } else if (game->board[i][j] == PLAYER2) {
                printf("2 ");
            } else if (game->board[i][j] == PLAYER1_KING) {
                printf("K ");
            } else {
                printf("K ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(Game *game, int start_row, int start_col, int end_row, int end_col, Piece player) {
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    if (game->board[end_row][end_col] != EMPTY) {
        return 0; // Destination not empty
    }

    int row_direction = (player == PLAYER1 || player == PLAYER1_KING) ? 1 : -1;
    if ((end_row - start_row) != row_direction || abs(end_col - start_col) != 1) {
        return 0; // Only diagonal moves by regular pieces
    }

    return 1; // Move is valid
}

void move_piece(Game *game, int start_row, int start_col, int end_row, int end_col) {
    game->board[end_row][end_col] = game->board[start_row][start_col];
    game->board[start_row][start_col] = EMPTY;

    // King promotion
    if (end_row == 0 && game->board[end_row][end_col] == PLAYER1) {
        game->board[end_row][end_col] = PLAYER1_KING;
    } else if (end_row == BOARD_SIZE - 1 && game->board[end_row][end_col] == PLAYER2) {
        game->board[end_row][end_col] = PLAYER2_KING;
    }
}

int main() {
    Game game;
    initialize_board(&game);
    int start_row, start_col, end_row, end_col;
    char col_start, col_end;

    while (1) {
        print_board(&game);
        printf("Player 1's turn (enter move as A1 B2): ");
        scanf(" %c%d %c%d", &col_start, &start_row, &col_end, &end_row);

        start_col = col_start - 'A';
        end_col = col_end - 'A';
        start_row -= 1;
        end_row -= 1;

        if (is_valid_move(&game, start_row, start_col, end_row, end_col, PLAYER1)) {
            move_piece(&game, start_row, start_col, end_row, end_col);
        } else {
            printf("Invalid move! Try again.\n");
        }

        print_board(&game);
        printf("Player 2's turn (enter move as A1 B2): ");
        scanf(" %c%d %c%d", &col_start, &start_row, &col_end, &end_row);

        start_col = col_start - 'A';
        end_col = col_end - 'A';
        start_row -= 1;
        end_row -= 1;

        if (is_valid_move(&game, start_row, start_col, end_row, end_col, PLAYER2)) {
            move_piece(&game, start_row, start_col, end_row, end_col);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}