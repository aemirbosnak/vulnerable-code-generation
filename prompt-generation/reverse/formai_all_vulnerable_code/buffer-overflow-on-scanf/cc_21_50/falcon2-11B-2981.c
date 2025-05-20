//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>

int main() {
    int board[3][3];
    int player = 1;
    int win = 0;

    printf("Tic Tac Toe\n");
    printf("Player %d's turn\n", player);
    printf("Enter your move (1-9): ");
    scanf("%d", &board[0][0]);
    printf("Board: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    player = (player == 1)? 2 : 1;

    while (win == 0) {
        printf("Player %d's turn\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &board[0][0]);
        printf("Board: \n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            win = 1;
        } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            win = 1;
        } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
            win = 1;
        } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
            win = 1;
        } else if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
            win = 1;
        } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
            win = 1;
        } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
            win = 1;
        } else {
            player = (player == 1)? 2 : 1;
        }
    }
    if (win == 1) {
        printf("Player %d wins!\n", player);
    } else if (win == 0) {
        printf("Draw!\n");
    }
    return 0;
}