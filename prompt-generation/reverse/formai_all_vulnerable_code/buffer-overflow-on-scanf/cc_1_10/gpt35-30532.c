//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mind-bending
#include <stdio.h>
#define N 9

int grid[N][N];

void printGrid(int grid[N][N]){
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int findUnassigned(int row, int col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return 1;
    return 0;
}

int isSafe(int row, int col, int num){
    for (int i = 0; i < 9; ++i)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i + boxRow][j + boxCol] == num)
                return 0;

    return 1;
}

int solveSudoku(){
    int row, col;

    if (!findUnassigned(row, col))
        return 1;

    for (int num = 1; num <= 9; ++num){
        if (isSafe(row, col, num)){
            grid[row][col] = num;

            if (solveSudoku())
                return 1;

            grid[row][col] = 0;
        }
    }
    return 0;
}

int main(){
    printf("Enter the Sudoku grid(Use 0 to represent blanks):\n");
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            scanf("%d", &grid[i][j]);
    }

    if (solveSudoku())
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}