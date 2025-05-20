//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);
void getRandomMove(char board[SIZE][SIZE], int *row, int *col);
void playGame();

int main() {
    srand(time(0)); // Seed for random moves
    playGame();
    return 0;
}

void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    int winner = 0;

    while (!winner && !isBoardFull(board)) {
        printBoard(board);
        playerMove(board);
        winner = checkWinner(board, PLAYER);
        if (winner || isBoardFull(board)) break;

        aiMove(board);
        winner = checkWinner(board, AI);
    }

    printBoard(board);
    if (winner == 1) {
        printf("Player wins!\n");
    } else if (winner == 2) {
        printf("AI wins!\n");
    } else {
        printf("It's a draw!\n");
    }
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
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return (player == PLAYER) ? 1 : 2;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return (player == PLAYER) ? 1 : 2;
    }
    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
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
        printf("Enter your move (row and column, 0-based): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    getRandomMove(board, &row, &col);
    board[row][col] = AI;
    printf("AI has made a move at (%d, %d).\n", row, col);
}

void getRandomMove(char board[SIZE][SIZE], int *row, int *col) {
    do {
        *row = rand() % SIZE;
        *col = rand() % SIZE;
    } while (board[*row][*col] != EMPTY);
}