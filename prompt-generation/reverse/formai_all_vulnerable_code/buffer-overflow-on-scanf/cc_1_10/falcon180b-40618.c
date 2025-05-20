//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: relaxed
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
    int currentPlayer = 1;
    while (playerScore < 8 || computerScore < 8) {
        printBoard(board);
        printf("Player %d's turn. Enter row and column: ", currentPlayer);
        scanf("%d %d", &board[currentPlayer - 1][0], &board[0][currentPlayer - 1]);
        if (board[currentPlayer - 1][0] == '-') {
            board[currentPlayer - 1][0] = 'X';
            playerScore++;
        } else {
            board[currentPlayer - 1][0] = '-';
        }
        if (board[0][currentPlayer - 1] == '-') {
            board[0][currentPlayer - 1] = 'O';
            computerScore++;
        } else {
            board[0][currentPlayer - 1] = '-';
        }
        if (playerScore == 8) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        } else if (computerScore == 8) {
            printf("Computer wins!\n");
            break;
        } else {
            currentPlayer = (currentPlayer == 1)? 2 : 1;
        }
    }
    return 0;
}