//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '\0';
        }
    }
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }

    return 0;
}

void makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (board[row][col] == '\0') {
            board[row][col] = 'X';
        } else {
            printf("Invalid move\n");
        }
    } else {
        printf("Invalid coordinates\n");
    }
}

void AI() {
    srand(time(NULL));
    int randRow, randCol, flag = 0;

    while (!flag) {
        randRow = rand() % 3;
        randCol = rand() % 3;

        if (board[randRow][randCol] == '\0') {
            makeMove(randRow, randCol);
            flag = 1;
        }
    }
}

int main() {
    initBoard();
    int player = 1;

    while (1) {
        system("clear");
        printBoard();

        if (player == 1) {
            printf("Player 1's turn\n");
            int row, col, valid = 0;

            while (!valid) {
                scanf("%d %d", &row, &col);

                if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                    if (board[row][col] == '\0') {
                        makeMove(row, col);
                        valid = 1;
                        player = 2;
                    } else {
                        printf("Invalid move\n");
                    }
                } else {
                    printf("Invalid coordinates\n");
                }
            }

            if (checkWin() == 1) {
                printf("Player 1 wins!\n");
                break;
            } else if (checkWin() == 2) {
                printf("It's a tie!\n");
                break;
            }
        } else {
            AI();

            if (checkWin() == 2) {
                printf("AI wins!\n");
                break;
            }
        }
    }

    return 0;
}