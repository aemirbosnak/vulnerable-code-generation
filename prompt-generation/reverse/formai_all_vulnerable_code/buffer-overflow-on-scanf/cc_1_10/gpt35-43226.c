//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARDSIZE 3

char board[BOARDSIZE][BOARDSIZE];
int moveCount = 0;

void printBoard() {
    int i, j;
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWinner() {
    int i, j;
    for (i = 0; i < BOARDSIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') return 1;
            else if (board[i][0] == 'O') return 2;
        }
    }

    for (i = 0; i < BOARDSIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') return 1;
            else if (board[0][i] == 'O') return 2;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') return 1;
        else if (board[0][0] == 'O') return 2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') return 1;
        else if (board[0][2] == 'O') return 2;
    }

    if (moveCount == BOARDSIZE*BOARDSIZE) return 3;

    return 0;
}

void makeMove(int player) {
    int row, col;
    printf("Player %d's turn\n", player);
    printf("Enter row(1-3) and column(1-3) : ");
    scanf("%d %d", &row, &col);
    row--; col--;
    if (row >= 0 && row < BOARDSIZE && col >= 0 && col < BOARDSIZE && board[row][col] == ' ') {
        if (player == 1) board[row][col] = 'X';
        else board[row][col] = 'O';
        moveCount++;
    } else {
        printf("Invalid Move... Please Try Again\n");
        makeMove(player);
    }
}

int miniMax(int isMaximizing) {
    int result = checkWinner();
    if (result != 0) {
        if (result == 1) return -10;
        else if (result == 2) return 10;
        else return 0;
    }
    if (isMaximizing) {
        int bestScore = -1000;
        int i, j;
        for (i = 0; i < BOARDSIZE; i++) {
            for (j = 0; j < BOARDSIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = miniMax(0);
                    board[i][j] = ' ';
                    if (score > bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        int i, j;
        for (i = 0; i < BOARDSIZE; i++) {
            for (j = 0; j < BOARDSIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = miniMax(1);
                    board[i][j] = ' ';
                    if (score < bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

void makeAIMove() {
    int bestScore = -1000;
    int bestRow, bestCol;

    int i, j;
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = miniMax(0);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    board[bestRow][bestCol] = 'O';
    moveCount++;
}

int main() {
    int winner = 0;
    int player = 1;
    int ai = 2;

    int mode;
    printf("Select Game Mode:\n");
    printf("1. Human vs Human\n");
    printf("2. Human vs AI\n");
    scanf("%d", &mode);

    // Initialize board
    int i, j;
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printBoard();

    while (winner == 0) {
        if (mode == 1 || player == 1) {
            makeMove(player);
        } else {
            makeAIMove();
        }
        printBoard();
        winner = checkWinner();
        if (winner == 1) {
            printf("Player 1 (X) wins!\n");
        }
        else if (winner == 2) {
            if (mode == 1) printf("Player 2 (O) wins!\n");
            else printf("Computer (O) wins!\n");
        }
        else if (winner == 3) {
            printf("Draw Game!\n");
        }
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}