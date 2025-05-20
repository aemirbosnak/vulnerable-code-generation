//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>
#define UNASSIGNED 0
#define N 9

int grid[N][N];

int solveSudoku(int row, int col)
{
    if (row == N - 1 && col == N)
        return 1;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != UNASSIGNED)
        return solveSudoku(row, col + 1);

    for (int num = 1; num <= N; num++) {
        int flag = 1;
        for (int x = 0; x < N; x++) {
            if (grid[row][x] == num || grid[x][col] == num) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            int startRow = row - row % 3, startCol = col - col % 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (grid[startRow + i][startCol + j] == num) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) {
                grid[row][col] = num;
                if (solveSudoku(row, col + 1))
                    return 1;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

void printGrid()
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main()
{
    printf("Enter Sudoku puzzle (0 for blank cells):\n");
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            scanf("%d", &grid[row][col]);

    if (solveSudoku(0, 0)) {
        printf("\nSolution:\n");
        printGrid();
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}