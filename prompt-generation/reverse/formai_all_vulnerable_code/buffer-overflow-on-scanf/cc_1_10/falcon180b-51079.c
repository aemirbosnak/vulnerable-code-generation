//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4

void initBoard(char board[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    char board[NUM_ROWS][NUM_COLS];
    initBoard(board);
    int numMatches = 0;
    int numTurns = 0;
    while (numMatches < NUM_ROWS * NUM_COLS / 2) {
        int row, col;
        row = rand() % NUM_ROWS;
        col = rand() % NUM_COLS;
        if (board[row][col] == '*') {
            board[row][col] = 'X';
            numMatches++;
        } else if (board[row][col] == 'X') {
            board[row][col] = '*';
        }
        numTurns++;
        if (numTurns % 2 == 0) {
            printf("Your turn!\n");
            char input[3];
            scanf("%s", input);
            int rowInput, colInput;
            rowInput = input[0] - '0';
            colInput = input[1] - '0';
            if (rowInput >= 0 && rowInput < NUM_ROWS && colInput >= 0 && colInput < NUM_COLS && board[rowInput][colInput] == '*') {
                board[rowInput][colInput] = 'X';
                numMatches++;
            } else {
                printf("Invalid move!\n");
            }
        } else {
            printf("Falcon's turn...\n");
            int row, col;
            do {
                row = rand() % NUM_ROWS;
                col = rand() % NUM_COLS;
            } while (board[row][col]!= '*');
            board[row][col] = 'X';
            numMatches++;
        }
        printBoard(board);
    }
    printf("Congratulations! You win!\n");
    return 0;
}