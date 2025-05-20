//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define BLOCKER 'B'
#define DOUBLE 'D'

char board[SIZE][SIZE];
char currentPlayer;
int movesCount = 0;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void displayBoard() {
    printf("\nCurrent Board:\n");
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

int isWinner(char player) {
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

int checkDraw() {
    return movesCount >= SIZE * SIZE;
}

void makeMove(int row, int col) {
    if (board[row][col] == EMPTY) {
        board[row][col] = currentPlayer;
        movesCount++;
    }
}

void addSpecialCell(int row, int col, char type) {
    board[row][col] = type;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void playGame() {
    int row, col;
    char specialType;

    initializeBoard();
    currentPlayer = PLAYER_X;

    while (1) {
        displayBoard();
        printf("Player %c, enter your move (row and column) or a special cell (e.g., D 1 2): ", currentPlayer);
        if (scanf(" %c", &specialType) == 1 && (specialType == DOUBLE || specialType == BLOCKER)) {
            scanf("%d %d", &row, &col);
            addSpecialCell(row, col, specialType);
            movesCount++;
        } else {
            scanf("%d %d", &row, &col);
            makeMove(row, col);
        }

        if (isWinner(currentPlayer)) {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe with a Twist!\n");
    playGame();
    return 0;
}