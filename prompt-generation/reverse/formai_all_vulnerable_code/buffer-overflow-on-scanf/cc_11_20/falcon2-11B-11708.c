//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int board[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    char player;

    printf("Welcome to the C Table Game!\n");

    while (1) {
        printf("Enter your move (A for left, D for right, W for up, S for down): ");
        scanf("%c", &player);

        switch (player) {
            case 'A':
                if (board[1][1] > 0) {
                    board[1][1]--;
                    printf("Move accepted.\n");
                } else {
                    printf("Move not accepted.\n");
                }
                break;
            case 'D':
                if (board[2][2] > 0) {
                    board[2][2]--;
                    printf("Move accepted.\n");
                } else {
                    printf("Move not accepted.\n");
                }
                break;
            case 'W':
                if (board[0][0] > 0) {
                    board[0][0]--;
                    printf("Move accepted.\n");
                } else {
                    printf("Move not accepted.\n");
                }
                break;
            case 'S':
                if (board[1][2] > 0) {
                    board[1][2]--;
                    printf("Move accepted.\n");
                } else {
                    printf("Move not accepted.\n");
                }
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        printf("Current board:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}