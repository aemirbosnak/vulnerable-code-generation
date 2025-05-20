//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int grid[N][N];
int count = 0;
int x, y, i, j, k, l;

void create_grid(int n)
{
    int i, j;
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            grid[i][j] = rand()%2;
        }
    }
}

void display_grid(int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(grid[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void percolate(int n)
{
    int i, j, k, l;
    for(k=0; k<n; k++)
    {
        for(l=0; l<n; l++)
        {
            if(grid[k][l] == 1)
            {
                count++;
                grid[k][l] = 0;
                i = k-1;
                j = l-1;
                while(i>=0 && j>=0 && grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    i--;
                    j--;
                }
                i = k+1;
                j = l+1;
                while(i<n && j<n && grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    i++;
                    j++;
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the grid: ");
    scanf("%d", &n);
    create_grid(n);
    display_grid(n);
    percolate(n);
    printf("\nTotal number of clusters: %d", count);
    return 0;
}