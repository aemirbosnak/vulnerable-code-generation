//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include<stdio.h>    
#include<string.h>    
#define ROW 10    
#define COL 10    
#define MAX 50    

int matrix[ROW][COL];    
int rows, cols;    
void createMaze();    
void printMaze();    
int solveMaze(int, int);    
int main(){    
    createMaze();    
    printf("\nMaze:\n");    
    printMaze();    
    printf("\nSolution:\n");    
    if(solveMaze(0,0))    
        printMaze();    
    else    
        printf("No possible solution\n");    
    return 0;    
}    
void createMaze(){    
    int i, j;    
    printf("Enter number of rows and columns\n");    
    scanf("%d %d",&rows,&cols);    
    printf("Enter maze:\n");    
    for(i=0;i<rows;i++){    
        for(j=0;j<cols;j++){    
            scanf("%d",&matrix[i][j]);    
        }    
    }    
}    
void printMaze(){    
    int i, j;    
    for(i=0;i<rows;i++){    
        for(j=0;j<cols;j++){    
            printf("%d ",matrix[i][j]);    
        }    
        printf("\n");    
    }    
}    
int solveMaze(int r, int c){    
    if(r==rows-1 && c==cols-1){    
        return 1;    //Reached the end of the maze        
    }    
    if(matrix[r][c]==1){    //If the cell is not a valid path(1 is not allowed)
        return 0;    
    }    
    if(r>=rows || c>=cols){    //If the cell is outside the maze
        return 0;    
    }    
    if(solveMaze(r+1,c)==1){    //Moving down    
        matrix[r][c]='*';    
        return 1;    
    }    
    if(solveMaze(r,c+1)==1){    //Moving right    
        matrix[r][c]='*';    
        return 1;    
    }    
    if(solveMaze(r-1,c)==1){    //Moving up    
        matrix[r][c]='*';    
        return 1;    
    }    
    if(solveMaze(r,c-1)==1){    //Moving left    
        matrix[r][c]='*';    
        return 1;    
    }    
    return 0;    
}