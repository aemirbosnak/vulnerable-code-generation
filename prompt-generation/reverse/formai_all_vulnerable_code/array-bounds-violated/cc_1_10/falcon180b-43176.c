//Falcon-180B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define WIN_CONDITION 3

void initBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWinCondition(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for(int j = 0; j < COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
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

    char board[ROWS][COLS];
    initBoard(board);

    int player = 1;
    int choice;
    while(1) {
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your choice (1-%d): ", ROWS*COLS-1);
        scanf("%d", &choice);
        choice--;

        if(board[choice/3][choice%3]!= '-') {
            printf("Invalid move.\n");
            continue;
        }

        board[choice/3][choice%3] = (player == 1)? 'X' : 'O';

        if(checkWinCondition(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}