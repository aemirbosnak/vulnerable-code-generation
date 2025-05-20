//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer;

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
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
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

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playerMove() {
    int row, col;
    printf("Player %c, enter your move (row and column): ", currentPlayer);
    while (true) {
        scanf("%d %d", &row, &col);
        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
            break;
        } else {
            printf("Whoa! That move is not valid. Try again: ");
        }
    }
}

void aiMove() {
    int row, col;
    printf("Hmm... AI %c is thinking... ", currentPlayer);
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (isMoveValid(row, col)) {
                board[row][col] = currentPlayer;
                if (checkWin(currentPlayer)) {
                    printf("Gotcha! AI %c wins!\n", currentPlayer);
                    return;
                }
                board[row][col] = ' '; // Undo the move
            }
        }
    }
    // If no winning move, pick a random valid move
    while (true) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
            printf("AI %c selects: (%d, %d)!\n", currentPlayer, row, col);
            return;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is 'X' and AI is 'O'.\n");
    currentPlayer = 'X';
    initializeBoard();

    while (true) {
        printBoard();

        if (currentPlayer == 'X') {
            playerMove();
        } else {
            aiMove();
        }

        if (checkWin(currentPlayer)) {
            printBoard();
            printf("Congratulations! Player %c has won!\n", currentPlayer);
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw! How surprising!\n");
            break;
        }

        switchPlayer();
    }
    
    return 0;
}