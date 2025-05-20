//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[3][3];
int moves = 0;

void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", i);
        for (int j = 0; j < 3; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isDraw() {
    return moves == 9;
}

void playerTurn() {
    int row, col;
    printf("Your turn! Enter row and column (0-2): ");
    scanf("%d %d", &row, &col);
    while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
        printf("Invalid move! Try again: ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = PLAYER;
    moves++;
}

void aiTurn() {
    int row, col;
    // Simple AI strategy: prioritize corners and center, then random
    int corners[4][2] = { {0, 0}, {0, 2}, {2, 0}, {2, 2} };
    int center[2][2] = { {1, 1} };
    for (int i = 0; i < 4; ++i) {
        row = corners[i][0];
        col = corners[i][1];
        if (board[row][col] == EMPTY) {
            board[row][col] = AI;
            moves++;
            return;
        }
    }
    if (board[1][1] == EMPTY) {
        board[1][1] = AI;
        moves++;
        return;
    }
    // Random move if no other option
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != EMPTY);
    board[row][col] = AI;
    moves++;
}

void playGame() {
    while (1) {
        printBoard();
        if (checkWin(PLAYER)) {
            printf("Congratulations, you win!\n");
            break;
        }
        if (isDraw()) {
            printf("It's a draw!\n");
            break;
        }
        playerTurn();
        if (checkWin(PLAYER)) {
            printBoard();
            printf("Congratulations, you win!\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        aiTurn();
        if (checkWin(AI)) {
            printBoard();
            printf("AI wins! Better luck next time.\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    initializeBoard();
    playGame();
    return 0;
}