//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE], char player);
int checkDraw(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);
void playGame();

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    playGame();
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
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

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column; 0-2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    srand(time(NULL));
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            printf("AI places 'O' at (%d, %d)\n", row, col);
            board[row][col] = AI;
            break;
        }
    }
}

void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);

    while (1) {
        playerMove(board);
        printBoard(board);
        if (checkWin(board, PLAYER)) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (checkDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
        
        aiMove(board);
        printBoard(board);
        if (checkWin(board, AI)) {
            printf("AI wins! Better luck next time.\n");
            break;
        }
        if (checkDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
    }
}