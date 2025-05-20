//FormAI DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void initializeGame(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        printf("\t\t\t");
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isGameOver(char board[ROWS][COLS], char player) {
    // Check diagonal
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    // Check rows and cols
    for(int i = 0; i < ROWS; i++) {
        int rowCounter = 0;
        int colCounter = 0;

        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == player) {
                rowCounter++;
            }
            if(board[j][i] == player) {
                colCounter++;
            }
        }

        if(rowCounter == 3) {
            return 1;
        }
        if(colCounter == 3) {
            return 1;
        }
    }

    return 0;
}

int isBoardFull(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }

    return 1;
}

void playGame(char board[ROWS][COLS]) {
    char playerOne = 'X';
    char playerTwo = 'O';
    char currentPlayer = playerOne;

    while(!isGameOver(board, playerOne) && !isGameOver(board, playerTwo) && !isBoardFull(board)) {
        printf("\nPlayer %c's turn: \n", currentPlayer);
        int row, col;

        do {
            printf("Enter row number (1-3): ");
            scanf("%d", &row);
            row--;

            printf("Enter column number (1-3): ");
            scanf("%d", &col);
            col--;
        } while(board[row][col] != '-');

        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == playerOne) ? playerTwo : playerOne;

        printBoard(board);
    }

    if(isGameOver(board, playerOne)) {
        printf("\nPlayer %c wins!!\n", playerOne);
    } else if(isGameOver(board, playerTwo)) {
        printf("\nPlayer %c wins!!\n", playerTwo);
    } else {
        printf("\nGame is a tie.\n");
    }
}

int main() {
    char board[ROWS][COLS];

    printf("\n\nWelcome to Tic Tac Toe!\n\n");

    initializeGame(board);

    printBoard(board);

    playGame(board);

    return 0;
}