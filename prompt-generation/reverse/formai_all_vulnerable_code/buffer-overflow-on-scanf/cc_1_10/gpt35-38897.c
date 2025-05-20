//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE] = {0};

//Function to print the maze
void print_maze(int rows, int columns) {
    printf("\nMaze:\n");
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < columns ; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

//Function to find if a path exists to the end of the maze
int find_path(int rows, int columns, int x, int y) {
    if(x < 0 || x >= rows || y < 0 || y >= columns || maze[x][y] == 0 || visited[x][y] == 1) {
        return 0;
    }
    if(x == rows - 1 && y == columns - 1) {
        return 1;
    }
    visited[x][y] = 1;
    if(find_path(rows, columns, x - 1, y) == 1) {
        return 1;
    }
    if(find_path(rows, columns, x, y + 1) == 1) {
        return 1;
    }
    if(find_path(rows, columns, x + 1, y) == 1) {
        return 1;
    }
    if(find_path(rows, columns, x, y - 1) == 1) {
        return 1;
    }
    return 0;
}

int main() {
    int rows, columns;

    printf("Enter the number of rows and columns in the maze (<= %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &columns);

    printf("Enter the maze (%d rows and %d columns) as 0s and 1s:\n", rows, columns);
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < columns ; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    print_maze(rows, columns);

    if(find_path(rows, columns, 0, 0) == 1) {
        printf("\nA path exists to the end of the maze.\n");
    }
    else {
        printf("\nNo path exists to the end of the maze.\n");
    }

    return 0;
}