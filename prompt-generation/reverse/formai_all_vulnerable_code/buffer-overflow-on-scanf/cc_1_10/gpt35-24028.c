//FormAI DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 100

void printBoard(int board[ROWS][COLS], int hidden[ROWS][COLS]) {
    printf("\nCurrent Board:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (hidden[i][j]) {
                printf("# ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int isValidMove(int x, int y, int lastX, int lastY) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return 0;
    }

    if (x == lastX && y == lastY) {
        return 0;
    }

    return 1;
}

int makeMove(int x, int y, int board[ROWS][COLS], int hidden[ROWS][COLS], int lastX, int lastY) {
    if (!isValidMove(x, y, lastX, lastY)) {
        return 0;
    }

    hidden[x][y] = 0;
    printBoard(board, hidden);

    if (board[x][y] == board[lastX][lastY]) {
        return 1;
    } else {
        hidden[x][y] = 1;
        hidden[lastX][lastY] = 1;
        return 0;
    }
}

int main() {
    int board[ROWS][COLS] = {{0}};
    int hidden[ROWS][COLS] = {{1}};
    int lastX = -1, lastY = -1;
    int moves = 0;

    srand(time(NULL));

    // Populate board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 8 + 1; // Numbers 1-8 for easier matching
        }
    }

    printBoard(board, hidden);

    while (1) {
        int x, y;

        printf("Enter row and column (e.g. 2 3): ");
        scanf("%d %d", &x, &y);

        if (makeMove(x, y, board, hidden, lastX, lastY)) {
            printf("Match found!\n");
        }

        lastX = x;
        lastY = y;

        moves++;

        if (moves > MAX_MOVES) {
            printf("Game over! No more moves left.\n");
            break;
        }
    }

    return 0;
}