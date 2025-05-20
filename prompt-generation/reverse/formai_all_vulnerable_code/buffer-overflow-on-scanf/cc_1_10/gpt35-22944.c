//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

#define UNASSIGNED 0
#define N 9

void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int is_valid(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;

    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num)
                return 0;
        }
    }

    return 1;
}

int find_unassigned(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
        }
    }
    return 0;
}

int solve_sudoku(int grid[N][N]) {
    int row, col;
    if (!find_unassigned(grid, &row, &col))
        return 1;

    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid))
                return 1;
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main() {
    int grid[N][N];

    printf("Enter the Sudoku grid in the following format (use 0 for blank spaces):\n");
    printf("[[5,3,0,0,7,0,0,0,0],\n [6,0,0,1,9,5,0,0,0],\n [0,9,8,0,0,0,0,6,0],\n [8,0,0,0,6,0,0,0,3],\n [4,0,0,8,0,3,0,0,1],\n [7,0,0,0,2,0,0,0,6],\n [0,6,0,0,0,0,2,8,0],\n [0,0,0,4,1,9,0,0,5],\n [0,0,0,0,8,0,0,7,9]]\n");
    // Sample input: [[5,3,0,0,7,0,0,0,0],[6,0,0,1,9,5,0,0,0],[0,9,8,0,0,0,0,6,0],[8,0,0,0,6,0,0,0,3],[4,0,0,8,0,3,0,0,1],[7,0,0,0,2,0,0,0,6],[0,6,0,0,0,0,2,8,0],[0,0,0,4,1,9,0,0,5],[0,0,0,0,8,0,0,7,9]]
    char temp, temp2;
    int value;
    scanf("%c%c", &temp, &temp2);
    for (int i = 0; i < N; i++) {
        scanf("%c", &temp);
        for (int j = 0; j < N; j++) {
            scanf("%d%c", &value, &temp);
            grid[i][j] = value;
        }
        scanf("%c", &temp);
    }

    printf("\nInput grid:\n");
    print_grid(grid);

    if (solve_sudoku(grid) == 1) {
        printf("\nSolution:\n");
        print_grid(grid);
    }
    else
        printf("\nNo solution exists.\n");

    return 0;
}