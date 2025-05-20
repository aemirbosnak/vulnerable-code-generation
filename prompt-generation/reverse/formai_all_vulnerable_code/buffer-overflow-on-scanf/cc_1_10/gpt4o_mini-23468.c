//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
}

bool isWin(char symbol) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || 
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void playerTurn() {
    int row, col;
    while (true) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiTurn() {
    int bestMoveValue = -1000;
    int moveRow = -1, moveCol = -1;

    // Check all available moves and calculate the score based on the AI's chances
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                int moveValue = evaluateMove();
                board[i][j] = ' ';

                if (moveValue > bestMoveValue) {
                    moveRow = i;
                    moveCol = j;
                    bestMoveValue = moveValue;
                }
            }
        }
    }

    board[moveRow][moveCol] = ai;
}

int evaluateMove() {
    if (isWin(ai)) return 10;
    if (isWin(player)) return -10;
    return 0;
}

int main() {
    srand(time(NULL));
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");

    while (true) {
        printBoard();
        playerTurn();
        if (isWin(player)) {
            printBoard();
            printf("You win!\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        aiTurn();
        if (isWin(ai)) {
            printBoard();
            printf("AI wins!\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}