//Falcon-180B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 3
#define MAX_COLS 3
#define MAX_NUMBERS 9
#define MAX_PLAYERS 2

int generateRandomBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for(i = 0; i < MAX_ROWS; i++) {
        for(j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % MAX_NUMBERS;
        }
    }
    return 0;
}

int printBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for(i = 0; i < MAX_ROWS; i++) {
        for(j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int checkWin(int board[MAX_ROWS][MAX_COLS], int player) {
    int i, j;
    for(i = 0; i < MAX_ROWS; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    for(j = 0; j < MAX_COLS; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[MAX_ROWS][MAX_COLS];
    int players[MAX_PLAYERS] = {1, 2};
    int currentPlayer = 0;
    int gameOver = 0;

    generateRandomBoard(board);
    while(!gameOver) {
        printBoard(board);
        printf("\nPlayer %d's turn\n", players[currentPlayer]);
        int row, col;
        if(scanf("%d %d", &row, &col)!= 2) {
            printf("Invalid input\n");
            continue;
        }
        row--;
        col--;
        if(board[row][col]!= 0) {
            printf("Invalid move\n");
            continue;
        }
        board[row][col] = players[currentPlayer];
        if(checkWin(board, players[currentPlayer])) {
            printf("Player %d wins!\n", players[currentPlayer]);
            gameOver = 1;
        } else if(currentPlayer == 0) {
            currentPlayer = 1;
        } else {
            currentPlayer = 0;
        }
    }

    return 0;
}