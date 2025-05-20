//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void ticTacToe(char board[SIZE][SIZE], char currentPlayer) {
    int x, y;
    
    printBoard(board);
    
    if (checkWin(board, 'X')) {
        printf("Player X wins!\n");
        return;
    } else if (checkWin(board, 'O')) {
        printf("Player O wins!\n");
        return;
    } else if (isDraw(board)) {
        printf("It's a draw!\n");
        return;
    }

    printf("Player '%c', enter your move (row and column): ", currentPlayer);
    scanf("%d %d", &x, &y);
    
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != ' ') {
        printf("Invalid move! Try again.\n");
        ticTacToe(board, currentPlayer);  // Recursive call for retry
        return;
    }

    board[x][y] = currentPlayer; // Place the move
    ticTacToe(board, (currentPlayer == 'X') ? 'O' : 'X'); // Switch player
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    printf("Welcome to Tic-Tac-Toe!\n");
    ticTacToe(board, 'X'); // X starts the game

    return 0;
}