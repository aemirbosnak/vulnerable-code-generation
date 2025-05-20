//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffleBoard(char board[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int randIndex = rand() % (ROWS * COLS);
            board[i][j] = board[randIndex / COLS][randIndex % COLS];
            board[randIndex / COLS][randIndex % COLS] = '-';
        }
    }
}

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    shuffleBoard(board);
    printBoard(board);

    int playerTurns = 0;
    int computerTurns = 0;

    while (1) {
        int row, col;
        printf("Player %d's turn. Enter a coordinate: ", playerTurns + 1);
        scanf("%d %d", &row, &col);
        if (board[row][col] == '-') {
            board[row][col] = 'X';
            playerTurns++;
        } else {
            printf("Invalid move.\n");
        }

        if (playerTurns == 8) {
            break;
        }

        computerTurns++;
        int computerRow, computerCol;
        while (1) {
            computerRow = rand() % ROWS;
            computerCol = rand() % COLS;
            if (board[computerRow][computerCol] == '-') {
                board[computerRow][computerCol] = 'O';
                break;
            }
        }
    }

    printBoard(board);

    if (computerTurns == 8) {
        printf("Tie game.\n");
    } else if (playerTurns == 8) {
        printf("Player wins!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}