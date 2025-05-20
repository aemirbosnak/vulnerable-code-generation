//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int colors[MAX];
int numNodes;

void colorGraph(int node)
{
    //check the previous colored nodes and skip if adjacent
    int usedColors[MAX] = {0};
    for (int i = 0; i < node; i++)
    {
        if (graph[node][i])
        {
            usedColors[colors[i]] = 1;
        }
    }
    //color the node with the first available color
    for (int j = 1; j <= numNodes; j++)
    {
        if (!usedColors[j])
        {
            colors[node] = j;
            break;
        }
    }
}

void printColors()
{
    printf("\nColors assigned to nodes:");
    for (int i = 0; i < numNodes; i++)
    {
        printf("\nNode %d: Color %d", i+1, colors[i]);
    }
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix for the graph:\n");

    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n");

    //Start coloring the graph
    for (int i = 0; i < numNodes; i++)
    {
        colorGraph(i);
    }

    //Display the final colors assigned to each node
    printColors();
    return 0;
}