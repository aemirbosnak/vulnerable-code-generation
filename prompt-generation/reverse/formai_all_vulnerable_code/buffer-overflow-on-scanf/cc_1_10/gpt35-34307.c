//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shape shifting
#include <stdio.h>

#define N 9

int grid[N][N]; // the initial Sudoku grid

void display() {
    // displays the current state of the grid
    printf("-------------------------\n");
    for(int i = 0; i < N; i++) {
        printf("| ");
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
            if((j+1)%3 == 0) printf("| ");
        }
        printf("\n");
        if((i+1)%3 == 0) printf("-------------------------\n");
    }
}

int isValid(int row, int col, int num) {
    // checks if inserting 'num' at position row,col is valid
    for(int i = 0; i < N; i++) {
        if(grid[row][i] == num) return 0; // check row
        if(grid[i][col] == num) return 0; // check column
    }
    int r = row - row%3, c = col - col%3;
    for(int i = r; i < r+3; i++) {
        for(int j = c; j < c+3; j++) {
            if(grid[i][j] == num) return 0; // check 3x3 sub-grid
        }
    }
    return 1;
}

int solve(int row, int col) {
    // recursive function that solves the Sudoku grid
    if(row == N-1 && col == N) return 1;
    if(col == N) {
        row++;
        col = 0;
    }
    if(grid[row][col] > 0) return solve(row, col+1);
    for(int num = 1; num <= N; num++) {
        if(isValid(row, col, num)) {
            grid[row][col] = num;
            if(solve(row, col+1)) return 1;
        }
        grid[row][col] = 0; // backtrack
    }
    return 0;
}

int main() {
    // initialize the Sudoku grid
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if(solve(0, 0)) {
        printf("Sudoku solved:\n");
        display();
    }
    else {
        printf("Invalid Sudoku grid\n");
    }
    return 0;
}