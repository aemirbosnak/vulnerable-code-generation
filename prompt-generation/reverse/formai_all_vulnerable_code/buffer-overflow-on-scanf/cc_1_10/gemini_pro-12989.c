//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY,
    BLACK,
    WHITE
} Piece;

typedef struct {
    int row;
    int col;
} Position;

Piece board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Place the initial pieces
    board[3][3] = WHITE;
    board[3][4] = BLACK;
    board[4][3] = BLACK;
    board[4][4] = WHITE;

    // Print the initial board
    print_board();

    // Get the player's move
    Position move;
    printf("Enter your move (e.g. a1): ");
    scanf("%c%d", &move.col, &move.row);

    // Place the player's piece on the board
    board[move.row - 1][move.col - 'a'] = WHITE;

    // Print the updated board
    print_board();

    return 0;
}