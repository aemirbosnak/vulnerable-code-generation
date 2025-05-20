//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for game board dimensions
#define ROWS 10
#define COLS 10

// Function prototypes
void displayBoard(int board[ROWS][COLS]);
void initBoard(int board[ROWS][COLS]);
void addMines(int board[ROWS][COLS], int numMines);
int countSurroundingMines(int board[ROWS][COLS], int row, int col);
void revealCell(int board[ROWS][COLS], int row, int col, int *numUncovered);
void gameLoop(int board[ROWS][COLS], int numMines);

int main() {
    int board[ROWS][COLS];
    int numMines;

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Minesweeper game!\n");
    printf("How many mines would you like to play with? (1 - %d)\n", ROWS*COLS/2);
    scanf("%d", &numMines);

    // Make sure user enters a valid number of mines
    while (numMines < 1 || numMines > ROWS*COLS/2) {
        printf("Please enter a number between 1 and %d.\n", ROWS*COLS/2);
        scanf("%d", &numMines);
    }

    initBoard(board);
    addMines(board, numMines);
    gameLoop(board, numMines);

    return 0;
}

// Function to display the game board
void displayBoard(int board[ROWS][COLS]) {
    printf("\n  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("- ");
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d|", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board with all cells hidden
void initBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to randomly add mines to the game board
void addMines(int board[ROWS][COLS], int numMines) {
    int row, col;

    for (int i = 0; i < numMines; i++) {
        row = rand() % ROWS;
        col = rand() % COLS;

        // Make sure that a mine is not already placed in this cell
        while (board[row][col] == '*') {
            row = rand() % ROWS;
            col = rand() % COLS;
        }

        // Place mine in current cell
        board[row][col] = '*';
    }
}

// Function to count the number of mines surrounding a cell
int countSurroundingMines(int board[ROWS][COLS], int row, int col) {
    int count = 0;

    // Check neighboring cells for mines
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            // Ignore cells that are outside the board or the current cell itself
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS || (i == row && j == col)) {
                continue;
            }

            if (board[i][j] == '*') {
                count++;
            }
        }
    }

    return count;
}

// Function to recursively reveal cells until a mine is hit
void revealCell(int board[ROWS][COLS], int row, int col, int *numUncovered) {
    // If current cell has already been uncovered or is outside the board, return
    if (board[row][col] != '-') {
        return;
    }

    // Uncover current cell and increment number of uncovered cells
    board[row][col] = '0' + countSurroundingMines(board, row, col);
    (*numUncovered)++;

    // If a mine is hit, exit the function
    if (board[row][col] == '*') {
        return;
    }

    // If current cell has no neighboring mines, recursively reveal all neighboring cells
    if (board[row][col] == '0') {
        for (int i = row-1; i <= row+1; i++) {
            for (int j = col-1; j <= col+1; j++) {
                // Ignore cells that are outside the board or the current cell itself
                if (i < 0 || i >= ROWS || j < 0 || j >= COLS || (i == row && j == col)) {
                    continue;
                }

                revealCell(board, i, j, numUncovered);
            }
        }
    }
}

// Main game loop
void gameLoop(int board[ROWS][COLS], int numMines) {
    int row, col, numUncovered = 0;

    while (numUncovered < ROWS*COLS - numMines) {
        displayBoard(board);

        printf("Enter the row and column number of the cell you want to uncover: ");
        scanf("%d %d", &row, &col);

        // Make sure user enters a valid cell that has not already been uncovered
        while (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != '-') {
            printf("Please enter a valid cell that has not already been uncovered.\n");
            printf("Enter the row and column number of the cell you want to uncover: ");
            scanf("%d %d", &row, &col);
        }

        revealCell(board, row, col, &numUncovered);

        // If a mine is hit, end the game
        if (board[row][col] == '*') {
            displayBoard(board);
            printf("\nGame Over! You hit a mine.\n");
            return;
        }
    }

    displayBoard(board);
    printf("\nCongratulations! You uncovered all non-mine cells.\n");
}