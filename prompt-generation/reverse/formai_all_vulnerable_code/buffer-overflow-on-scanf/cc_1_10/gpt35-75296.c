//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100   // maximum number of nodes allowed in the graph
#define MAX_DEGREE 10   // maximum degree (number of adjacent nodes) allowed for each node

int graph[MAX_NODES][MAX_DEGREE];   // adjacency list representation of the graph
int color[MAX_NODES];               // stores the color assigned to each node
int num_nodes;                      // number of nodes in the graph
int num_colors;                     // number of colors available

// function to check if a color can be assigned to a node
int isSafe(int node, int c)
{
    for(int i = 0; i < MAX_DEGREE; i++)
    {
        if(graph[node][i] != -1)
        {
            if(color[graph[node][i]] == c)
                return 0;   // color already assigned to adjacent node, not safe
        }
    }
    return 1;   // safe color
}

// function to assign color to a node
int colorNode(int node)
{
    for(int c = 0; c < num_colors; c++)
    {
        if(isSafe(node, c))
        {
            color[node] = c;
            return 1;   // color assigned
        }
    }
    return 0;   // no color could be assigned
}

// function to print the color assigned to each node
void printColors()
{
    printf("Colors assigned to nodes:\n");
    for(int i = 0; i < num_nodes; i++)
        printf("Node %d: Color %d\n", i, color[i]);
}

// main function to execute the graph coloring problem
int main()
{
    // input the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    printf("Enter the adjacency list representation of the graph:\n");
    for(int i = 0; i < num_nodes; i++)
    {
        printf("Node %d: ", i);
        for(int j = 0; j < MAX_DEGREE; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == -1)
                break;
        }
    }
    
    // initialize colors assigned to each node to -1 (no color assigned)
    memset(color, -1, sizeof(color));
    
    // color each node
    for(int i = 0; i < num_nodes; i++)
    {
        if(colorNode(i) == 0)
        {
            printf("Cannot color the graph with %d colors.\n", num_colors);
            exit(0);
        }
    }
    
    // print the colors assigned to each node
    printColors();
    
    return 0;
}