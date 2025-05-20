//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

int adjMatrix[MAX_VERTICES][MAX_VERTICES]; //Adjacency Matrix
int visited[MAX_VERTICES]; //Mark the visited vertices

//Function to add an edge between two vertices of the graph
void addEdge(int v1, int v2)
{
    adjMatrix[v1][v2] = 1;
    adjMatrix[v2][v1] = 1;
}

//Function to print the adjacency matrix
void printAdjMatrix(int n)
{
    printf("\nThe Adjacency Matrix is : \n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
}

//Function for a Depth First Search traversal of the graph
void dfs(int vertex)
{
    visited[vertex] = 1;
    printf("%d ",vertex);

    for(int i=0; i<MAX_VERTICES; i++)
    {
        if(adjMatrix[vertex][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int n, v1, v2;

    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);

    printf("Enter the edges of the graph (-1 -1 to exit loop) : \n");

    while(1)
    {
        scanf("%d%d",&v1,&v2);
        if(v1 == -1 && v2 == -1)
        {
            break;
        }
        else
        {
            addEdge(v1, v2);
        }
    }

    printAdjMatrix(n);

    printf("\nDFS Traversal of the graph is : ");
    dfs(0);

    return 0;
}