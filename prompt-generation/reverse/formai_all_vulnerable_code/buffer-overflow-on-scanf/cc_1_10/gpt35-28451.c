//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];
int row[N];
int col[N];
int box[N];
int solutions = 0;

void printGrid() {
    printf("Solution %d: \n", solutions + 1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveSudoku(int r, int c) {
    // Base case: if we've reached the end of the grid, print the solution
    if(r == N) {
        printGrid();
        solutions++;
        return;
    }
    
    // If this cell is already filled, move on to the next one
    if(grid[r][c] != UNASSIGNED) {
        if(c == N - 1) {
            solveSudoku(r + 1, 0);
        } else {
            solveSudoku(r, c + 1);
        }
        return;
    }
    
    // Try every possible digit in this cell
    for(int i = 1; i <= 9; i++) {
        int boxIndex = (r / 3) * 3 + (c / 3);
        if(!(row[r] & 1 << i) && !(col[c] & 1 << i) && !(box[boxIndex] & 1 << i)) {
            row[r] |= 1 << i;
            col[c] |= 1 << i;
            box[boxIndex] |= 1 << i;
            grid[r][c] = i;
            
            if(c == N - 1) {
                solveSudoku(r + 1, 0);
            } else {
                solveSudoku(r, c + 1);
            }
            
            row[r] &= ~(1 << i);
            col[c] &= ~(1 << i);
            box[boxIndex] &= ~(1 << i);
            grid[r][c] = UNASSIGNED;
        }
    }
}

int main() {
    printf("Please input the 9x9 Sudoku puzzle one row at a time, with 0 representing an empty cell: \n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            if(grid[i][j] != UNASSIGNED) {
                int boxIndex = (i / 3) * 3 + (j / 3);
                row[i] |= 1 << grid[i][j];
                col[j] |= 1 << grid[i][j];
                box[boxIndex] |= 1 << grid[i][j];
            }
        }
    }
    
    solveSudoku(0, 0);
    
    if(solutions == 0) {
        printf("No solutions found.\n");
    } else if(solutions == 1) {
        printf("1 solution found.\n");
    } else {
        printf("%d solutions found.\n", solutions);
    }
    
    return 0;
}