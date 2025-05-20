//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int playerScore = 0;
    int computerScore = 0;

    while (playerScore < 5 && computerScore < 5) {
        printf("Player's turn\n");
        printf("Enter row and column: ");
        int row, col;
        scanf("%d %d", &row, &col);

        if (board[row - 1][col - 1] == '-') {
            board[row - 1][col - 1] = 'X';
            playerScore++;
        } else {
            printf("Invalid move\n");
        }

        printBoard(board);

        if (playerScore >= 5) {
            printf("Player wins!\n");
            break;
        }

        printf("Computer's turn\n");
        int computerRow, computerCol;
        do {
            computerRow = getRandomInt(1, ROWS);
            computerCol = getRandomInt(1, COLS);
        } while (board[computerRow - 1][computerCol - 1]!= '-');

        board[computerRow - 1][computerCol - 1] = 'O';
        computerScore++;

        printBoard(board);

        if (computerScore >= 5) {
            printf("Computer wins!\n");
            break;
        }
    }

    return 0;
}