//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000   // maximum number of vertices

int adjacent[MAXV][MAXV];    // adjacency matrix
int nvertices;              // number of vertices
int colors[MAXV];           // array to hold the solution
int ncolors = 0;            // number of colors used

// function prototypes
void read_graph();
void color_graph(int);
int is_safe(int, int);

int main()
{
    read_graph();
    color_graph(0);

    // print the solution
    printf("Colors used: %d\n", ncolors);
    for (int i = 0; i < nvertices; i++)
        printf("Node %d: Color %d\n", i, colors[i]);

    return 0;
}

void read_graph()
{
    int nedges;

    printf("Enter the number of vertices: ");
    scanf("%d", &nvertices);

    printf("Enter the number of edges: ");
    scanf("%d", &nedges);

    // initialize the adjacency matrix
    for (int i = 0; i < nvertices; i++)
        for (int j = 0; j < nvertices; j++)
            adjacent[i][j] = 0;

    // read the edges
    printf("Enter the edges (u v):\n");
    int u, v;
    for (int i = 0; i < nedges; i++)
    {
        scanf("%d %d", &u, &v);
        adjacent[u][v] = 1;
        adjacent[v][u] = 1;     // graph is undirected
    }
}

void color_graph(int node)
{
    // base case: all nodes have been colored
    if (node == nvertices)
        return;

    // try all colors for this node
    for (int i = 1; i <= nvertices; i++)
    {
        if (is_safe(node, i))
        {
            colors[node] = i;
            color_graph(node + 1);

            // if a color was found that works for the remaining nodes, return
            if (node + 1 == nvertices)
                return;
        }
    }
}

int is_safe(int node, int color)
{
    // check if any adjacent nodes have the same color
    for (int i = 0; i < nvertices; i++)
    {
        if (adjacent[node][i] && colors[i] == color)
            return 0;
    }

    // color is safe
    if (color > ncolors)
        ncolors = color;

    return 1;
}