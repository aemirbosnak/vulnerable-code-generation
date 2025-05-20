//Falcon-180B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to initialize the game board
void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print the game board
void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int checkGameOver(char board[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Function to get user input for a move
int getMove(char board[ROWS][COLS]) {
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
        return row * COLS + col;
    } else {
        printf("Invalid move.\n");
        return -1;
    }
}

// Function to make a move
void makeMove(char board[ROWS][COLS], int move) {
    int row = move / COLS;
    int col = move % COLS;
    if (row == 0) {
        board[row][col] = 'X';
    } else if (row == 1) {
        board[row][col] = 'O';
    } else {
        board[row][col] = 'X';
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);

    int currentPlayer = 0;
    while (1) {
        printBoard(board);
        printf("Player %d's turn.\n", currentPlayer + 1);
        int move = getMove(board);
        if (move == -1) {
            continue;
        }

        makeMove(board, move);

        if (checkGameOver(board)) {
            printf("Game over! Player %d wins!\n", currentPlayer + 1);
            break;
        }

        currentPlayer =!currentPlayer;
    }

    return 0;
}