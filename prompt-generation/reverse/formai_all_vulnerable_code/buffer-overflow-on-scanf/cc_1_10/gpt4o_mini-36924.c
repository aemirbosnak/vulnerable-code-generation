//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player = 'X', opponent = 'O';

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int isWinner(char ch) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) || 
            (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch))
            return 1;
    }
    if ((board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) || 
        (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch))
        return 1;
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove() {
    // Check for winning move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = opponent;
                if (isWinner(opponent)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    
    // Check if blocking player win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (isWinner(player)) {
                    board[i][j] = opponent;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    
    // Take the first available position
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') {
                board[i][j] = opponent;
                return;
            }
}

int main() {
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    printBoard();

    while (1) {
        playerMove();
        printBoard();
        if (isWinner(player)) {
            printf("You win!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        aiMove();
        printBoard();
        if (isWinner(opponent)) {
            printf("AI wins!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}