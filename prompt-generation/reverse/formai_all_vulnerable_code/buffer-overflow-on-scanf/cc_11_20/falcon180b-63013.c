//Falcon-180B DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define MAX_ROWS 5
#define MAX_COLS 7

void drawBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == 0)
                printf(" %d ", i*MAX_COLS + j);
            else if (board[i][j] == 1)
                printf(" X ");
            else
                printf(" O ");
        }
        printf("\n");
    }
}

int checkWin(int board[MAX_ROWS][MAX_COLS], int player) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    for (j = 0; j < MAX_COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

int main() {
    int board[MAX_ROWS][MAX_COLS] = {0};
    int player = 1;
    int choice;
    int i, j;
    srand(time(NULL));

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (i == 0 || i == 1 || i == 2 || j == 0 || j == 1 || j == 2 || i == j) {
                board[i][j] = -1;
            }
        }
    }

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &i, &j);
        if (board[i-1][j-1]!= -1) {
            board[i-1][j-1] = player;
            player = (player == 1)? 2 : 1;
            if (checkWin(board, player)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}