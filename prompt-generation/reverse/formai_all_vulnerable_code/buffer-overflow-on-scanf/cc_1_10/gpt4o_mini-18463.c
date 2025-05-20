//GPT-4o-mini DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
bool isMoveValid(char board[SIZE][SIZE], int row, int col);
bool checkWin(char board[SIZE][SIZE], char player);
bool isBoardFull(char board[SIZE][SIZE]);
void playGame();

int main() {
    playGame();
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("  0 1 2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  -----\n");
        }
    }
}

bool isMoveValid(char board[SIZE][SIZE], int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        displayBoard(board);
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isMoveValid(board, row, col)) {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            } else if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}