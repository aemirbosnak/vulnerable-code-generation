//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char playerSymbol, aiSymbol;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

bool checkWin(char symbol) {
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

void playerMove() {
    int row, col;
    while (true) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = playerSymbol;
            break;
        } else {
            printf("This move is not valid. Try again.\n");
        }
    }
}

int evaluateBoard() {
    if (checkWin(aiSymbol))
        return 10;
    if (checkWin(playerSymbol))
        return -10;
    return 0;
}

int minimax(bool isMax) {
    int score = evaluateBoard();
    if (score == 10 || score == -10) {
        return score;
    }
    if (isBoardFull()) {
        return 0;
    }
    
    if (isMax) {
        int best = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = aiSymbol;
                    best = (best > minimax(false)) ? best : minimax(false);
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = playerSymbol;
                    best = (best < minimax(true)) ? best : minimax(true);
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void aiMove() {
    int bestValue = -1000;
    int moveRow = -1, moveCol = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = aiSymbol;
                int moveValue = minimax(false);
                board[i][j] = ' ';
                if (moveValue > bestValue) {
                    moveRow = i;
                    moveCol = j;
                    bestValue = moveValue;
                }
            }
        }
    }
    
    board[moveRow][moveCol] = aiSymbol;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    
    printf("Choose your symbol (X or O): ");
    scanf(" %c", &playerSymbol);
    aiSymbol = (playerSymbol == 'X') ? 'O' : 'X';

    initializeBoard();
    printBoard();
    
    while (true) {
        playerMove();
        printBoard();
        if (checkWin(playerSymbol)) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (isBoardFull()) {
            printf("The game is a draw!\n");
            break;
        }
        
        aiMove();
        printBoard();
        if (checkWin(aiSymbol)) {
            printf("AI wins! Better luck next time!\n");
            break;
        }
        if (isBoardFull()) {
            printf("The game is a draw!\n");
            break;
        }
    }
    
    return 0;
}