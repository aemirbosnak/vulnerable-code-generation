//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SYMBOL '-'
#define PLAYER_ONE_SYMBOL 'X'
#define PLAYER_TWO_SYMBOL 'O'

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return 1;
        }
    }
    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return 1;
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

int check_full_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_SYMBOL) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SYMBOL, EMPTY_SYMBOL, EMPTY_SYMBOL},
                                             {EMPTY_SYMBOL, EMPTY_SYMBOL, EMPTY_SYMBOL},
                                             {EMPTY_SYMBOL, EMPTY_SYMBOL, EMPTY_SYMBOL}};
    int player = 1;
    int x, y;
    while (!check_full_board(board)) {
        print_board(board);
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d %d", &x, &y);
        if ((x >= 0) && (x < BOARD_SIZE) && (y >= 0) && (y < BOARD_SIZE)) {
            if (board[x][y] == EMPTY_SYMBOL) {
                board[x][y] = (player == 1)? PLAYER_ONE_SYMBOL : PLAYER_TWO_SYMBOL;
                player = (player == 1)? 2 : 1;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    print_board(board);
    if (check_winner(board) == 1) {
        printf("Player %d wins!\n", (player == 1)? 1 : 2);
    } else {
        printf("It's a draw.\n");
    }
    return 0;
}