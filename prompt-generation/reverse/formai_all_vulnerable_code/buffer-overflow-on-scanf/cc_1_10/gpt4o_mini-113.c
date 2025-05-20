//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

int checkWinner(char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1;
        }
    }
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }
    return 0;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", playerSymbol);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = playerSymbol;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove() {
    int row, col;
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == ' ') {
            board[row][col] = aiSymbol;
            printf("AI %c has placed on (%d, %d)\n", aiSymbol, row, col);
            break;
        }
    }
}

void gameLoop() {
    while (1) {
        printBoard();
        if (checkWinner(playerSymbol)) {
            printf("Player %c wins!\n", playerSymbol);
            break;
        }
        if (isBoardFull()) {
            printf("The game is a draw!\n");
            break;
        }
        playerMove();
        if (checkWinner(playerSymbol)) {
            printBoard();
            printf("Player %c wins!\n", playerSymbol);
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("The game is a draw!\n");
            break;
        }
        aiMove();
        if (checkWinner(aiSymbol)) {
            printBoard();
            printf("AI %c wins!\n", aiSymbol);
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("The game is a draw!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your symbol (X/O): ");
    scanf(" %c", &playerSymbol);
    aiSymbol = (playerSymbol == 'X') ? 'O' : 'X';
    initializeBoard();
    gameLoop();
    return 0;
}