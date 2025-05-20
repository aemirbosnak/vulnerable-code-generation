//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include<stdio.h>

#define MAX 100

int adj_matrix[MAX][MAX], color[MAX];
int vertices, edges;

int getAdjacentColoredVertex(int vertex, int color[])
{
    int i;
    for(i = 0; i < vertices; i++)
        if(adj_matrix[vertex][i] && color[i] != -1)
            return color[i];
    return -1;
}

int getUnusedColor(int color[])
{
    int i, col;
    int used[MAX] = {0}; 
    for(i = 0; i < vertices; i++)
        if(color[i] != -1)
            used[color[i]] = 1;
    for(i = 0; i < vertices; i++)
        if(!used[i])
            return i;
}

void graphColoring(int vertex, int color[])
{
    int i, c;
    if(vertex == vertices)
        return;

    c = getAdjacentColoredVertex(vertex, color);
    if(c != -1)
        color[vertex] = getUnusedColor(color);
    else
        color[vertex] = c;

    graphColoring(vertex+1, color);
}

int main()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            adj_matrix[i][j] = 0;

    printf("Enter the edge matrix:\n");
    for(i = 0; i < edges; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        adj_matrix[v1][v2] = adj_matrix[v2][v1] = 1;
    }

    for(i = 0; i < vertices; i++)
        color[i] = -1;

    graphColoring(0, color);

    printf("The assigned colors are:\n");
    for(i = 0; i < vertices; i++)
        printf("Vertex[%d] = %d\n", i, color[i]);

    return 0;
}