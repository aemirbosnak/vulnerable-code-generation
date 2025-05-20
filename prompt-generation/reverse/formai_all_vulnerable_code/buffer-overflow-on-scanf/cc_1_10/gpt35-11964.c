//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 20
#define MAX_COLS 20

int maze[MAX_ROWS][MAX_COLS]; // 2D array represeting the maze
int visited[MAX_ROWS][MAX_COLS]; // 2D array to keep track of visited cells
int path[MAX_ROWS*MAX_COLS][2]; // 2D array to store the path of the route
int path_length = 0; // variable to store the length of the path
int valid_route_found = 0; // flag to check if a valid route is found
int start_row, start_col; // variables to store the starting cell coordinates
int end_row, end_col; // variables to store the ending cell coordinates

// Function to print the maze
void print_maze(int rows, int cols){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a cell is valid to visit
int is_valid_cell(int row, int col, int rows, int cols){
    if(row>=0 && row<rows && col>=0 && col<cols && maze[row][col]==1 && visited[row][col]==0){
        return 1;
    }
    return 0;
}

// Function to find the route through the maze using DFS
void find_route(int row, int col, int rows, int cols){
    visited[row][col] = 1;
    path[path_length][0] = row;
    path[path_length][1] = col;
    path_length++;
    if(row==end_row && col==end_col){
        valid_route_found = 1;
        return;
    }
    if(is_valid_cell(row-1,col,rows,cols)){
        find_route(row-1,col,rows,cols);
        if(valid_route_found){
            return;
        }
    }
    if(is_valid_cell(row+1,col,rows,cols)){
        find_route(row+1,col,rows,cols);
        if(valid_route_found){
            return;
        }
    }
    if(is_valid_cell(row,col-1,rows,cols)){
        find_route(row,col-1,rows,cols);
        if(valid_route_found){
            return;
        }
    }
    if(is_valid_cell(row,col+1,rows,cols)){
        find_route(row,col+1,rows,cols);
        if(valid_route_found){
            return;
        }
    }
    // backtrack if there is no valid route from this cell
    path_length--;
    visited[row][col] = 0;
}

int main(){
    int rows,cols;
    printf("Enter the number of rows and columns of the maze (max=20)\n");
    scanf("%d%d",&rows,&cols);
    printf("Enter the maze (1=valid path, 0=blocked path):\n");
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    printf("Enter the starting cell coordinates:\n");
    scanf("%d%d",&start_row,&start_col);
    printf("Enter the ending cell coordinates:\n");
    scanf("%d%d",&end_row,&end_col);
    // check if the starting and ending cells are valid
    if(maze[start_row][start_col]!=1 || maze[end_row][end_col]!=1){
        printf("Invalid starting or ending cell\n");
        exit(0);
    }
    // find the route through the maze
    find_route(start_row,start_col,rows,cols);
    if(valid_route_found){
        printf("Route found!\n");
        printf("The path is:\n");
        for(i=0;i<path_length;i++){
            printf("(%d,%d)\n",path[i][0],path[i][1]);
        }
    }
    else{
        printf("No route found\n");
    }
    return 0;
}