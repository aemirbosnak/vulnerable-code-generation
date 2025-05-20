//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = rand() % 2;
        }
    }
    int player = 1;
    int turn = 0;
    int win = 0;
    while (win == 0) {
        system("clear");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    printf("X");
                } else {
                    printf("O");
                }
                printf(" ");
            }
            printf("\n");
        }
        if (player == 1) {
            printf("Player 1's turn\n");
        } else {
            printf("Player 2's turn\n");
        }
        if (turn == 8) {
            win = 1;
            printf("Tie game!\n");
        }
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= 3 && y >= 1 && y <= 3 && board[x - 1][y - 1] == 0) {
            board[x - 1][y - 1] = player;
            turn++;
            if (check_win(board, player)) {
                win = 1;
                printf("Player %d wins!\n", player);
            }
        } else {
            printf("Invalid move\n");
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}

int check_win(int board[3][3], int player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}