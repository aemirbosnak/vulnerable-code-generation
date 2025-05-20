//FormAI DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>

int grid[9][9];

void printGrid() {
    int i, j;
    printf("+-------+-------+-------+\n");
    for(i=0; i<9; i++) {
        printf("| ");
        for(j=0; j<9; j++) {
            if(grid[i][j] == 0) {
                printf(". ");
            }
            else {
                printf("%d ", grid[i][j]);
            }
            if(j%3 == 2) printf("| ");
        }
        printf("\n");
        if(i%3 == 2) printf("+-------+-------+-------+\n");
    }
}

int findEmptyCell(int *row, int *col) {
    for(*row=0; *row<9; (*row)++) {
        for(*col=0; *col<9; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int checkRow(int row, int num) {
    int i;
    for(i=0; i<9; i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

int checkCol(int col, int num) {
    int i;
    for(i=0; i<9; i++) {
        if(grid[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkSquare(int row, int col, int num) {
    int i, j;
    int rowStart = (row/3)*3;
    int colStart = (col/3)*3;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(grid[rowStart+i][colStart+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    int row, col, num;
    if(!findEmptyCell(&row, &col)) {
        return 1;
    }
    for(num=1; num<=9; num++) {
        if(checkRow(row, num) && checkCol(col, num) && checkSquare(row, col, num)) {
            grid[row][col] = num;
            if(solve()) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int i, j;
    printf("Welcome to the Medieval Sudoku Solver! Please Enter Grid 1-9 (0 for empty cells):\n");
    for(i=0; i<9; i++) {
        printf("Enter row #%d: ", i+1);
        for(j=0; j<9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("Entered Sudoku Grid:\n");
    printGrid();
    if(solve()) {
        printf("Solved Sudoku Grid:\n");
        printGrid();
    }
    else {
        printf("This Sudoku Grid is unsolvable!\n");
    }
    return 0;
}