//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

char board[3][3] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
};

void printBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int checkWin(char player) {
    for(int i = 0; i < 3; i++) {
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

int isFull() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return 0;
    return 1;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column: 0-2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == EMPTY) {
            board[row][col] = PLAYER_X;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                if (checkWin(PLAYER_O)) {
                    return;
                } else {
                    board[i][j] = EMPTY;
                }
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_X;
                if (checkWin(PLAYER_X)) {
                    board[i][j] = PLAYER_O;
                    return;
                } else {
                    board[i][j] = EMPTY;
                }
            }
        }
    }

    while (1) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (board[row][col] == EMPTY) {
            board[row][col] = PLAYER_O;
            break;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are 'X' and the AI is 'O'.\n");
    
    while (1) {
        printBoard();
        playerMove();
        if (checkWin(PLAYER_X)) {
            printBoard();
            printf("Congratulations! You win!\n");
            break;
        }
        if (isFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        aiMove();
        if (checkWin(PLAYER_O)) {
            printBoard();
            printf("AI wins! Better luck next time.\n");
            break;
        }
        if (isFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}