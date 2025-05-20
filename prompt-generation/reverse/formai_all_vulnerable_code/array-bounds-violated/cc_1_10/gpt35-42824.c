//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Initializes the board with numbers from 0 to 7
void initializeBoard(int board[ROWS][COLS]) {
    int num = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = num % 8;
            num++;
        }
    }
}

// Randomizes the order of the numbers on the board
void shuffleBoard(int board[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = ROWS - 1; i > 0; i--) {
        for (int j = COLS - 1; j > 0; j--) {
            int rndRow = rand() % (i + 1);
            int rndCol = rand() % (j + 1);

            int temp = board[i][j];
            board[i][j] = board[rndRow][rndCol];
            board[rndRow][rndCol] = temp;
        }
    }
}

// Prints the current state of the board
void printBoard(int board[ROWS][COLS], int hidden[ROWS][COLS]) {
    printf("\nCurrent board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (hidden[i][j]) {
                printf("? ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Asks the user for a row and column to flip over
void userPick(int *row, int *col) {
    printf("\nEnter row: ");
    scanf("%d", row);

    printf("Enter column: ");
    scanf("%d", col);
}

// Flips over the cell at the given row and column
void flipCell(int board[ROWS][COLS], int hidden[ROWS][COLS], int row, int col) {
    hidden[row][col] = 0;
}

// Checks to see if any cells are still hidden
int allCellsFound(int hidden[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (hidden[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[ROWS][COLS];
    int hidden[ROWS][COLS];

    initializeBoard(board);
    initializeBoard(hidden);

    shuffleBoard(board);

    printf("Welcome to the Memory Game!\n");

    while (!allCellsFound(hidden)) {

        printBoard(board, hidden);

        int row, col;
        userPick(&row, &col);

        flipCell(board, hidden, row, col);

        if (board[row][col] != board[0][0]) {
            hidden[row][col] = 1;
            hidden[0][0] = 1;
        } else {
            printf("You found a match!\n");
        }
    }

    printf("\nCongratulations! You found all the matches!\n");

    return 0;
}