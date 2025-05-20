//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function declarations
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    
    printf("Welcome to Tic Tac Toe! You are 'X' and the AI is 'O'.\n");
    while (1) {
        printBoard(board);
        playerMove(board);

        if (checkWin(board)) {
            printBoard(board);
            printf("Congratulations! You win!\n");
            break;
        }
        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        aiMove(board);
        
        if (checkWin(board)) {
            printBoard(board);
            printf("Oh no! The AI wins!\n");
            break;
        }
        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }
    }
    
    printf("Game Over! Thank you for playing!\n");
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = 'X';
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    // Simple AI that just takes the first available position
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Found an empty spot
            }
        }
    }
    return 1; // Board is full
}