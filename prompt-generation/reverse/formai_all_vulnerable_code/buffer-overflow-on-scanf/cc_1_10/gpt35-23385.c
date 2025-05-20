//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 100

int adjMatrix[MAXIMUM][MAXIMUM]; // adjacency matrix to hold the graph
int visited[MAXIMUM]; // array to hold visited nodes
int path[MAXIMUM]; // array to hold the path
int path_index = 0; // variable to keep track of the path index

// DFS traversal of the graph
void DFS(int start, int end)
{
    visited[start] = 1; // mark the current node as visited
    path[path_index++] = start; // add the current node to the path

    // if the destination is found, print the path and return
    if (start == end)
    {
        printf("Path: ");
        for (int i = 0; i < path_index; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");

        return;
    }

    // consider all adjacent nodes of the current node
    for (int i = 0; i < MAXIMUM; i++)
    {
        if (adjMatrix[start][i] == 1 && visited[i] == 0) // if the node is adjacent and not visited
        {
            DFS(i, end); // recursively call the function for the adjacent node
        }
    }

    // if destination is not found, remove the current node from the path and mark as unvisited
    path_index--;
    visited[start] = 0;
}

int main()
{
    int n; // number of nodes in the graph
    int m; // number of edges in the graph

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // initialize the adjacency matrix with 0 to denote no edges
    for (int i = 0; i < MAXIMUM; i++)
    {
        for (int j = 0; j < MAXIMUM; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    // take input for the graph
    printf("Enter the graph:\n"); 
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // since graph is undirected
    }

    int start, end; // variables to hold the starting and ending node for the pathfinding
    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    // call the DFS function to find the path
    DFS(start, end);

    return 0;
}