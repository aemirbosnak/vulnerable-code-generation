//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn;  // 0 for WHITE's turn, 1 for BLACK's turn
} ChessGame;

void init_board(ChessGame *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    // Set up pieces for both players
    game->board[0][0] = game->board[0][7] = WHITE;  // Rooks
    game->board[0][1] = game->board[0][6] = WHITE;  // Knights
    game->board[0][2] = game->board[0][5] = WHITE;  // Bishops
    game->board[0][3] = WHITE; // Queen
    game->board[0][4] = WHITE; // King

    game->board[7][0] = game->board[7][7] = BLACK;  // Rooks
    game->board[7][1] = game->board[7][6] = BLACK;  // Knights
    game->board[7][2] = game->board[7][5] = BLACK;  // Bishops
    game->board[7][3] = BLACK; // Queen
    game->board[7][4] = BLACK; // King

    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = WHITE;  // White pawns
        game->board[6][i] = BLACK;  // Black pawns
    }
    game->turn = 0;  // White starts first
}

void print_board(ChessGame *game) {
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        printf("%d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", game->board[row][col]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int is_valid_move(ChessGame *game, char src_col, int src_row, char dest_col, int dest_row) {
    int src_x = src_col - 'a';
    int src_y = src_row - 1;
    int dest_x = dest_col - 'a';
    int dest_y = dest_row - 1;

    if (src_x < 0 || src_x >= BOARD_SIZE || src_y < 0 || src_y >= BOARD_SIZE ||
        dest_x < 0 || dest_x >= BOARD_SIZE || dest_y < 0 || dest_y >= BOARD_SIZE) {
        return 0; // Invalid coordinates
    }

    char piece = game->board[src_y][src_x];
    if ((game->turn == 0 && piece == BLACK) || (game->turn == 1 && piece == WHITE)) {
        return 0; // Not your turn
    }

    // Simple validation: ensure destination is either empty or occupied by an opponent's piece
    char target = game->board[dest_y][dest_x];
    if (target != EMPTY && ((game->turn == 0 && target == WHITE) || (game->turn == 1 && target == BLACK))) {
        return 0; // Can't capture your own piece
    }

    return 1; // Move is valid
}

void move_piece(ChessGame *game, char src_col, int src_row, char dest_col, int dest_row) {
    int src_x = src_col - 'a';
    int src_y = src_row - 1;
    int dest_x = dest_col - 'a';
    int dest_y = dest_row - 1;

    game->board[dest_y][dest_x] = game->board[src_y][src_x]; // Move piece
    game->board[src_y][src_x] = EMPTY; // Empty the source square
    game->turn = 1 - game->turn;  // Switch turn
}

void play_game() {
    ChessGame game;
    init_board(&game);

    while (1) {
        print_board(&game);
        printf("Player %s's turn:\n", game.turn == 0 ? "WHITE" : "BLACK");

        char src_col, dest_col;
        int src_row, dest_row;
        printf("Enter move (e.g. e2 e4): ");
        scanf(" %c%d %c%d", &src_col, &src_row, &dest_col, &dest_row);

        if (is_valid_move(&game, src_col, src_row, dest_col, dest_row)) {
            move_piece(&game, src_col, src_row, dest_col, dest_row);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    play_game();
    return 0;
}