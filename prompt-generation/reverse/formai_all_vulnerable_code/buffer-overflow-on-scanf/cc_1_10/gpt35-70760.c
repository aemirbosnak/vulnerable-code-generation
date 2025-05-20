//FormAI DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>

#define UNASS 0
#define DIM 9

int grid[DIM][DIM];

int Find_Empty(int row, int col);
int Is_Valid(int num, int row, int col);
void Solve_Sudoku();

int main() {
    // Input initial Grid
    printf("Enter the Initial Sudoku Grid (Enter 0 for Empty cells):\n");
    for(int i=0; i<DIM; i++) {
        for(int j=0; j<DIM; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    Solve_Sudoku(); // Solve Sudoku

    // Print Solved Sudoku Grid
    printf("Solved Sudoku Grid:\n");
    for(int i=0; i<DIM; i++) {
        for(int j=0; j<DIM; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int Find_Empty(int row, int col) {
    for(int i=row; i<DIM; i++) {
        for(int j=(i == row ? col : 0); j<DIM; j++) {
            if(grid[i][j] == UNASS)
                return i*DIM+j;
        }
    }
    return -1;
}

int Is_Valid(int num, int row, int col) {
    int boxX = row - row%3;
    int boxY = col - col%3;

    for(int i=0; i<DIM; i++) {
        if(grid[row][i] == num || grid[i][col] == num)
            return 0;
    }
    for(int i=boxX; i<boxX+3; i++) {
        for(int j=boxY; j<boxY+3; j++) {
            if(grid[i][j] == num)
                return 0;
        }
    }
    return 1;
}

void Solve_Sudoku() {
    int pos = Find_Empty(0, 0);
    if(pos == -1)
        return;

    int row = pos/DIM;
    int col = pos%DIM;

    for(int num=1; num<=DIM; num++) {
        if(Is_Valid(num, row, col)) {
            grid[row][col] = num;

            Solve_Sudoku(); // Recursive Call

            if(Find_Empty(row, col) == -1)
                return;

            grid[row][col] = UNASS;
        }
    }
}