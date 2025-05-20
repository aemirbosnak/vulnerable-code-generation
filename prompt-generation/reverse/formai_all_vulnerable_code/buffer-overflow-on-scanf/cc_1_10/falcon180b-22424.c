//Falcon-180B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

char board[ROWS][COLS];

void initBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    int player = 0;
    int choice;
    while(player!= -1) {
        printBoard();
        printf("Player %d's turn\n", player + 1);
        printf("Enter your choice of row and column (e.g. 0 0): ");
        scanf("%d %d", &choice, &choice);
        int row = choice / COLS;
        int col = choice % COLS;
        if(row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
            board[row][col] = (player == 0)? 'X' : 'O';
            player = (player == 0)? 1 : 0;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    if(player == -1) {
        printf("It's a tie!\n");
    } else {
        printf("Player %d wins!\n", player + 1);
    }
    return 0;
}