//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include<stdio.h>
#define MAX_SIZE 100

int maze[MAX_SIZE][MAX_SIZE];
int path[MAX_SIZE][MAX_SIZE] = {0};  // 0 means not visited yet
int row, col;
int solution_found = 0;

void findPath(int cur_row, int cur_col){
    if(cur_row==row-1 && cur_col==col-1){
        solution_found = 1;
        path[cur_row][cur_col] = 1;  // mark the final cell as visited
        printf("Path Found:\n");
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
        return;
    }
    path[cur_row][cur_col] = 1;
    // check right cell
    if(cur_col+1<col && maze[cur_row][cur_col+1]!=1 && path[cur_row][cur_col+1]==0){
        findPath(cur_row, cur_col+1);
    }
    // check down cell
    if(!solution_found && cur_row+1<row && maze[cur_row+1][cur_col]!=1 && path[cur_row+1][cur_col]==0){
        findPath(cur_row+1, cur_col);
    }
    // check left cell
    if(!solution_found && cur_col-1>=0 && maze[cur_row][cur_col-1]!=1 && path[cur_row][cur_col-1]==0){
        findPath(cur_row, cur_col-1);
    }
    // check up cell
    if(!solution_found && cur_row-1>=0 && maze[cur_row-1][cur_col]!=1 && path[cur_row-1][cur_col]==0){
        findPath(cur_row-1, cur_col);
    }
    if(!solution_found){
        path[cur_row][cur_col] = 0;  // backtrack if no solution is found
    }
}

int main(){
    printf("Enter the number of rows and columns of the maze:\n");
    scanf("%d %d", &row, &col);
    printf("Enter the cells of the maze:\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    findPath(0, 0);
    if(!solution_found){
        printf("No solution found.");
    }
    return 0;
}