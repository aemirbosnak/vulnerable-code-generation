//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

char board[MAX_SIZE][MAX_SIZE];
int boardSize;

// Function prototypes
void initializeBoard();
void printBoard();
int checkWin(char player);
void playerMove(char player);
void aiMove(char aiPlayer);
int isBoardFull();
void displayInstructions();

int main() {
    char playerSymbol = 'X';
    char aiSymbol = 'O';

    displayInstructions();

    printf("Enter the size of the Tic Tac Toe board (3-10): ");
    scanf("%d", &boardSize);
    if (boardSize < 3 || boardSize > 10) {
        printf("Invalid board size! Setting to default size 3.\n");
        boardSize = 3;
    }

    initializeBoard();

    while (1) {
        printBoard();
        playerMove(playerSymbol);
        if (checkWin(playerSymbol)) {
            printBoard();
            printf("Player %c wins!\n", playerSymbol);
            break;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        aiMove(aiSymbol);
        if (checkWin(aiSymbol)) {
            printBoard();
            printf("Player %c wins!\n", aiSymbol);
            break;
        }

        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            printf(" %c ", board[i][j]);
            if (j < boardSize - 1) printf("|");
        }
        printf("\n");
        if (i < boardSize - 1) {
            for (int k = 0; k < boardSize; ++k) {
                printf("---");
                if (k < boardSize - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int checkWin(char player) {
    // Check rows
    for (int i = 0; i < boardSize; ++i) {
        int win = 1;
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] != player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }

    // Check columns
    for (int j = 0; j < boardSize; ++j) {
        int win = 1;
        for (int i = 0; i < boardSize; ++i) {
            if (board[i][j] != player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }

    // Check diagonals
    int win = 1;
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][i] != player) {
            win = 0;
            break;
        }
    }
    if (win) return 1;

    win = 1;
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][boardSize - 1 - i] != player) {
            win = 0;
            break;
        }
    }
    return win;
}

void playerMove(char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove(char aiPlayer) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = aiPlayer;
                if (checkWin(aiPlayer)) {
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    
    // Random move if no winning move found
    while (1) {
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        if (board[row][col] == ' ') {
            board[row][col] = aiPlayer;
            break;
        }
    }
}

int isBoardFull() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void displayInstructions() {
    printf("Welcome to the Tic Tac Toe Game!\n");
    printf("You can configure the size of the board (3-10)\n");
    printf("Players take turns to place their marks on the board.\n");
    printf("The first player to align 3 marks in a row, column or diagonal wins!\n");
    printf("Enjoy the game!\n\n");
}