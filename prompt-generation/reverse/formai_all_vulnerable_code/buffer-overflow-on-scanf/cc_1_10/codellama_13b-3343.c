//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 3
#define Y 3
#define EMPTY ' '
#define CROSS 'X'
#define CIRCLE 'O'

void print_board(char board[X][Y]) {
    printf("  1 | 2 | 3 \n");
    printf("  ---------\n");
    for (int i = 0; i < X; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < Y; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
}

void make_move(char board[X][Y], char player, int row, int col) {
    board[row][col] = player;
}

int is_winning_move(char board[X][Y], char player) {
    // check rows
    for (int i = 0; i < X; i++) {
        int count = 0;
        for (int j = 0; j < Y; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == Y) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < Y; i++) {
        int count = 0;
        for (int j = 0; j < X; j++) {
            if (board[j][i] == player) {
                count++;
            }
        }
        if (count == X) {
            return 1;
        }
    }

    // check diagonals
    int count = 0;
    for (int i = 0; i < X; i++) {
        if (board[i][i] == player) {
            count++;
        }
    }
    if (count == X) {
        return 1;
    }
    count = 0;
    for (int i = 0; i < X; i++) {
        if (board[i][Y - i - 1] == player) {
            count++;
        }
    }
    if (count == X) {
        return 1;
    }

    return 0;
}

int is_board_full(char board[X][Y]) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void make_random_move(char board[X][Y]) {
    int row, col;
    do {
        row = rand() % X;
        col = rand() % Y;
    } while (board[row][col] != EMPTY);
    board[row][col] = CROSS;
}

int main() {
    char board[X][Y] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };
    char player = CROSS;
    int turn = 0;
    while (1) {
        print_board(board);
        if (is_winning_move(board, player)) {
            printf("Player %c wins!\n", player);
            break;
        }
        if (is_board_full(board)) {
            printf("It's a tie!\n");
            break;
        }
        printf("Player %c, enter a row and column: ", player);
        int row, col;
        scanf("%d %d", &row, &col);
        make_move(board, player, row - 1, col - 1);
        turn++;
        if (turn % 2 == 0) {
            player = CIRCLE;
        } else {
            player = CROSS;
        }
    }
    return 0;
}