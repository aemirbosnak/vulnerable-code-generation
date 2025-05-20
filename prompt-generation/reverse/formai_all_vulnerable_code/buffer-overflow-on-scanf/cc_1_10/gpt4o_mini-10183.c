//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 'X'
#define AI 'O'
#define EMPTY ' '

void printBoard(char board[3][3]);
int checkWin(char board[3][3], char player);
int isFull(char board[3][3]);
void playerMove(char board[3][3]);
void aiMove(char board[3][3]);
void initializeBoard(char board[3][3]);

int main() {
    char board[3][3];
    char currentPlayer = PLAYER;
    int gameOver = 0;

    initializeBoard(board);
    printf("Welcome to Tic Tac Toe!\n");

    while (!gameOver) {
        printBoard(board);

        if (currentPlayer == PLAYER) {
            playerMove(board);
        } else {
            aiMove(board);
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            if (currentPlayer == PLAYER) {
                printf("Congratulations! You win!\n");
            } else {
                printf("AI wins! Better luck next time.\n");
            }
            gameOver = 1;
        } else if (isFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            currentPlayer = (currentPlayer == PLAYER) ? AI : PLAYER;
        }
    }

    return 0;
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

int checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
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

int isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char board[3][3]) {
    int row, col;

    do {
        printf("Enter your move (row and column: 0, 1, or 2): ");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY);

    board[row][col] = PLAYER;
}

void aiMove(char board[3][3]) {
    srand(time(NULL));
    int row, col;

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != EMPTY);

    board[row][col] = AI;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}