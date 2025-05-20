//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
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

int check_tie(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j]!= 1 && board[i][j]!= 2) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[SIZE][SIZE] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int player = 1;
    int x, y;

    while (1) {
        print_board(board);
        printf("Player %d's turn\n", player);
        scanf("%d%d", &x, &y);
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid move\n");
            continue;
        }
        if (board[x][y]!= 0) {
            printf("Invalid move\n");
            continue;
        }
        board[x][y] = player;
        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        if (check_tie(board)) {
            printf("Tie game!\n");
            break;
        }
        player = (player == 1)? 2 : 1;
    }

    return 0;
}