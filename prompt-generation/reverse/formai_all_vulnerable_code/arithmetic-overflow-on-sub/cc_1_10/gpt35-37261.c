//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

/**
 * Initialize board with numbers from 1 to ROWS*COLS
 */
void initializeBoard(int board[][COLS]) {
    int count = 1;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = count;
            count++;
        }
    }
}

/**
 * Shuffle the board by swapping random elements
 */
void shuffleBoard(int board[][COLS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int x1 = rand() % ROWS;
            int y1 = rand() % COLS;

            int x2 = rand() % ROWS;
            int y2 = rand() % COLS;

            int temp = board[x1][y1];
            board[x1][y1] = board[x2][y2];
            board[x2][y2] = temp;
        }
    }
}

/**
 * Print the current state of the board
 */
void printBoard(int board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * Prompt the user to select two elements to flip
 */
void promptFlip(int board[][COLS], int* r1, int* c1, int* r2, int* c2) {
    printf("Enter the row and column for element 1: ");
    scanf("%d %d", r1, c1);

    printf("Enter the row and column for element 2: ");
    scanf("%d %d", r2, c2);

    // Convert to 0-indexed
    (*r1)--;
    (*c1)--;
    (*r2)--;
    (*c2)--;
}

/**
 * Check if the elements at (r1, c1) and (r2, c2) are adjacent
 */
int isAdjacent(int r1, int c1, int r2, int c2) {
    if(r1 == r2) {
        return abs(c1 - c2) == 1;
    }
    if(c1 == c2) {
        return abs(r1 - r2) == 1;
    }
    return 0;
}

/**
 * Flip the elements at (r1, c1) and (r2, c2)
 */
void flip(int board[][COLS], int r1, int c1, int r2, int c2) {
    int temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;
}

/**
 * Check if the board is in a winning state
 */
int isBoardWin(int board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] != i*COLS + j + 1) {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * Main function for the memory game
 */
int main() {
    int board[ROWS][COLS];
    initializeBoard(board);
    shuffleBoard(board);
    printBoard(board);

    int r1, c1, r2, c2;
    int moves = 0;
    while(!isBoardWin(board)) {
        promptFlip(board, &r1, &c1, &r2, &c2);

        if(isAdjacent(r1, c1, r2, c2)) {
            flip(board, r1, c1, r2, c2);
            printBoard(board);
            moves++;
        } else {
            printf("Invalid move! Elements are not adjacent.\n");
        }
    }

    printf("Congratulations! You won in %d moves.\n", moves);

    return 0;
}