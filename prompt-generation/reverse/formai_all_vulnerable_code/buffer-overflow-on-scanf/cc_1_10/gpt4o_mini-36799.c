//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#define N 9

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
            break;
    }
    if (isEmpty)
        return true;
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void inputSudoku(int grid[N][N]) {
    printf("Please enter your Sudoku puzzle (use 0 for blanks):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int numPlayers;
    printf("Welcome to Multiplayer Sudoku Solver!\n");
    printf("How many players will be participating? ");
    scanf("%d", &numPlayers);
    
    for (int player = 1; player <= numPlayers; player++) {
        int grid[N][N] = {0};
        printf("\nPlayer %d, ", player);
        inputSudoku(grid);
        
        printf("Player %d's Sudoku puzzle:\n", player);
        printGrid(grid);
        
        if (solveSudoku(grid))
            printf("Sudoku solution for Player %d:\n", player);
        else
            printf("No solution exists for Player %d's Sudoku puzzle.\n", player);
        
        printGrid(grid);
    }

    printf("\nThank you for playing! Goodbye!\n");
    return 0;
}