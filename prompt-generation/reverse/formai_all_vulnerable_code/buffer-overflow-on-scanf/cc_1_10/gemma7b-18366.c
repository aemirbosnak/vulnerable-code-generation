//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 3

typedef struct Board {
    int **board;
    int size;
    int current_player;
    int winner;
} Board;

void initialize_board(Board *board) {
    board->board = (int **)malloc(board->size * sizeof(int *));
    for (int i = 0; i < board->size; i++) {
        board->board[i] = (int *)malloc(board->size * sizeof(int));
    }
    board->size = board->size;
    board->current_player = 1;
    board->winner = 0;
}

void place_mark(Board *board, int row, int col) {
    if (board->board[row][col] == 0) {
        board->board[row][col] = board->current_player;
        board->current_player *= -1;
    }
}

int check_win(Board *board) {
    // Check rows
    for (int r = 0; r < board->size; r++) {
        if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != 0) {
            return board->board[r][0];
        }
    }

    // Check columns
    for (int c = 0; c < board->size; c++) {
        if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != 0) {
            return board->board[0][c];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // No winner
    return 0;
}

int main() {
    Board board;
    initialize_board(&board);

    // Game loop
    while (!check_win(&board) && board.board[0][0] != board.board[0][1] && board.board[0][0] != board.board[0][2]) {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Place the mark
        place_mark(&board, row, col);
    }

    // Game over
    if (check_win(&board) != 0) {
        printf("Winner: Player %d\n", check_win(&board));
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}