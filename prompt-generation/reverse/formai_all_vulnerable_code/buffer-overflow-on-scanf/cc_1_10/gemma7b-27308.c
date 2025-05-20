//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Cell {
    char symbol;
    int row;
    int col;
} Cell;

Cell board[BOARD_SIZE][BOARD_SIZE] = {{
    {' ', 0, 0},
    {' ', 0, 0},
    {' ', 0, 0}
}};

void drawBoard() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c].symbol);
        }
        printf("\n");
    }
}

void makeMove(char symbol) {
    int moveValid = 0;
    while (!moveValid) {
        printf("Enter move (row, column): ");
        char move[2];
        scanf("%s", move);

        int row = move[0] - '0';
        int col = move[1] - '0';

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col].symbol == ' ') {
            board[row][col].symbol = symbol;
            moveValid = 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

int checkWin() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0].symbol == board[r][1].symbol && board[r][0].symbol == board[r][2].symbol) {
            return 1;
        }
    }

    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c].symbol == board[1][c].symbol && board[0][c].symbol == board[2][c].symbol) {
            return 1;
        }
    }

    if (board[0][0].symbol == board[1][1].symbol && board[0][0].symbol == board[2][2].symbol) {
        return 1;
    }

    return 0;
}

int main() {
    char currentSymbol = 'X';
    int gameWon = 0;

    drawBoard();

    while (!gameWon) {
        makeMove(currentSymbol);
        drawBoard();

        if (checkWin()) {
            gameWon = 1;
            printf("Winner: %c!\n", currentSymbol);
        } else if (board[0][0].symbol == board[1][1].symbol && board[0][0].symbol == board[2][2].symbol) {
            gameWon = 1;
            printf("Draw!\n");
        } else {
            currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}