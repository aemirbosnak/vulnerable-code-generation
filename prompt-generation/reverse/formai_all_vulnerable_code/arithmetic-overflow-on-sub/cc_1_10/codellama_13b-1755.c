//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int check_tie(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void make_move(int board[N][N], int player) {
    int row, col;
    printf("Enter the row and column (1-3): ");
    scanf("%d %d", &row, &col);
    board[row - 1][col - 1] = player;
}

int main() {
    int board[N][N] = {0};
    int player = 1;

    while (1) {
        print_board(board);
        make_move(board, player);
        if (check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        if (check_tie(board)) {
            printf("It's a tie!\n");
            break;
        }
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}