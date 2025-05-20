//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdbool.h>

#define V 4 //Total Number of vertices

bool isSafe(int v, bool graph[V][V], int color[V], int c)
{
    int i;
    for (i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoring(bool graph[V][V], int m, int color[V], int v)
{
    int c;
    if (v == V)
        return true;

    for (c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoring(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void printSolution(int color[V])
{
    int i;
    printf("Coloring vertices in following order:\n");
    for (i = 0; i < V; i++)
        printf("Vertex %d => Color %d\n", i+1, color[i]);
    printf("\n");
}

int main()
{
    bool graph[V][V] = { {0, 1, 1, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1},
                         {1, 0, 1, 0} };

    //Initialize all colors to 0
    int color[V] = {0};

    printf("Enter the number of colors (m) to color the graph: ");
    int m;
    scanf("%d", &m);

    if (graphColoring(graph, m, color, 0) == false)
        printf("Solution does not exist.\n");
    else
        printSolution(color);

    return 0;
}