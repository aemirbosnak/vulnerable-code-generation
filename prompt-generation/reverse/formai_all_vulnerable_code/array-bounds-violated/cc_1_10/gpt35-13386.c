//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
// Post-Apocalyptic Graph Coloring Problem
// In this world, nodes represent surviving communities and edges represent alliances
// Due to limited resources, each community must choose a unique color to identify themselves
// But neighboring communities cannot have the same color to avoid confusion and conflict

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 500

int n, m; // number of nodes and edges
int color[MAX_NODES]; // to store the color of each node
int adj[MAX_NODES][MAX_NODES]; // adjacency matrix to represent edges

// function to assign color to each node
void graph_coloring(int node)
{
    int i, j;
    bool available[MAX_NODES]; // to keep track of available colors
    
    // initially, all colors are available
    for(i=0; i<n; i++)
        available[i] = true;
        
    // loop over all adjacent nodes and mark their colors as not available
    for(i=0; i<n; i++)
    {
        if(adj[node][i] == 1 && color[i] != -1)
        {
            available[color[i]] = false;
        }
    }
    
    // assign the first available color
    for(i=0; i<n; i++)
    {
        if(available[i] == true)
        {
            color[node] = i;
            break;
        }
    }
}

int main()
{
    int i, j;
    
    // input number of nodes and edges
    printf("Enter the number of nodes (<= %d): ", MAX_NODES);
    scanf("%d", &n);
    printf("Enter the number of edges (<= %d): ", n*(n-1)/2);
    scanf("%d", &m);
    
    // initialize adjacency matrix to zero
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            adj[i][j] = 0;
        }
    }
    
    // input edges
    printf("Enter the edges as pairs (u, v):\n");
    for(i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // initialize color of each node to -1 (undefined)
    for(i=0; i<n; i++)
    {
        color[i] = -1;
    }
    
    // assign color to each node
    for(i=0; i<n; i++)
    {
        graph_coloring(i);
    }
    
    // print the result
    printf("\nCommunity\tColor\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t\t%d\n", i, color[i]);
    }
    
    return 0;
}