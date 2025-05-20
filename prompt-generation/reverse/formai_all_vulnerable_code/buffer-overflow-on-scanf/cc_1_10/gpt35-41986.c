//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include<stdio.h>
#define MAX 20

int maze[MAX][MAX];
int sol[MAX][MAX];
int rows,cols;

int isSafe(int i,int j)
{
    return (i>=0 && i<rows && j>=0 && j<cols && maze[i][j]==1);
}

void printSolution()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",sol[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int x,int y)
{
    if(x==rows-1 && y==cols-1 && maze[x][y]==1)
    {
        sol[x][y]=1;
        return 1;
    }

    if(isSafe(x,y)==1)
    {
        sol[x][y]=1;

        if(solveMaze(x+1,y)==1)
            return 1;
            
        if(solveMaze(x,y+1)==1)
            return 1;

        sol[x][y]=0;
    }

    return 0;
}

int main()
{
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&rows,&cols);

    printf("Enter the maze respectively (1 for path and 0 for block): ");

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }

    if(solveMaze(0,0)==1)
    {
        printf("Solution found!\n\n");
        printSolution();
    }
    else
    {
        printf("No solution found.");
    }

    return 0;
}