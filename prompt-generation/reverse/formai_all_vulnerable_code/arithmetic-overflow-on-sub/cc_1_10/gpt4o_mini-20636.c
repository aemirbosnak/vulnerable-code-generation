//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X', ai = 'O';

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

int checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return 1;
    }
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column numbers from 1 to 3): ");
        scanf("%d %d", &row, &col);
        row--; col--; // Convert to 0-based index
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("This move is not valid. Try again.\n");
        }
    }
}

void aiMove() {
    // Simple AI: Random move
    int row, col;
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == ' ') {
            board[row][col] = ai;
            break;
        }
    }
}

int main() {
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    printBoard();
    
    while (1) {
        playerMove();
        printBoard();
        if (checkWin(player)) {
            printf("You win!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
        
        aiMove();
        printBoard();
        if (checkWin(ai)) {
            printf("AI wins!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
    }
    
    printf("Game over. Thanks for playing!\n");
    return 0;
}