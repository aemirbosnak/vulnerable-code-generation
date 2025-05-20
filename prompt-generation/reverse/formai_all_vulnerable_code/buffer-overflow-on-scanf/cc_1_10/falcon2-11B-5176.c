//Falcon2-11B DATASET v1.0 Category: Chess engine ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BOARD_SIZE 8

typedef struct board {
    int board[BOARD_SIZE][BOARD_SIZE];
    int current_player;
} Board;

void initialize_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->current_player = 1;
}

void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Board *board, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return 0;
    }
    if (board->board[x][y]!= 0) {
        return 0;
    }
    return 1;
}

void make_move(Board *board, int x, int y) {
    if (is_valid_move(board, x, y)) {
        board->board[x][y] = board->current_player;
        board->current_player = 3 - board->current_player;
    }
}

int main() {
    Board board;
    initialize_board(&board);
    print_board(&board);

    int move;
    while (1) {
        printf("Enter the coordinates of the move (x y): ");
        scanf("%d %d", &move, &move);
        if (move < 0 || move >= BOARD_SIZE * BOARD_SIZE) {
            continue;
        }
        make_move(&board, move / BOARD_SIZE, move % BOARD_SIZE);
        print_board(&board);
        if (board.current_player == 3) {
            break;
        }
    }
    printf("Game over! %s wins!\n", board.current_player == 1? "White" : "Black");
    return 0;
}