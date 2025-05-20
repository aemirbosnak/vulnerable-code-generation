//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h> 

#define N 9

int grid[N][N];

//function to check if a number is already in the same row
int checkRow(int row, int num) {
    for(int i=0; i<N; i++) {
        if(grid[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

//function to check if a number is already in the same column
int checkCol(int col, int num) {
    for(int i=0; i<N; i++) {
        if(grid[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

//function to check if a number is already in the same box
int checkBox(int row, int col, int num) {
    row = row - row % 3;
    col = col - col % 3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[row+i][col+j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

//function to find the next empty cell
int findEmpty(int* row, int* col) {
    for(*row=0; *row<N; (*row)++) {
        for(*col=0; *col<N; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

//function to solve the Sudoku puzzle
int solve() {
    int row, col;
    
    //check if there are any empty cells left
    if(!findEmpty(&row, &col)) {
        return 1;
    }
    
    //try a number in the empty cell
    for(int num=1; num<=9; num++) {
        if(!checkRow(row, num) && !checkCol(col, num) && !checkBox(row, col, num)) {
            grid[row][col] = num;
            
            //if the number is valid, continue solving the puzzle recursively
            if(solve()) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    //input the Sudoku puzzle
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    //solve the puzzle
    if(solve()) {
        //print the solution
        printf("\nSolution:\n");
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("\nNo solution exists.\n");
    }
    
    return 0;
}