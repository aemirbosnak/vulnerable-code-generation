//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '#', '.', '#', '#', '.', '.'},
    {'#', '#', '.', '.', '.', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '#', '.', '#', '.', '.', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '#', '#'},
};

int visited[ROW][COL] = {0};

int dfs(int row, int col, int dest_row, int dest_col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL) return 0;
    if (maze[row][col] == '#' || visited[row][col]) return 0;
    if (row == dest_row && col == dest_col) return 1;
    visited[row][col] = 1;
    if (dfs(row - 1, col, dest_row, dest_col)) {
        printf("(%d, %d) -> ", row-1, col);
        return 1;
    }
    if (dfs(row, col + 1, dest_row, dest_col)) {
        printf("(%d, %d) -> ", row, col+1);
        return 1;
    }
    if (dfs(row + 1, col, dest_row, dest_col)) {
        printf("(%d, %d) -> ", row+1, col);
        return 1;
    }
    if (dfs(row, col - 1, dest_row, dest_col)) {
        printf("(%d, %d) -> ", row, col-1);
        return 1;
    }
    return 0;
}

int main() {
    int start_row, start_col;
    int dest_row, dest_col;

    printf("Enter starting row and column: ");
    scanf("%d%d", &start_row, &start_col);

    printf("Enter destination row and column: ");
    scanf("%d%d", &dest_row, &dest_col);

    if (dfs(start_row, start_col, dest_row, dest_col))
        printf("(%d, %d)\n", dest_row, dest_col);
    else
        printf("No path found\n");

    return 0;
}