//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdio.h>

char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char symbol) {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

int minimax(int depth, int isMax, char player) {
    int i, j, score, bestScore;
    bestScore = (player == 'X') ? -10 : 10;

    if (checkWin('X')) return 1;
    if (checkWin('O')) return -1;

    if (depth == 0) return 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                if (player == 'X') {
                    board[i][j] = 'X';
                    score = minimax(depth - 1, !isMax, 'O');
                    if (score > bestScore) {
                        bestScore = score;
                    }
                } else {
                    board[i][j] = 'O';
                    score = minimax(depth - 1, !isMax, 'X');
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
                board[i][j] = ' ';
            }
        }
    }

    return (isMax) ? bestScore : -bestScore;
}

void aiMove() {
    int i, j, score, bestScore = -10;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                score = minimax(5, 0, 'X');
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    board[i][j] = 'O';
                }
            }
        }
    }
}

int main() {
    int i, j, turn = 0;
    while (1) {
        printBoard();
        if (turn % 2 == 0) {
            printf("Player X's move:\n");
            scanf("%d %d", &i, &j);
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                turn++;
            }
        } else {
            printf("Player O's move:\n");
            aiMove();
            turn++;
        }
        if (checkWin('X')) {
            printf("Player X wins!\n");
            break;
        }
        if (checkWin('O')) {
            printf("Player O wins!\n");
            break;
        }
        if (turn == 9) {
            printf("Draw!\n");
            break;
        }
    }
    printBoard();
    return 0;
}