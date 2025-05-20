//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include<stdio.h>
#define MAX 10

void graph(int arr[MAX][MAX],int);
void drawHorizontalLine();
void drawVerticalLine();

int main()
{
    int arr[MAX][MAX],i,j,n;
    printf("\nEnter the number of vertices in the graph:\n");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nGraph Representation:\n\n");
    graph(arr,n);

    return 0;
}

void graph(int arr[MAX][MAX], int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        drawHorizontalLine();
        printf("|");
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                printf(" * |");
            }
            else
            {
                printf("   |");
            }
        }
        printf("\n");
    }
    drawHorizontalLine();
}

void drawHorizontalLine()
{
    int i;
    printf("  ");
    for(i=0;i<MAX*(4)+1;i++)
    {
        printf("-");
    }
    printf("\n");
}