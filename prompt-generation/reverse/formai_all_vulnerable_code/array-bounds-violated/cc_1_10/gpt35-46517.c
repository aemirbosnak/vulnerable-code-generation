//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int from;
    int to;
    int cost;
} Edge;

int nodes, edges;
Edge edge[MAX_EDGES];
int edgeCount[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];

void dfs(int u, int* visited)
{
    printf("%d ", u);
    visited[u] = 1;
    for (int v = 0; v < nodes; v++)
        if (edgeCount[u][v] && !visited[v])
            dfs(v, visited);
}

int find(int u)
{
    while (u != parent[u])
        u = parent[u];
    return u;
}

int main()
{
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter from, to and cost of edge %d: ", i + 1);
        scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].cost);
        edge[i].from--;
        edge[i].to--;
        edgeCount[edge[i].from][edge[i].to]++;
        edgeCount[edge[i].to][edge[i].from]++;
    }

    // Kruskal's Algorithm
    for (int i = 0; i < nodes; i++)
        parent[i] = i;

    Edge result[MAX_NODES];
    int resultCount = 0;

    for (int i = 0; i < edges; i++) {
        int u = edge[i].from;
        int v = edge[i].to;

        int parentU = find(u);
        int parentV = find(v);

        if (parentU != parentV) {
            result[resultCount++] = edge[i];
            parent[parentU] = parentV;
        }
    }

    // Print MST
    printf("\nMinimum Spanning Tree:\n");
    for (int i = 0; i < resultCount; i++) {
        printf("%d - %d : %d\n", result[i].from + 1, result[i].to + 1, result[i].cost);
    }

    // DFS Traversal
    printf("\nDFS traversal of the graph:\n");
    int visited[MAX_NODES] = { 0 };
    dfs(0, visited);
    printf("\n");

    return 0;
}