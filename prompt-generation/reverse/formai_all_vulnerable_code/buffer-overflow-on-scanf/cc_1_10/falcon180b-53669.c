//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }
    return 0;
}

void update_board(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    char player = 'X';
    int move_count = 0;
    while (move_count < BOARD_SIZE * BOARD_SIZE) {
        print_board(board);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '-') {
            update_board(board, row, col, player);
            move_count++;
            if (check_winner(board)) {
                printf("Player %c wins!\n", player);
                break;
            }
            player = (player == 'X')? 'O' : 'X';
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}