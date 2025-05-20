//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS];
int turn = 0;

void initBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
            if (j != COLS - 1) printf("|");
        }
        printf("\n");
        if (i != ROWS - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char symbol) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

void computerMove() {
    int i, j;
    srand(time(NULL));
    do {
        i = rand() % ROWS;
        j = rand() % COLS;
    } while (board[i][j] != ' ');
    board[i][j] = 'O';
    turn++;
}

void playerMove() {
    int i, j;
    do {
        printf("Enter row (1-%d): ", ROWS);
        scanf("%d", &i);
        printf("Enter column (1-%d): ", COLS);
        scanf("%d", &j);
    } while (i < 1 || i > ROWS || j < 1 || j > COLS || board[i - 1][j - 1] != ' ');
    board[i - 1][j - 1] = 'X';
    turn++;
}

int main() {
    int choice, i, j;
    do {
        printf("Choose your level of difficulty : \n");
        printf("(1) Easy\n(2) Medium\n(3) Hard\n");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);
    initBoard();
    displayBoard();
    while (turn < 9) {
        if (turn % 2 == 0) {
            playerMove();
        } else {
            printf("Computer's turn...\n");
            switch (choice) {
                case 1:
                    computerMove();
                    break;
                case 2:
                    if (turn == 1) {
                        if (board[1][1] == ' ') {
                            board[1][1] = 'O';
                        } else {
                            board[0][0] = 'O';
                        }
                    } else {
                        computerMove();
                    }
                    break;
                case 3:
                    computerMove();
                    if (checkWin('O')) {
                        displayBoard();
                        printf("Computer wins!\n");
                        return 0;
                    }
                    if (turn < 9) {
                        for (i = 0; i < ROWS; i++) {
                            for (j = 0; j < COLS; j++) {
                                if (board[i][j] == ' ') {
                                    board[i][j] = 'O';
                                    if (checkWin('O')) {
                                        return 0;
                                    }
                                    board[i][j] = ' ';
                                }
                            }
                        }
                        computerMove();
                    }
                    break;
            }
        }
        displayBoard();
        if (checkWin('X')) {
            printf("Player wins!\n");
            return 0;
        }
    }
    printf("It's a tie!\n");
    return 0;
}