//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int maze[MAX_SIZE][MAX_SIZE];  // store the maze
int visited[MAX_SIZE][MAX_SIZE];  // store visited maze cells
int bestPath[MAX_SIZE];  // store best path from start to end
int dx[4] = {1, 0, -1, 0};  // direction vector for x-axis
int dy[4] = {0, 1, 0, -1};  // direction vector for y-axis
int rows, cols;  // dimensions of maze
int startRow, startCol, endRow, endCol;  // start and end positions

// function to read input maze
void readMaze(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &maze[i][j]);
            if (maze[i][j] == 2) {
                startRow = i;
                startCol = j;
            }
            if (maze[i][j] == 3) {
                endRow = i;
                endCol = j;
            }
        }
    }
    fclose(fp);
}

// function to check if given cell is valid
int isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= rows || y >= cols) {
        return 0;
    }
    if (visited[x][y] == 1 || maze[x][y] == 1) {
        return 0;
    }
    return 1;
}

// function to find best path from start to end
int findPath(int x, int y, int steps) {
    if (x == endRow && y == endCol) {  // reached end
        bestPath[steps] = 0;
        return steps;
    }
    visited[x][y] = 1;
    int best = MAX_SIZE;  // initialize best to a large value
    for (int i = 0; i < 4; i++) {  // try all directions
        int nx = x + dx[i];  // move in x-axis
        int ny = y + dy[i];  // move in y-axis
        if (isValid(nx, ny)) {
            int res = findPath(nx, ny, steps+1);
            if (res < best) {  // found shorter path
                best = res;
                bestPath[steps] = i;
            }
        }
    }
    visited[x][y] = 0;
    return best;
}

// function to print best path
void printPath(int steps) {
    printf("Best path from start to end:\n");
    int x = startRow, y = startCol;
    for (int i = 0; i < steps; i++) {
        printf("(%d,%d) -> ", x, y);
        int dir = bestPath[i];
        x += dx[dir];
        y += dy[dir];
    }
    printf("(%d,%d)\n", x, y);  // print end position
}

int main() {
    memset(visited, 0, sizeof visited);  // initialize visited array to zero
    readMaze("maze.txt");  // read maze from file
    int steps = findPath(startRow, startCol, 0);  // find best path from start to end
    printPath(steps);  // print best path
    return 0;
}