//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 10

// Function to find the node with the minimum distance value
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm for finding the shortest path
void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int n) {
    int dist[MAX_NODES]; // Output array for the shortest distances
    int sptSet[MAX_NODES]; // Shortest Path Tree Set
   
    // Initialize all distances as infinite and sptSet as 0
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
   
    // Distance from source to itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1; // Mark the picked vertex

        // Update dist value of the neighboring vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && 
                dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex \t Distance from Source Node (%d)\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Main function to run the program
int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int sourceNode;
    printf("Enter the source node (0 to %d): ", MAX_NODES - 1);
    scanf("%d", &sourceNode);
    
    if (sourceNode < 0 || sourceNode >= MAX_NODES) {
        printf("Invalid node number! Exiting...\n");
        return -1;
    }

    dijkstra(graph, sourceNode, MAX_NODES);
    return 0;
}