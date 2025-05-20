//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4
#define COLS 4

int board[ROWS][COLS] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
int selectedRow, selectedCol, numMatches = 0;

void initBoard() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void drawBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

void checkMatch(int row, int col) {
    if ((row > 0 && board[row - 1][col] == board[row][col]) ||
        (col > 0 && board[row][col - 1] == board[row][col]) ||
        (row < ROWS - 1 && board[row + 1][col] == board[row][col]) ||
        (col < COLS - 1 && board[row][col + 1] == board[row][col])) {
        numMatches++;
    }
}

int main() {
    initBoard();
    int playerTurn = 1;
    while (numMatches < ROWS * COLS) {
        system("clear");
        drawBoard();
        printf("\nPlayer %d's turn\n", playerTurn);
        printf("Enter row and column: ");
        scanf("%d %d", &selectedRow, &selectedCol);
        selectedRow--;
        selectedCol--;
        if (board[selectedRow][selectedCol] == 0) {
            board[selectedRow][selectedCol] = playerTurn;
            checkMatch(selectedRow, selectedCol);
            playerTurn =!playerTurn;
        } else {
            printf("Invalid move\n");
        }
    }
    system("clear");
    drawBoard();
    printf("\nGame over! Player %d wins with %d matches!\n", playerTurn, numMatches);
    return 0;
}