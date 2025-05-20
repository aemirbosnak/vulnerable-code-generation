//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int maze[10][10], path[10][10];             // Global 2D arrays to store maze and path information
int i,j,n;

void printMaze()
{
    printf("Maze Layout:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printPath()
{
    printf("Maze Solution:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && path[x][y]==0)      // Check if the position is within maze and is a valid path
        return 1;
    return 0;
}

int solveMaze(int x, int y)
{
    if(x==n-1 && y==n-1){               // Reached the end point, found solution
        path[x][y] = 1;
        return 1;
    }

    if(isValid(x,y)==1){                // Current position is valid to move ahead
        path[x][y] = 1;

        if(solveMaze(x+1,y)==1)         // Move down
            return 1;
        if(solveMaze(x,y+1)==1)         // Move right
            return 1;
        if(solveMaze(x-1,y)==1)         // Move up
            return 1;
        if(solveMaze(x,y-1)==1)         // Move left
            return 1;

        path[x][y] = 0;                 // Backtracking, remove current position from solution path
        return 0;
    }

    return 0;
}

int main()
{
    printf("Enter the number of rows/columns for the maze: ");
    scanf("%d",&n);

    printf("\nEnter the Maze Layout:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&maze[i][j]);            // Input maze layout row by row
            path[i][j] = 0;                     // Initializing path as 0 for all positions
        }
    }

    printMaze();

    if(solveMaze(0,0)==1)                       // Starting at origin (0,0) position to solve maze
        printPath();
    else
        printf("\nNo solution found!");

    return 0;
}