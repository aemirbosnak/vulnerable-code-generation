//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

int grid[MAX_SIZE][MAX_SIZE];
int solution[MAX_SIZE][MAX_SIZE];

void print_grid(int grid[MAX_SIZE][MAX_SIZE]) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void generate_solution(int grid[MAX_SIZE][MAX_SIZE]) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            solution[i][j] = grid[i][j];
        }
    }
}

int is_valid(int grid[MAX_SIZE][MAX_SIZE], int row, int col, int num) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;

    for (i = subgrid_row; i < subgrid_row + 3; i++) {
        for (j = subgrid_col; j < subgrid_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void solve_sudoku(int grid[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    int count = 0;

    while (count < MAX_SIZE * MAX_SIZE) {
        int row = rand() % MAX_SIZE;
        int col = rand() % MAX_SIZE;

        if (grid[row][col] == 0) {
            int num = 1;

            while (!is_valid(grid, row, col, num)) {
                num++;
            }

            grid[row][col] = num;
            count++;
        }
    }
}

int main() {
    srand(time(NULL));

    int grid[MAX_SIZE][MAX_SIZE];

    printf("Enter the initial grid:\n");

    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Initial Grid:\n");
    print_grid(grid);

    generate_solution(grid);
    solve_sudoku(grid);

    printf("\nFinal Grid:\n");
    print_grid(grid);

    return 0;
}