//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define EMPTY '-'
#define PLAYER1 'X'
#define PLAYER2 'O'

void initializeBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
bool placeMark(char board[ROWS][COLS], int row, int col, char player);
bool checkWinner(char board[ROWS][COLS], char player);
bool isBoardFull(char board[ROWS][COLS]);
void takeTurn(char board[ROWS][COLS], char player);
void gameOver(char winner);

int main() {
    char board[ROWS][COLS];
    char winner = EMPTY;
    char currentPlayer = PLAYER1;

    initializeBoard(board);
    
    printf("Welcome to the 5x5 Tic-Tac-Toe Table Game!\n");
    
    while (winner == EMPTY && !isBoardFull(board)) {
        printBoard(board);
        takeTurn(board, currentPlayer);
        
        if (checkWinner(board, currentPlayer)) {
            winner = currentPlayer;
        }
        
        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1; // Switch player
    }

    printBoard(board);
    gameOver(winner);
    
    return 0;
}

void initializeBoard(char board[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = EMPTY;
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    printf("\nCurrent Board:\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf(" %c ", board[r][c]);
            if (c < COLS - 1) printf("|");
        }
        printf("\n");
        if (r < ROWS - 1) {
            for (int c = 0; c < COLS; c++) {
                printf("---");
                if (c < COLS - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

bool placeMark(char board[ROWS][COLS], int row, int col, char player) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != EMPTY) {
        printf("Invalid move! Try again.\n");
        return false;
    }
    board[row][col] = player;
    return true;
}

bool checkWinner(char board[ROWS][COLS], char player) {
    // Check rows and columns for a winner
    for (int i = 0; i < ROWS; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player && board[i][4] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player && board[4][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player) ||
        (board[0][4] == player && board[1][3] == player && board[2][2] == player && board[3][1] == player && board[4][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(char board[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void takeTurn(char board[ROWS][COLS], char player) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        validMove = placeMark(board, row, col, player);
    }
}

void gameOver(char winner) {
    if (winner == PLAYER1) {
        printf("Congratulations! Player 1 (X) wins!\n");
    } else if (winner == PLAYER2) {
        printf("Congratulations! Player 2 (O) wins!\n");
    } else {
        printf("The game is a draw!\n");
    }
}