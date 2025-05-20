//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int value;
    int revealed;
} Cell;

Cell board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    int i, j, pairIndex;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = 0;
            board[i][j].revealed = 0;
            if (i < BOARD_SIZE / 2 && j < BOARD_SIZE / 2) {
                board[i][j].value = rand() % NUM_PAIRS + 1;
                pairIndex = board[i][j].value - 1;
                board[i + BOARD_SIZE / 2][j + BOARD_SIZE / 2].value = pairIndex + 1;
            }
        }
    }
}

void revealCell(int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && !board[row][col].revealed) {
        board[row][col].revealed = 1;
        if (board[row][col].value != 0) {
            printf("Found pair: %d\n", board[row][col].value);
            if (checkForWin()) {
                printf("Congratulations! You've won the game!\n");
                exit(EXIT_SUCCESS);
            }
        }
    } else {
        printf("Invalid move. Please try again.\n");
    }
}

void printBoard() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d  ", board[i][j].value);
            } else {
                printf("-  ");
            }
        }
        printf("\n");
    }
}

int checkForWin() {
    int revealedCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                revealedCount++;
            }
        }
    }

    return revealedCount == NUM_PAIRS;
}

int main() {
    srand(time(NULL));
    initBoard();

    int row, col;
    while (1) {
        printBoard();
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        revealCell(row - 1, col - 1);
        system("clear"); // or 'cls' on Windows
    }

    return 0;
}