//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define RED 1
#define BLACK 2
#define EMPTY 0

typedef struct {
    int color;
    int king;
} piece;

typedef struct {
    piece board[BOARD_SIZE][BOARD_SIZE];
} board;

void print_board(board *b) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (b->board[i][j].color == RED) {
                printf("R ");
            } else if (b->board[i][j].color == BLACK) {
                printf("B ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    board *b = malloc(sizeof(board));

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    b->board[i][j].color = RED;
                } else if (i > 4) {
                    b->board[i][j].color = BLACK;
                } else {
                    b->board[i][j].color = EMPTY;
                }
            } else {
                b->board[i][j].color = EMPTY;
            }
            b->board[i][j].king = 0;
        }
    }

    // Print the board
    print_board(b);

    // Get the player's move
    int from_row, from_col, to_row, to_col;
    printf("Enter your move (from_row, from_col, to_row, to_col): ");
    scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

    // Check if the move is valid
    if (b->board[from_row][from_col].color == EMPTY) {
        printf("Invalid move: No piece at (%d, %d)\n", from_row, from_col);
    } else if (b->board[from_row][from_col].color == b->board[to_row][to_col].color) {
        printf("Invalid move: Cannot move to a square occupied by your own piece\n");
    } else if (abs(from_row - to_row) != abs(from_col - to_col)) {
        printf("Invalid move: Must move diagonally\n");
    } else if (abs(from_row - to_row) > 2) {
        printf("Invalid move: Cannot move more than two squares at a time\n");
    } else if (b->board[from_row][from_col].king == 0 && (to_row - from_row > 0 && b->board[from_row][from_col].color == RED || to_row - from_row < 0 && b->board[from_row][from_col].color == BLACK)) {
        printf("Invalid move: Cannot move backwards\n");
    } else {
        // Make the move
        b->board[to_row][to_col].color = b->board[from_row][from_col].color;
        b->board[to_row][to_col].king = b->board[from_row][from_col].king;
        b->board[from_row][from_col].color = EMPTY;

        // Check if the player has won
        int red_count = 0;
        int black_count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (b->board[i][j].color == RED) {
                    red_count++;
                } else if (b->board[i][j].color == BLACK) {
                    black_count++;
                }
            }
        }

        if (red_count == 0) {
            printf("Black wins!\n");
        } else if (black_count == 0) {
            printf("Red wins!\n");
        } else {
            // Print the board
            print_board(b);

            // Get the player's move
            printf("Enter your move (from_row, from_col, to_row, to_col): ");
            scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        }
    }

    free(b);

    return 0;
}