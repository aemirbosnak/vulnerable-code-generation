//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>

#define EMPTY ' '
#define PLAYER 'X'
#define COMPUTER 'O'

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
}

void printBoard() {
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

int checkWin(char player) {
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

int isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY) return 0;
    return 1;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column: 0-2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

void computerMove() {
    // Simple AI that selects the first available spot
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                return;
            }
        }
    }
}

void playGame() {
    printf("Welcome to Tic Tac Toe! May the best spirit win.\n");
    while (1) {
        printBoard();
        if (checkWin(PLAYER)) {
            printBoard();
            printf("Congratulations! You have won!\n");
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("It's a tie! A serene end to our game.\n");
            break;
        }
        
        playerMove();

        if (checkWin(PLAYER)) {
            printBoard();
            printf("Congratulations! You have won!\n");
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("It's a tie! A serene end to our game.\n");
            break;
        }

        computerMove();
        
        if (checkWin(COMPUTER)) {
            printBoard();
            printf("Alas! The computer has triumphed. Better luck next time.\n");
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("It's a tie! A serene end to our game.\n");
            break;
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}