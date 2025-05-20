//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000

int board[MAX][MAX];
int count = 0;

void init()
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            board[i][j] = 0;
        }
    }
}

void percolate()
{
    int i,j,k,l,flag=0;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(board[i][j]==1)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag==1)
    {
        for(i=0;i<MAX;i++)
        {
            for(j=0;j<MAX;j++)
            {
                if(board[i][j]==1)
                {
                    board[i][j] = 0;
                    count++;
                }
            }
        }
    }
}

void display()
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(board[i][j]==1)
            {
                printf("\033[1;32m"); // Green color
                printf("*");
                printf("\033[0m"); // Reset color
            }
            else
            {
                printf("\033[1;31m"); // Red color
                printf(".");
                printf("\033[0m"); // Reset color
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int i,j,k,l;
    printf("Enter the number of drops: ");
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        l = rand()%MAX;
        j = rand()%MAX;
        while(board[l][j]==1)
        {
            l = rand()%MAX;
            j = rand()%MAX;
        }
        board[l][j] = 1;
    }
    init();
    while(count<k)
    {
        percolate();
    }
    display();
    printf("\nThe percolation process is complete.\n");
    return 0;
}