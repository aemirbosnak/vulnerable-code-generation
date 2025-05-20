//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char piece[2];
    int row, col;
} Piece;

typedef struct {
    int board[8][8];
    int player;
    int turn;
} Board;

int checkers(Board* board, int row, int col) {
    if (board->board[row][col] == 1) {
        return 1;
    }
    else if (board->board[row][col] == -1) {
        return -1;
    }
    else {
        return 0;
    }
}

void print_board(Board* board) {
    printf("\nPlayer %d's turn\n", board->player);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board->board[i][j] == 1? 'X' : 'O');
        }
        printf("\n");
    }
    printf("\n");
}

void move_piece(Board* board, Piece* piece, int row, int col) {
    board->board[piece->row][piece->col] = -1;
    board->board[row][col] = 1;
    piece->row = row;
    piece->col = col;
    board->turn = -board->turn;
}

void jump_piece(Board* board, Piece* piece, int row, int col) {
    if (checkers(board, row, col) == 1) {
        board->board[row][col] = -1;
        move_piece(board, piece, piece->row, piece->col);
        board->turn = -board->turn;
    }
}

int main() {
    Board board;
    Piece piece;
    int row, col;
    int num_moves = 0;

    while (1) {
        print_board(&board);
        printf("Enter row and column of piece to move (row, col): ");
        scanf("%d,%d", &row, &col);
        if (row < 0 || row >= 8 || col < 0 || col >= 8) {
            printf("Invalid move.\n");
            continue;
        }
        if (board.board[row][col] == 0) {
            printf("No piece in position (%d, %d).\n", row, col);
            continue;
        }
        if (board.board[row][col] == -1) {
            printf("Invalid move (jumping).\n");
            continue;
        }
        if (board.player == -1) {
            printf("It is not your turn.\n");
            continue;
        }
        if (board.turn == -1) {
            move_piece(&board, &piece, row, col);
        }
        else {
            jump_piece(&board, &piece, row, col);
        }
        num_moves++;
        if (num_moves >= 32) {
            break;
        }
        board.player *= -1;
        board.turn *= -1;
    }

    printf("Game over!\n");

    return 0;
}