//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Piece;
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int player1_pieces;
    int player2_pieces;
} CheckersGame;

void initialize_board(CheckersGame *game) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row < 3 && (row + col) % 2 == 1) {
                game->board[row][col] = PLAYER1;
                game->player1_pieces++;
            } else if (row > 4 && (row + col) % 2 == 1) {
                game->board[row][col] = PLAYER2;
                game->player2_pieces++;
            } else {
                game->board[row][col] = EMPTY;
            }
        }
    }
}

void print_board(CheckersGame *game) {
    printf("  a b c d e f g h\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (game->board[row][col]) {
                case EMPTY:   printf(". "); break;
                case PLAYER1: printf("O "); break;
                case PLAYER2: printf("X "); break;
            }
        }
        printf("\n");
    }
}

int move_piece(CheckersGame *game, int from_row, int from_col, int to_row, int to_col, int player) {
    Piece current_player = (player == 1) ? PLAYER1 : PLAYER2;
    Piece opponent = (player == 1) ? PLAYER2 : PLAYER1;

    if (game->board[from_row][from_col] == current_player && game->board[to_row][to_col] == EMPTY) {
        // Valid Movement
        if ((player == 1 && to_row == from_row + 1 && (to_col == from_col - 1 || to_col == from_col + 1)) ||
            (player == 2 && to_row == from_row - 1 && (to_col == from_col - 1 || to_col == from_col + 1))) {
            game->board[to_row][to_col] = current_player;
            game->board[from_row][from_col] = EMPTY;
            return 1;
        }
    }
    return 0;
}

int check_winner(CheckersGame *game) {
    if (game->player1_pieces == 0)
        return 2; // Player 2 wins
    if (game->player2_pieces == 0)
        return 1; // Player 1 wins
    return 0; // No winner yet
}

int main() {
    CheckersGame game;
    game.player1_pieces = 12;
    game.player2_pieces = 12;

    initialize_board(&game);
    int currentPlayer = 1;
    int winner = 0;

    while (winner == 0) {
        print_board(&game);
        printf("Player %d's turn. Enter your move (e.g., '2 a 3 b'):\n", currentPlayer);
        
        int from_row, to_row, from_col, to_col;
        char from_col_ch, to_col_ch;
        scanf("%d %c %d %c", &from_row, &from_col_ch, &to_row, &to_col_ch);
        
        from_row--; // Adjust for 0-indexing
        to_row--;
        from_col = from_col_ch - 'a';
        to_col = to_col_ch - 'a';

        if (move_piece(&game, from_row, from_col, to_row, to_col, currentPlayer)) {
            winner = check_winner(&game);
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch Players
        } else {
            printf("Invalid move, please try again.\n");
        }
    }

    printf("Congratulations! Player %d wins!\n", winner);
    return 0;
}