//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void multiplayerSudoku(int grid[SIZE][SIZE]) {
    int playerCount;
    printf("Enter number of players: ");
    scanf("%d", &playerCount);

    int currentPlayer = 0;
    while (true) {
        printGrid(grid);
        printf("Player %d's turn. Enter row, column, and number (0 to exit): ", currentPlayer + 1);
        int row, col, num;
        scanf("%d %d %d", &row, &col, &num);

        if (row == 0 && col == 0 && num == 0) {
            printf("Exiting the game.\n");
            break;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("Invalid input! Please enter numbers in the range 1-9 for row, column and number.\n");
            continue;
        }

        if (grid[row - 1][col - 1] != 0) {
            printf("Cell already filled! Try a different cell.\n");
            continue;
        }

        if (isSafe(grid, row - 1, col - 1, num)) {
            grid[row - 1][col - 1] = num;
            currentPlayer = (currentPlayer + 1) % playerCount; // Switch player turn
        } else {
            printf("Invalid move! %d cannot be placed in the selected cell.\n", num);
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    multiplayerSudoku(grid);
    return 0;
}