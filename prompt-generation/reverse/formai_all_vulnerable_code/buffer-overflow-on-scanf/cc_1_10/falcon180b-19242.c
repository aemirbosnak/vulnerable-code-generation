//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {{1, 1, 1, 1, 1},
                    {1, 0, 0, 0, 1},
                    {1, 1, 0, 1, 1},
                    {1, 0, 1, 0, 1},
                    {1, 1, 1, 1, 1}};

void printMaze(int maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int isValidCell(int maze[ROW][COL], int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 0) {
        return 1;
    }
    return 0;
}

void solveMaze(int maze[ROW][COL], int row, int col) {
    int i, j;
    if (row == ROW - 1 && col == COL - 1) {
        printf("Solution found!\n");
        return;
    }
    if (!isValidCell(maze, row, col)) {
        return;
    }
    maze[row][col] = 1;
    if (isValidCell(maze, row - 1, col)) {
        solveMaze(maze, row - 1, col);
    }
    if (isValidCell(maze, row, col - 1)) {
        solveMaze(maze, row, col - 1);
    }
    if (isValidCell(maze, row + 1, col)) {
        solveMaze(maze, row + 1, col);
    }
    if (isValidCell(maze, row, col + 1)) {
        solveMaze(maze, row, col + 1);
    }
    maze[row][col] = 0;
}

int main() {
    int row, col;
    printf("Enter starting row and column: ");
    scanf("%d %d", &row, &col);
    if (!isValidCell(maze, row, col)) {
        printf("Invalid starting position.\n");
        return 0;
    }
    printf("Maze:\n");
    printMaze(maze);
    solveMaze(maze, row, col);
    return 0;
}