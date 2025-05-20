//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
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

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

void playerMove() {
    int row, col;
    while (true) {
        printf("Dearest player, enter your move (row and column: 0, 1, or 2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = playerSymbol;
            break;
        } else {
            printf("Oh no! That place is already taken or out of bounds. Please try again.\n");
        }
    }
}

void aiMove() {
    // AI (minimax) strategy for demonstration
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                board[i][j] = aiSymbol;
                if (checkWin(aiSymbol)) return;
                board[i][j] = ' ';
            }

    // Block player
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                board[i][j] = playerSymbol;
                if (checkWin(playerSymbol)) {
                    board[i][j] = aiSymbol;
                    return;
                }
                board[i][j] = ' ';
            }

    // Choose the first available spot
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                board[i][j] = aiSymbol;
                return;
            }
}

int main() {
    printf("Welcome to the magical realm of Tic Tac Toe, where you and I shall duel!\n");
    printf("Choose your symbol (X or O): ");
    scanf(" %c", &playerSymbol);
    aiSymbol = (playerSymbol == 'X') ? 'O' : 'X';

    initializeBoard();
    printBoard();

    while (true) {
        playerMove();
        printBoard();
        if (checkWin(playerSymbol)) {
            printf("Congratulations! You've won my heart!\n");
            break;
        }
        if (isBoardFull()) {
            printf("Oh dear, it's a romantic draw!\n");
            break;
        }
        
        printf("Now, my dear AI shall take its turn...\n");
        aiMove();
        printBoard();
        
        if (checkWin(aiSymbol)) {
            printf("Alas, the AI has claimed victory, but my heart belongs to you!\n");
            break;
        }
        if (isBoardFull()) {
            printf("Oh dear, it's a romantic draw!\n");
            break;
        }
    }

    printf("Thank you for this mesmerizing game of love and strategy! Farewell!\n");
    return 0;
}