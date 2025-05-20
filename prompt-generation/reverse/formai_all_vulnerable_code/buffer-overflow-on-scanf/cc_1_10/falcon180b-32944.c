//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9
#define MAX_VAL 9

int grid[MAX_SIZE][MAX_SIZE] = {0};

void print_grid() {
    int i, j;
    for(i = 0; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    int i, j;
    for(i = 0; i < MAX_SIZE; i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }
    for(j = 0; j < MAX_SIZE; j++) {
        if(grid[i][j] == num) {
            return 0;
        }
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for(i = box_row; i < box_row + 3; i++) {
        for(j = box_col; j < box_col + 3; j++) {
            if(grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void solve_sudoku() {
    int i, j;
    for(i = 0; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            if(grid[i][j] == 0) {
                int num = 1;
                while(is_valid(i, j, num)) {
                    grid[i][j] = num;
                    num++;
                }
            }
        }
    }
}

int main() {
    int i, j;
    for(i = 0; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    solve_sudoku();
    print_grid();
    return 0;
}