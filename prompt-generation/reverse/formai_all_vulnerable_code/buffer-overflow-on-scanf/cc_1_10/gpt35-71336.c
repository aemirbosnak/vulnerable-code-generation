//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROW 11
#define COL 11

char maze[ROW][COL] = {
    "# # # # # # # # # # #",
    "# . . . # . . . . . #",
    ". # # . # . # # # . .",
    "# # # . # . . . # # #",
    "# . . . . # # . . . #",
    "# # # # . # # . # # #",
    "# . . # . . . . # . .",
    "# # . # . # # # # # #",
    "# . . . . . . . . . #",
    "# # # # # # # # . # #",
    "# . . . . . . . . # #"
};

bool visited[ROW][COL];
int startRow, startCol, endRow, endCol;

void printMaze() {
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValid(int row, int col) {
    if(row<0 || row>=ROW || col<0 || col>=COL) {
        return false;
    }
    if(maze[row][col] == '#' || visited[row][col]) {
        return false;
    }
    return true;
}

bool recursiveSolve(int row, int col) {
    visited[row][col] = true;
    if(row == endRow && col == endCol) {
        return true;
    }
    if(isValid(row-1,col) && recursiveSolve(row-1,col)) {
        maze[row-1][col] = 'X';
        return true;
    }
    if(isValid(row+1,col) && recursiveSolve(row+1,col)) {
        maze[row+1][col] = 'X';
        return true;
    }
    if(isValid(row,col-1) && recursiveSolve(row,col-1)) {
        maze[row][col-1] = 'X';
        return true;
    }
    if(isValid(row,col+1) && recursiveSolve(row,col+1)) {
        maze[row][col+1] = 'X';
        return true;
    }
    return false;
}

void solveMaze() {
    printf("Enter starting coordinates (x,y)\n");
    scanf("%d%d",&startCol,&startRow);
    printf("Enter ending coordinates (x,y)\n");
    scanf("%d%d",&endCol,&endRow);
    if(recursiveSolve(startRow,startCol)) {
        printf("Path Found!\n");
    }
    else {
        printf("Path Not Found!\n");
    }
    printMaze();
}

int main() {
    solveMaze();
    return 0;
}