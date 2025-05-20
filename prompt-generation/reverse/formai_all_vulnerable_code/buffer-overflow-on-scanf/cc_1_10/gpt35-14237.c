//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 10
#define MAX_COL 10

int check_path(int maze[MAX_ROW][MAX_COL], int start_row, int start_col, int end_row, int end_col, int visited[MAX_ROW][MAX_COL])
{
    if (start_row < 0 || start_row >= MAX_ROW || start_col < 0 || start_col >= MAX_COL || maze[start_row][start_col] == 0 || visited[start_row][start_col])
        return 0;

    visited[start_row][start_col] = 1;

    if (start_row == end_row && start_col == end_col)
        return 1;
    if (check_path(maze, start_row, start_col + 1, end_row, end_col, visited)) { // go right
        printf("(%d,%d) -> ", start_row, start_col);
        return 1;
    }
    if (check_path(maze, start_row, start_col - 1, end_row, end_col, visited)) { // go left
        printf("(%d,%d) -> ", start_row, start_col);
        return 1;
    }
    if (check_path(maze, start_row + 1, start_col, end_row, end_col, visited)) { // go down
        printf("(%d,%d) -> ", start_row, start_col);
        return 1;
    }
    if (check_path(maze, start_row - 1, start_col, end_row, end_col, visited)) { // go up
        printf("(%d,%d) -> ", start_row, start_col);
        return 1;
    }

    return 0;
}

int main()
{
    int maze[MAX_ROW][MAX_COL] = {
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}
    };

    int start_row, start_col, end_row, end_col;
    int visited[MAX_ROW][MAX_COL] = {0};

    printf("Enter the starting row and column:\n");
    scanf("%d%d", &start_row, &start_col);

    printf("Enter the ending row and column:\n");
    scanf("%d%d", &end_row, &end_col);

    printf("\n");

    if (check_path(maze, start_row, start_col, end_row, end_col, visited)) {
        printf("(%d,%d)\n", start_row, start_col);
        return 0;
    }

    printf("Path not found.\n");
}