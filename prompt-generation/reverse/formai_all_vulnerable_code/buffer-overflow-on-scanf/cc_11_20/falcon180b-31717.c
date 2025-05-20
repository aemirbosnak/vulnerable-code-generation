//Falcon-180B DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = rand() % 2;
        }
    }
    int player = 1;
    while (1) {
        system("clear");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    printf(" ");
                } else {
                    printf("X");
                }
            }
            printf("\n");
        }
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == 0) {
            board[x][y] = player;
            player = (player == 1)? 2 : 1;
            if (check_win(board, player)) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move\n");
        }
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