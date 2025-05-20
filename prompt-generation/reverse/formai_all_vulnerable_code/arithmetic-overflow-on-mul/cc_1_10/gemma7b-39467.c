//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 6

typedef struct Board {
    int **board;
    int size;
    int turn;
    int winner;
} Board;

Board *initBoard(int size) {
    Board *board = malloc(sizeof(Board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    board->turn = 0;
    board->winner = -1;

    return board;
}

void displayBoard(Board *board) {
    for (int r = 0; r < board->size; r++) {
        for (int c = 0; c < board->size; c++) {
            printf("%d ", board->board[r][c]);
        }
        printf("\n");
    }
}

int movePiece(Board *board, int row, int col, int direction) {
    if (board->board[row][col] == 0) {
        return 0;
    }

    switch (direction) {
        case 0: // Forward
            for (int r = row + 1; r < board->size && board->board[r][col] == 0; r++) {
                board->board[r][col] = board->board[row][col];
            }
            board->board[row][col] = 0;
            break;
        case 1: // Backward
            for (int r = row - 1; r >= 0 && board->board[r][col] == 0; r--) {
                board->board[r][col] = board->board[row][col];
            }
            board->board[row][col] = 0;
            break;
        case 2: // Left
            for (int c = col - 1; c >= 0 && board->board[row][c] == 0; c--) {
                board->board[row][c] = board->board[row][col];
            }
            board->board[row][col] = 0;
            break;
        case 3: // Right
            for (int c = col + 1; c < board->size && board->board[row][c] == 0; c++) {
                board->board[row][c] = board->board[row][col];
            }
            board->board[row][col] = 0;
            break;
    }

    board->turn++;

    if (board->board[board->size - 1][board->size - 1] == board->board[0][0] || board->board[board->size - 1][board->size - 1] == board->board[0][0] * -1) {
        board->winner = board->turn;
    }

    return 1;
}

int main() {
    Board *board = initBoard(MAX_BOARD_SIZE);

    // Place the pieces
    board->board[1][1] = 1;
    board->board[1][2] = -1;
    board->board[2][2] = 1;
    board->board[2][3] = -1;

    // Play the game
    movePiece(board, 1, 1, 0);
    movePiece(board, 2, 2, 2);
    movePiece(board, 1, 2, 1);

    // Display the board
    displayBoard(board);

    // Check if there is a winner
    if (board->winner != -1) {
        printf("Winner: Player %d\n", board->winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}