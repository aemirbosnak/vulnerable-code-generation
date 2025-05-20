//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define WIN_CONDITION 5

void initBoard(char board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= '-') {
            return 1;
        }
    }
    for (int j = 0; j < MAX_COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j]!= '-') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= '-') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[MAX_ROWS][MAX_COLS];
    initBoard(board);
    int player = 1;
    int choice;
    while (1) {
        drawBoard(board);
        printf("Player %d's turn.\n", player);
        printf("Enter your choice of row and column: ");
        scanf("%d%d", &choice, &choice);
        if (board[choice][choice] == '-') {
            board[choice][choice] = (player % 2) + '0';
            player++;
            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}