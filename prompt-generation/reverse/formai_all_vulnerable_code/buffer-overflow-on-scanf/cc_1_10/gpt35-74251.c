//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int maze[MAX_SIZE][MAX_SIZE], solution[MAX_SIZE][MAX_SIZE];
int rows, cols, start_row, start_col, end_row, end_col;

int find_path(int row, int col) {
    if(row < 0 || col < 0 || row >= rows || col >= cols) {
        // If out of the borders of the maze
        return 0;
    }
    if(maze[row][col] == 1 || solution[row][col] == 1) {
        // If there is a wall or we already passed by this position
        return 0;
    }
    if(row == end_row && col == end_col) {
        // If we reached the end position
        solution[row][col] = 1;
        return 1;
    }

    solution[row][col] = 1;

    if(find_path(row, col-1) || find_path(row-1, col) || find_path(row, col+1) || find_path(row+1, col)) {
        return 1;
    }

    solution[row][col] = 0;
    return 0;
}

int main() {
    printf("Enter the number of rows:\n");
    scanf("%d", &rows);
    printf("Enter the number of columns:\n");
    scanf("%d", &cols);

    printf("Enter the maze matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("Enter the starting position row and column:\n");
    scanf("%d %d", &start_row, &start_col);

    printf("Enter the ending position row and column:\n");
    scanf("%d %d", &end_row, &end_col);

    if(find_path(start_row, start_col)) {
        printf("Solution found!\n");
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                printf("%d ", solution[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Solution not found.\n");
    }

    return 0;
}