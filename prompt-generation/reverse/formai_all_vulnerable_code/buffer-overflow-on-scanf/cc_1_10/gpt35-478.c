//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 50

//Function to print the current grid state
void printGrid(int grid[MAX_SIZE][MAX_SIZE], int size)
{
    printf("\nCurrent Grid State:\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

//Function to check if all elements of the grid are connected
int allConnected(int grid[MAX_SIZE][MAX_SIZE], int size)
{
    int connected=1;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(grid[i][j]==0)
            {
                connected=0;
                break;
            }
        }
        if(connected==0)
        break;
    }

    return connected;
}

//Function for the percolation simulation
void percolate(int grid[MAX_SIZE][MAX_SIZE], int size, float prob)
{
    //Populating the Grid
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if((rand()%100) < (prob*100))
            grid[i][j]=1;
            else
            grid[i][j]=0;
        }
    }

    //Percolation Process
    int connectedCount=0;

    while(1)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(grid[i][j]>0)
                {
                    //Checking Upward Element
                    if(i>0 && grid[i-1][j]==0)
                    grid[i-1][j]=2;

                    //Checking Downward Element
                    if(i<size-1 && grid[i+1][j]==0)
                    grid[i+1][j]=2;

                    //Checking Left Element
                    if(j>0 && grid[i][j-1]==0)
                    grid[i][j-1]=2;

                    //Checking Right Element
                    if(j<size-1 && grid[i][j+1]==0)
                    grid[i][j+1]=2;
                }
            }
        }

        //Replacing 2 with 1
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(grid[i][j]==2)
                grid[i][j]=1;
            }
        }

        //Checking if all elements are connected
        if(allConnected(grid,size))
        break;

        //Resetting 1 to 0
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(grid[i][j]==1)
                grid[i][j]=0;
            }
        }

        connectedCount++;
    }

    //Printing the Final State
    printf("\nFinal Grid State:\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of Iterations for Percolation: %d",connectedCount);
}

//Main Function
int main()
{
    int size;
    float prob;
    int grid[MAX_SIZE][MAX_SIZE];

    printf("Enter the Grid Size: ");
    scanf("%d",&size);

    printf("\nEnter the Probability of Percolation: ");
    scanf("%f",&prob);

    srand(time(NULL));

    percolate(grid,size,prob);

    return 0;
}