//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_1 'X'
#define PLAYER_2 'O'

typedef struct {
    int rows;
    int cols;
    char board[BOARD_SIZE][BOARD_SIZE];
} Board;

void print_board(Board *board) {
    for (int i = 0; i < board->rows; ++i) {
        for (int j = 0; j < board->cols; ++j) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

int check_win(Board *board, char player) {
    for (int i = 0; i < board->rows; ++i) {
        if (board->board[i][0] == player && board->board[i][1] == player && board->board[i][2] == player) {
            return 1;
        }
    }

    for (int j = 0; j < board->cols; ++j) {
        if (board->board[0][j] == player && board->board[1][j] == player && board->board[2][j] == player) {
            return 1;
        }
    }

    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    }

    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
        return 1;
    }

    return 0;
}

void initialize_board(Board *board) {
    for (int i = 0; i < board->rows; ++i) {
        for (int j = 0; j < board->cols; ++j) {
            board->board[i][j] = ' ';
        }
    }
}

int main() {
    Board board;
    board.rows = BOARD_SIZE;
    board.cols = BOARD_SIZE;
    initialize_board(&board);

    int current_player = 1;
    while (!check_win(&board, PLAYER_1) && !check_win(&board, PLAYER_2)) {
        print_board(&board);

        int row, col;
        printf("Player %d (%c), enter row and column: ", current_player, current_player == 1 ? 'X' : 'O');
        scanf("%d%d", &row, &col);

        if (row < 0 || row >= board.rows || col < 0 || col >= board.cols || board.board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board.board[row][col] = current_player == 1 ? PLAYER_1 : PLAYER_2;
        current_player = 3 - current_player;
    }

    print_board(&board);

    return 0;
}