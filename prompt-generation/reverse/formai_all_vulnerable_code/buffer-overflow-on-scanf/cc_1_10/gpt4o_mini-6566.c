//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X';
char ai = 'O';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

bool isWinning(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playerMove() {
    int row, col;
    while (true) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        row--; col--; // Adjusting for 0-based index

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

void findBestMove(int *bestRow, int *bestCol) {
    int bestValue = -1000;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                int moveValue = -evaluateMove();
                board[i][j] = ' ';
                if (moveValue > bestValue) {
                    *bestRow = i; 
                    *bestCol = j;
                    bestValue = moveValue;
                }
            }
        }
    }
}

int evaluateMove() {
    if (isWinning(ai)) return 10;
    if (isWinning(player)) return -10;
    return 0;
}

void aiMove() {
    int bestRow, bestCol;
    findBestMove(&bestRow, &bestCol);
    board[bestRow][bestCol] = ai;
}

int main() {
    initializeBoard();
    printBoard();

    while (true) {
        playerMove();
        printBoard();
        if (isWinning(player)) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        aiMove();
        printBoard();
        if (isWinning(ai)) {
            printf("AI wins!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}