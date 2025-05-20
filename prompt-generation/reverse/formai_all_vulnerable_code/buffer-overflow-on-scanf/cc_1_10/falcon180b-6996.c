//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
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

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

void get_move(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    int row, col;
    printf("Player %d, enter your move (row and column): ", player);
    scanf("%d %d", &row, &col);
    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col]!= '\0') {
        printf("Invalid move, try again: ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = (player == 1)? 'X' : 'O';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '\0';
        }
    }
    int player = 1;
    while (1) {
        system("clear");
        print_board(board);
        printf("Player %d's turn\n", player);
        get_move(board, player);
        if (check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}