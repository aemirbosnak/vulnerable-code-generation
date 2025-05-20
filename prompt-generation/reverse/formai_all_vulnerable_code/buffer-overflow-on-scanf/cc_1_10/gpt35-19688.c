//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random maze
void generateMaze(int maze[][100], int rows, int cols){
    srand(time(0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            maze[i][j] = rand()%2;
        }
    }
}

//Function to display maze
void displayMaze(int maze[][100], int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

//Function to find the starting point in the maze
void findStartPoint(int maze[][100], int rows, int cols, int *x, int *y){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(maze[i][j]==1){
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

//Function to find the path in the maze
void findPath(int maze[][100], int x, int y, int rows, int cols){
    if(x<0 || x>=rows || y<0 || y>=cols || maze[x][y]==0){
        return;
    }
    if(maze[x][y]==2){
        printf("Path found!\n");
        return;
    }
    maze[x][y] = 0;
    printf("(%d, %d)\n", x, y);
    findPath(maze, x+1, y, rows, cols); //Check down
    findPath(maze, x-1, y, rows, cols);// Check up
    findPath(maze, x, y+1, rows, cols); //Check right
    findPath(maze, x, y-1, rows, cols); //Check left
}

int main(){
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int maze[100][100];
    generateMaze(maze, rows, cols);
    displayMaze(maze, rows, cols);
    int startX, startY;
    findStartPoint(maze, rows, cols, &startX, &startY);
    printf("Starting point: (%d, %d)\n", startX, startY);
    findPath(maze, startX, startY, rows, cols);
    return 0;
}