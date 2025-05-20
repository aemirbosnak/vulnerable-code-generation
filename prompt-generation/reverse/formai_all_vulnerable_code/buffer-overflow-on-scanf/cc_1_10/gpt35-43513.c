//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

//global variables
int num_rows, num_cols;
int flag[MAX][MAX];
char maze[MAX][MAX];

//function to initialize the maze
void initialize_maze()
{
    int i, j;
    for(i=0; i<num_rows; i++){
        for(j=0; j<num_cols; j++){
            if(i==0 || i==num_rows-1 || j==0 || j==num_cols-1){
                //creating walls around the maze
                maze[i][j] = '#';
                flag[i][j] = 1;
            }
            else{
                maze[i][j] = ' ';
                flag[i][j] = 0;
            }
        }
    }
}

//function to print the maze
void print_maze()
{
    int i, j;
    for(i=0; i<num_rows; i++){
        for(j=0; j<num_cols; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

//function to check if given cell is a valid cell or not
int isValid(int x, int y)
{
    if(x<0 || y<0 || x>=num_rows || y>=num_cols){
        return 0;
    }
    if(maze[x][y] == '#' || flag[x][y] == 1){
        return 0;
    }
    return 1;
}

//function to solve the maze using DFS
int solve_maze_DFS(int x, int y)
{
    if(x==num_rows-2 && y==num_cols-2){
        //reached the destination
        return 1;
    }
    flag[x][y] = 1;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int i, next_x, next_y;
    for(i=0; i<4; i++){
        next_x = x + dx[i];
        next_y = y + dy[i];
        if(isValid(next_x, next_y)){
            if(solve_maze_DFS(next_x, next_y)){
                //marking the path with '*'
                maze[next_x][next_y] = '*';
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    printf("Enter number of rows and columns of the maze (both should be greater than 3 and less than 15):\n");
    scanf("%d %d", &num_rows, &num_cols);
    if(num_rows<=3 || num_cols<=3 || num_rows>=15 || num_cols>=15){
        printf("Invalid input. Please try again.\n");
        exit(0);
    }
    printf("Maze of size %d X %d:\n", num_rows, num_cols);
    initialize_maze();
    print_maze();
    printf("Finding the path to the destination...\n");
    if(solve_maze_DFS(1, 1)){
        printf("Path found!\n");
        print_maze();
    }
    else{
        printf("Path not found!\n");
        print_maze();
    }
    return 0;
}