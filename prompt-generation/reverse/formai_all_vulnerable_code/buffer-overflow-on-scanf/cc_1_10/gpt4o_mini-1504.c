//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 10

void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int dist[], int prev[], int nodes) {
    int visited[MAX_NODES] = {0};
    
    for (int i = 0; i < nodes; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < nodes; count++) {
        int min_distance = INT_MAX;
        int u = -1;
        
        for (int v = 0; v < nodes; v++) {
            if (!visited[v] && dist[v] < min_distance) {
                min_distance = dist[v];
                u = v;
            }
        }
        
        if (u == -1) {
            break; // All reachable nodes are visited
        }
        
        visited[u] = 1;
        
        for (int v = 0; v < nodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

void printPath(int prev[], int j) {
    if (j == -1) {
        return;
    }
    printPath(prev, prev[j]);
    printf("%d ", j);
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int nodes, edges, src;
    int dist[MAX_NODES], prev[MAX_NODES];

    printf("Enter the number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &nodes);
    
    if (nodes > MAX_NODES) {
        printf("Exceeded maximum nodes limit!\n");
        return 1;
    }

    // Initialize the graph
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0; // No edges
        }
    }
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter each edge (u v weight):\n");
    
    for (int e = 0; e < edges; e++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        
        if (u < nodes && v < nodes) {
            graph[u][v] = weight; // Directed graph
            graph[v][u] = weight; // If undirected, uncomment this line
        }
    }
    
    printf("Enter the source node: ");
    scanf("%d", &src);
    
    if (src < 0 || src >= nodes) {
        printf("Invalid source node!\n");
        return 1;
    }
    
    dijkstra(graph, src, dist, prev, nodes);
    
    printf("Node\tDistance from Source\tPath\n");
    for (int i = 0; i < nodes; i++) {
        printf("%d\t%d\t\t\t", i, dist[i]);
        printPath(prev, i);
        printf("\n");
    }
    
    return 0;
}