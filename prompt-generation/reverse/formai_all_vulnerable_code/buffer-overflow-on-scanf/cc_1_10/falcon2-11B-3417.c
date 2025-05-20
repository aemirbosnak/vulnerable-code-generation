//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_maze(int maze[][5], int rows, int cols) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void read_maze(int maze[][5], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            scanf("%d", &maze[i][j]);
        }
    }
}

void print_path(int path[][5], int rows, int cols) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int maze[5][5];
    int path[5][5];

    read_maze(maze, rows, cols);
    print_maze(maze, rows, cols);

    int start = 0;
    int goal = 4;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(maze[i][j] == 1){
                path[i][j] = 1;
            }
            else{
                path[i][j] = 0;
            }
        }
    }

    while(start!= goal){
        if(path[start][0] == 1){
            start = start + 1;
        }
        else if(path[start][0] == 0){
            start = start - 1;
        }

        if(path[start][1] == 1){
            start = start + 1;
        }
        else if(path[start][1] == 0){
            start = start - 1;
        }

        if(path[start][2] == 1){
            start = start + 1;
        }
        else if(path[start][2] == 0){
            start = start - 1;
        }

        if(path[start][3] == 1){
            start = start + 1;
        }
        else if(path[start][3] == 0){
            start = start - 1;
        }

        if(path[start][4] == 1){
            start = start + 1;
        }
        else if(path[start][4] == 0){
            start = start - 1;
        }
    }

    print_path(path, rows, cols);
    printf("\n");

    return 0;
}