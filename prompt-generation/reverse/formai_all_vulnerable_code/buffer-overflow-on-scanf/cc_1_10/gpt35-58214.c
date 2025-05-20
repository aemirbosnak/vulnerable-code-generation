//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the board
void initializeBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
}

// Function to display the board
void displayBoard(char board[][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a position is valid
int isValidMove(char board[][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '_') {
        return 1;
    }
    return 0;
}

// Function to check if there is a winner
int checkWinner(char board[][3], char playerSymbol) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol) {
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) {
        return 1;
    }
    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol) {
        return 1;
    }
    return 0;
}

// Function to generate a random position
void generateRandomPosition(int *row, int *col) {
    srand(time(NULL));
    *row = rand() % 3;
    *col = rand() % 3;
}

// Function to get user input
void getUserInput(int *row, int *col) {
    printf("\nEnter row and column to make move : ");
    scanf("%d %d", row, col);
}

int main() {
    char board[3][3];
    char player1Symbol = 'X';
    char player2Symbol = 'O';
    int currentPlayer = 1; // 1 if player1's turn, 2 if player2's turn
    
    initializeBoard(board);
    
    printf("\nWelcome to the Table Game!\nPlayer 1: X\nPlayer 2: O\n\n");
    while(1) {
        displayBoard(board);
        if (currentPlayer == 1) {
            printf("\nplayer 1 turn\n");
            int row, col;
            getUserInput(&row, &col);
            if (isValidMove(board, row, col)) {
                board[row][col] = player1Symbol;
                if (checkWinner(board, player1Symbol)) {
                    displayBoard(board);
                    printf("\nPlayer 1 won!\n");
                    break;
                }
                currentPlayer = 2;
            } else {
                printf("\nInvalid move! Try again.\n");
            }
        } else {
            printf("\nplayer 2 turn\n");
            int row, col;
            generateRandomPosition(&row, &col);
            if (isValidMove(board, row, col)) {
                board[row][col] = player2Symbol;
                if (checkWinner(board, player2Symbol)) {
                    displayBoard(board);
                    printf("\nPlayer 2 won!\n");
                    break;
                }
                currentPlayer = 1;
            }
        }
    }
    
    return 0;
}