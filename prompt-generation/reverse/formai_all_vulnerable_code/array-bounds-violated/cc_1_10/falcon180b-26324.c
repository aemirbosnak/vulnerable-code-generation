//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 'X';
        }
    }
}

void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int player = 0;
    int moves = 0;

    while (moves < 8) {
        printBoard(board);
        int row, col;
        if (player % 2 == 0) {
            row = rand() % ROWS;
            col = rand() % COLS;
            board[row][col] = 'O';
            printf("Player 1's turn. Enter your choice (row, col): ");
            scanf("%d %d", &row, &col);
            if (row == rand() % ROWS && col == rand() % COLS) {
                printf("Congratulations! You won!\n");
                break;
            }
        } else {
            printf("Player 2's turn. Enter your choice (row, col): ");
            scanf("%d %d", &row, &col);
            if (board[row][col] == 'O') {
                printf("You found it!\n");
                board[row][col] = 'X';
                moves++;
            } else {
                printf("Try again.\n");
            }
        }
        player++;
    }

    return 0;
}