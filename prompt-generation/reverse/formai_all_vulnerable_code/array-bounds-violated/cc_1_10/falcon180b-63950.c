//Falcon-180B DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define WIN_CONDITION 3

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int player = 1;
    int choice;
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    while(1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &i, &j);

        if(board[i-1][j-1]!= 0) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[i-1][j-1] = player;
        player = (player == 1)? 2 : 1;

        if(checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        if(player == 2 && checkWin(board)) {
            printf("\nPlayer 1 wins!\n");
            break;
        }
    }

    return 0;
}