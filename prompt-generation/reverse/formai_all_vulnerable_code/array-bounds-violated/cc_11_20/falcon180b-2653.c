//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 10

int main() {
    int board[SIZE][SIZE];
    int player = 0;
    int comp = 1;
    int i, j, k, flag = 0, count = 0;
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
    while (flag == 0) {
        system("clear");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == 0) {
                    printf(" %d ", player);
                } else {
                    printf(" %d ", comp);
                }
            }
            printf("\n");
        }
        if (player == 0) {
            printf("\nPlayer 1's turn\n");
        } else {
            printf("\nPlayer 2's turn\n");
        }
        printf("Enter your move: ");
        scanf("%d %d", &i, &j);
        if (board[i][j]!= 0) {
            printf("\nInvalid move\n");
        } else {
            board[i][j] = player;
            if (checkWin(board, player)) {
                printf("\nPlayer %d wins!\n", player);
                flag = 1;
            } else if (count == SIZE * SIZE - 1) {
                printf("\nTie game\n");
                flag = 1;
            } else {
                player =!player;
                count++;
            }
        }
    }
    return 0;
}

int checkWin(int board[SIZE][SIZE], int player) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    for (j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
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