//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X';
char ai = 'O';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1;
        }
    }
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || 
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }
    return 0;
}

int checkDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void playerMove() {
    int x, y;
    while (1) {
        printf("Enter your move (row and column 0-2): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == ' ') {
            board[x][y] = player;
            break;
        }
        printf("Invalid move! Try again.\n");
    }
}

void aiMove() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                if (checkWin(ai)) return;
                board[i][j] = ' '; // Undo if not winning
            }
        }
    }

    // Block player's winning move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (checkWin(player)) {
                    board[i][j] = ai; // Block the player
                    return;
                }
                board[i][j] = ' '; // Undo if not a winning block
            }
        }
    }

    // Place in the first available space
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                return;
            }
        }
    }
}

int main() {
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    displayBoard();

    while (1) {
        playerMove();
        displayBoard();
        if (checkWin(player)) {
            printf("You win!\n");
            break;
        }
        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }

        aiMove();
        displayBoard();
        if (checkWin(ai)) {
            printf("AI wins!\n");
            break;
        }
        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}