//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int maze[MAX_ROWS][MAX_COLS];
int startRow, startCol;
int endRow, endCol;

void printMaze(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int isValidRow(int row) {
    return row >= 0 && row < MAX_ROWS;
}

int isValidCol(int col) {
    return col >= 0 && col < MAX_COLS;
}

int getAdjacentCell(int row, int col) {
    int adjacentRow = row - 1;
    int adjacentCol = col - 1;
    int up = isValidRow(adjacentRow) && isValidCol(adjacentCol)? maze[adjacentRow][adjacentCol] : -1;
    int down = isValidRow(adjacentRow) && isValidCol(adjacentCol)? maze[adjacentRow][adjacentCol] : -1;
    int left = isValidRow(adjacentRow) && isValidCol(adjacentCol)? maze[adjacentRow][adjacentCol] : -1;
    int right = isValidRow(adjacentRow) && isValidCol(adjacentCol)? maze[adjacentRow][adjacentCol] : -1;
    return (up == 1 && down == 1) || (left == 1 && right == 1)? -1 : up + down + left + right;
}

void solveMaze(int startRow, int startCol, int endRow, int endCol) {
    if (startRow == endRow && startCol == endCol) {
        printf("You have reached the end!\n");
        return;
    }

    if (startRow == endRow) {
        if (startCol < endCol) {
            solveMaze(startRow, startCol + 1, endRow, endCol);
        } else if (startCol > endCol) {
            solveMaze(startRow, startCol - 1, endRow, endCol);
        } else {
            printf("You have reached the end!\n");
        }
    } else {
        if (startCol < endCol) {
            solveMaze(startRow, startCol + 1, endRow, endCol);
        } else if (startCol > endCol) {
            solveMaze(startRow, startCol - 1, endRow, endCol);
        } else {
            solveMaze(startRow + 1, startCol, endRow, endCol);
        }
    }
}

int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    maze[0][0] = 1;

    printf("Enter the starting row (0-%d): ", rows - 1);
    scanf("%d", &startRow);
    printf("Enter the starting column (0-%d): ", cols - 1);
    scanf("%d", &startCol);
    printf("Enter the ending row (0-%d): ", rows - 1);
    scanf("%d", &endRow);
    printf("Enter the ending column (0-%d): ", cols - 1);
    scanf("%d", &endCol);

    solveMaze(startRow, startCol, endRow, endCol);

    printMaze(rows, cols);

    return 0;
}