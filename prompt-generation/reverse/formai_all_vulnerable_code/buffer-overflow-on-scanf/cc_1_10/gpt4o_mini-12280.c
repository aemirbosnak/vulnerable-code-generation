//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X'; // Player's symbol
char ai = 'O';     // AI's symbol

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
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

bool checkWin(char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }
    return (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || 
           (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol);
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void playerMove() {
    int row, col;
    printf("Your move (row and column from 0 to 2): ");
    scanf("%d %d", &row, &col);
    while (!isValidMove(row, col)) {
        printf("Invalid move, try again (row and column from 0 to 2): ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = player;
}

void aiMove() {
    int row, col;
    // Simple AI strategy: Check for winning move
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (isValidMove(row, col)) {
                board[row][col] = ai; // Make the move
                if (checkWin(ai)) {
                    return; // Win
                }
                board[row][col] = ' '; // Undo move
            }
        }
    }
    
    // Block player's winning move
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (isValidMove(row, col)) {
                board[row][col] = player; // Temporarily make the move
                if (checkWin(player)) {
                    board[row][col] = ai; // Block the win
                    return;
                }
                board[row][col] = ' '; // Undo move
            }
        }
    }

    // Random move if no other moves were found
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isValidMove(row, col));
    board[row][col] = ai;
}

int main() {
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    printBoard();
    
    while (true) {
        playerMove();
        printBoard();
        if (checkWin(player)) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        aiMove();
        printBoard();
        if (checkWin(ai)) {
            printf("AI wins! Better luck next time.\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}