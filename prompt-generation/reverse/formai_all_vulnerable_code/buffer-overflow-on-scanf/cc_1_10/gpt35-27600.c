//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>

#define N 9

int grid[N][N];

void get_input() {
    // Get the input Sudoku puzzle from the user
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

void print_grid() {
    // Print the Sudoku puzzle to the console
    printf("Sudoku Puzzle:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    // Check if a number can be placed in a given cell
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int x = row - row % 3;
    int y = col - col % 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    // Solve the Sudoku puzzle using backtracking
    int row = -1;
    int col = -1;
    int solved = 1;
    for (int i = 0; i < N && solved; i++) {
        for (int j = 0; j < N && solved; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                solved = 0;
            }
        }
    }
    if (solved) {
        return 1;
    }
    for (int num = 1; num <= N; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            if (solve()) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to Sudoku Solver!\n");
    printf("Please enter the puzzle numbers row-wise (use 0 for unknown cells):\n");
    get_input();
    print_grid();
    if (solve()) {
        printf("Solution:\n");
        print_grid();
    } else {
        printf("No solution found!\n");
    }
    return 0;
}