//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
    int i;

    // Check rows
    for(i=0; i<ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for(i=0; i<COLS; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    int board[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int player = 1;
    int choice;
    int x, y;
    int flag = 0;

    srand(time(NULL));

    while(!flag) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);

        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);

        if(x >= 0 && x < ROWS && y >= 0 && y < COLS && board[x][y] == 0) {
            board[x][y] = player;

            flag = checkWin(board);

            if(flag) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }

            player =!player;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}