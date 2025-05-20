//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>

// Define constants for maximum possible edge weight and maximum number of edges
#define MAX_WEIGHT 100000
#define MAX_EDGES 100000

int main() {

    // Declare variables
    int n; // Number of nodes
    int m; // Number of edges
    int graph[MAX_EDGES][2]; // Adjacency list representation of graph

    // Read input from user
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &graph[i][0]); // Source node
        scanf("%d", &graph[i][1]); // Destination node
    }

    // Sort edges based on their weights in non-decreasing order
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (graph[j][0] > graph[j+1][0]) {
                int temp = graph[j][0];
                graph[j][0] = graph[j+1][0];
                graph[j+1][0] = temp;
                temp = graph[j][1];
                graph[j][1] = graph[j+1][1];
                graph[j+1][1] = temp;
            }
        }
    }

    // Initialize array to keep track of visited nodes
    int visited[MAX_EDGES] = {0};

    // Find minimum spanning tree using Kruskal's algorithm
    int edgeCount = 0;
    for (int i=0; i<n-1; i++) {
        if (!visited[i]) {
            for (int j=0; j<n-1; j++) {
                if (!visited[j] && graph[i][0]!= graph[j][0] && graph[i][1]!= graph[j][1]) {
                    if (graph[i][0] + graph[j][1] < MAX_WEIGHT) {
                        visited[i] = visited[j] = 1;
                        edgeCount++;
                    }
                }
            }
        }
    }

    printf("Minimum spanning tree has %d edges\n", edgeCount);

    // Print the minimum spanning tree
    printf("Edge weights: ");
    for (int i=0; i<n-1; i++) {
        if (visited[i]) {
            printf("%d ", graph[i][0] + graph[i][1]);
        }
    }
    printf("\n");

    return 0;
}