//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int from;
    int to;
} Edge;

Edge edges[MAX_EDGES];
int numEdges = 0;

void addEdge(int from, int to) {
    edges[numEdges].from = from;
    edges[numEdges].to = to;
    numEdges++;
}

void dfs(int node, int visited[MAX_NODES], int adjacencyMatrix[MAX_NODES][MAX_NODES], int numNodes) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < numNodes; i++) {
        if (visited[i] == 0 && adjacencyMatrix[node][i] == 1) {
            dfs(i, visited, adjacencyMatrix, numNodes);
        }
    }
}

void printGraph(int adjacencyMatrix[MAX_NODES][MAX_NODES], int numNodes) {
    printf("Network Topology:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void mapTopology() {
    int numNodes, numConnections;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));

    printf("Enter the number of connections: ");
    scanf("%d", &numConnections);

    for (int i = 0; i < numConnections; i++) {
        int u, v;
        printf("Enter the edges (u,v): ");
        scanf("%d,%d", &u, &v);

        addEdge(u - 1, v - 1);
    }

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].from;
        int v = edges[i].to;

        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    printGraph(adjacencyMatrix, numNodes);

    printf("DFS traversal: ");
    int visited[MAX_NODES] = {0};
    dfs(0, visited, adjacencyMatrix, numNodes);
}

int main() {
    mapTopology();
    return 0;
}