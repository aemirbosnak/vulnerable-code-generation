//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Linus Torvalds
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int startRow = 1;
int startCol = 1;

int endRow = 8;
int endCol = 8;

bool visited[ROW][COL];

bool route_found = false;

void find_route(int row, int col)
{
    printf("(%d, %d)\n", row, col);

    if (row == endRow && col == endCol)
    {
        route_found = true;
        return;
    }

    visited[row][col] = true;

    if (maze[row-1][col] != '#' && !visited[row-1][col] && !route_found)
        find_route(row-1, col);

    if (maze[row+1][col] != '#' && !visited[row+1][col] && !route_found)
        find_route(row+1, col);

    if (maze[row][col-1] != '#' && !visited[row][col-1] && !route_found)
        find_route(row, col-1);

    if (maze[row][col+1] != '#' && !visited[row][col+1] && !route_found)
        find_route(row, col+1);

    if (!route_found)
        printf("Backtracking to (%d, %d)\n", row, col);
}

int main()
{
    printf("Finding route in maze...\n");

    find_route(startRow, startCol);

    if (route_found)
        printf("Route found!\n");
    else
        printf("Route not found :(\n");

    return 0;
}