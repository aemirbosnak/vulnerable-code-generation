//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES] = { {0} };
int nVertices;
int nColors;
int color[MAX_VERTICES] = {0};

void initGraph(int vertices)
{
    nVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int v, int w)
{
    graph[v][w] = 1;
    graph[w][v] = 1;
}

int isSafe(int v, int c, int color[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
        {
            return 0;
        }
    }
    return 1;
}

void colorGraph(int startVertex, int colorIndex)
{
    color[startVertex] = colorIndex;

    for (int i = 0; i < nVertices; i++)
    {
        if (graph[startVertex][i] == 1 && color[i] == 0 && isSafe(i, colorIndex, color, nVertices))
        {
            colorGraph(i, colorIndex);
        }
    }
}

int main()
{
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initGraph(vertices);

    for (int i = 0; i < edges; i++)
    {
        int v, w;
        printf("Enter the vertices for edge %d: ", i + 1);
        scanf("%d %d", &v, &w);
        addEdge(v, w);
    }

    srand(time(NULL));
    int colors[MAX_COLORS] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < nVertices; i++)
    {
        color[i] = 0;
    }
    for (int i = 0; i < nColors; i++)
    {
        int startVertex = rand() % nVertices;
        while (color[startVertex]!= 0)
        {
            startVertex = rand() % nVertices;
        }
        colorGraph(startVertex, colors[i]);
    }

    printf("The graph is colored using %d colors.\n", nColors);

    return 0;
}