//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '*';
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

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);

    int playerScore = 0;
    int computerScore = 0;

    while (playerScore < 5 || computerScore < 5) {
        printBoard(board);
        int row, col;
        printf("Enter your move (row col): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            if (board[row][col] == '*') {
                board[row][col] = 'X';
                playerScore++;
            } else if (board[row][col] == 'O') {
                printf("Invalid move!\n");
            }
        } else {
            printf("Invalid move!\n");
        }

        if (playerScore < 5) {
            int computerRow, computerCol;
            do {
                computerRow = rand() % ROWS;
                computerCol = rand() % COLS;
            } while (board[computerRow][computerCol]!= '*');
            board[computerRow][computerCol] = 'O';
            computerScore++;
        }

        if (playerScore == 5) {
            printf("You win!\n");
            break;
        } else if (computerScore == 5) {
            printf("You lose!\n");
            break;
        }
    }

    return 0;
}