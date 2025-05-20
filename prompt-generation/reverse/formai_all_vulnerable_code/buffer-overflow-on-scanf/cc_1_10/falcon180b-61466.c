//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

int start_row, start_col, end_row, end_col;

void print_maze() {
    for(int i=0; i<MAX_ROWS; i++) {
        for(int j=0; j<MAX_COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void dfs(int row, int col) {
    if(row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS || maze[row][col] == 1) {
        return;
    }
    if(row == end_row && col == end_col) {
        printf("Path found!\n");
        exit(0);
    }
    maze[row][col] = 1;
    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
    maze[row][col] = 0;
}

int main() {
    printf("Enter the starting point (row, col): ");
    scanf("%d%d", &start_row, &start_col);
    printf("Enter the ending point (row, col): ");
    scanf("%d%d", &end_row, &end_col);
    dfs(start_row, start_col);
    printf("No path found.\n");
    return 0;
}