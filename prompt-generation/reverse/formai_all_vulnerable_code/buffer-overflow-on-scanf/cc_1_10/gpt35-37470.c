//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 100
int graph[MAX_VERTEX][MAX_VERTEX], vertexColor[MAX_VERTEX], numVertices;

int isSafe(int v, int c)
{
    for(int i = 0; i < numVertices; i++)
    {
        if(graph[v][i] && vertexColor[i] == c)
            return 0;
    }
    return 1;
}

int GraphColoring(int v)
{
    if(v == numVertices)
        return 1;
    for(int c = 1; c <= numVertices; c++)
    {
        if(isSafe(v, c))
        {
            vertexColor[v] = c;
            if(GraphColoring(v+1))
                return 1;
            vertexColor[v] = 0;
        }
    }
    return 0;
}

void input()
{
    printf("Enter the number of vertices:\n");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void printSolution()
{
    printf("The vertex colorings are:\n");
    for(int i = 0; i < numVertices; i++)
    {
        printf("Vertex %d: Color %d\n", i+1, vertexColor[i]);
    }
}

int main()
{
    input();
    if(GraphColoring(0))
        printSolution();
    else
        printf("No solution exists.\n");

    return 0;
}