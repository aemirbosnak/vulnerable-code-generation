//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 30

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int V;
int E;

//check if two nodes have the same color
int isValid(int node, int color)
{
    for (int i = 0; i < V; i++)
        if (graph[node][i] && color == colors[i])
            return 0;
    return 1;
}

//Color adjacent nodes recursively
int colorNodes(int node)
{
    if (node == V)
        return 1;

    //assign a color to current node
    for (int c = 1; c <= V; c++)   
    {
        if (isValid(node, c))   
        {
            colors[node] = c;

            //recursive call to color next node
            if (colorNodes(node + 1))
                return 1;

            //backtrack and change color for current node
            colors[node] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("\nPost-Apocalyptic Graph Coloring Problem\n");
    printf("=======================================\n");

    printf("\nEnter the number of nodes and edges:\n");
    scanf("%d %d", &V, &E);

    int u, v;
    for (int i = 0; i < E; i++)
    {
        printf("\nEnter the edge - (%d, %d): ", i + 1, E);
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    //color nodes recursively
    if (colorNodes(0))
    {
        printf("\nColors for each node:\n");
        for (int i = 0; i < V; i++)
            printf("Node %d: %d\n", i, colors[i]);
    }
    else
        printf("\nSolution does not exist for the graph.");

    return 0;
}