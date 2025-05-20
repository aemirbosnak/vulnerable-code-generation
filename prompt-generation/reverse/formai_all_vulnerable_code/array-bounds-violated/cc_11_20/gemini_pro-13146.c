//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define BLACK 'b'
#define WHITE 'w'
#define EMPTY ' '

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int black_count = 0;
    int white_count = 0;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = EMPTY;
            } else {
                if (i < 3) {
                    board[i][j] = BLACK;
                    black_count++;
                } else if (i >= 5) {
                    board[i][j] = WHITE;
                    white_count++;
                } else {
                    board[i][j] = EMPTY;
                }
            }
        }
    }

    // Print the board
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Get the player's move
    char player;
    int from_row, from_col, to_row, to_col;
    while (1) {
        printf("Enter your move (e.g. b2b3): ");
        scanf(" %c%d%c%d", &player, &from_row, &to_row, &to_col);
        if (player == BLACK && board[from_row][from_col] == BLACK) {
            break;
        } else if (player == WHITE && board[from_row][from_col] == WHITE) {
            break;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    // Move the piece
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;

    // Check if the player has won
    if (black_count == 0) {
        printf("White wins!\n");
    } else if (white_count == 0) {
        printf("Black wins!\n");
    } else {
        // Print the board
        printf("   ");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
        }
        printf("\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}