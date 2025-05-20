//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col) {
    if (from_row >= 0 && from_row < BOARD_SIZE &&
        from_col >= 0 && from_col < BOARD_SIZE &&
        to_row >= 0 && to_row < BOARD_SIZE &&
        to_col >= 0 && to_col < BOARD_SIZE) {
            if (board[from_row][from_col]!= '\0' && board[to_row][to_col] == '\0') {
                return 1;
            }
    }
    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j;

    // Initialize board with pieces
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (i + j) % 2? 'B' : 'W';
        }
    }

    // Print initial board
    print_board(board);

    // Simulate game
    int moves = 0;
    while (moves < 10) {
        int from_row, from_col, to_row, to_col;
        printf("Enter move (row col row col): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        if (is_valid_move(board, from_row, from_col, to_row, to_col)) {
            board[to_row][to_col] = board[from_row][from_col];
            board[from_row][from_col] = '\0';
            moves++;
        } else {
            printf("Invalid move.\n");
        }

        // Print updated board
        print_board(board);
    }

    return 0;
}