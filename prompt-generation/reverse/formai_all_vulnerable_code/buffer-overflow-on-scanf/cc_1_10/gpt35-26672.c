//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODE 20 // Maximum number of nodes
#define MAX_COLOR 4 // Maximum number of colors

int numOfNodes, numOfEdges; // Number of nodes and edges in the graph
bool graph[MAX_NODE][MAX_NODE]; // 2D array representing the graph
int color[MAX_NODE]; // Array to store the color of each node

bool isValid(int node, int c) {
    for (int i = 0; i < numOfNodes; i++) {
        if (graph[node][i] && c == color[i]) {
            return false; // If node is neighbor and has the same color
        }
    }
    return true;
}

bool graphColoring(int node) {
    if (node == numOfNodes) {
        return true; // All nodes have been colored
    }
    for (int c = 1; c <= MAX_COLOR; c++) {
        if (isValid(node, c)) {
            color[node] = c;
            if (graphColoring(node + 1)) {
                return true;
            }
            color[node] = 0; // Backtrack
        }
    }
    return false; // Color cannot be assigned to this node
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &numOfNodes);
    printf("Enter number of edges: ");
    scanf("%d", &numOfEdges);

    // Initialize graph to all zeros
    for (int i = 0; i < MAX_NODE; i++) {
        for (int j = 0; j < MAX_NODE; j++) {
            graph[i][j] = false;
        }
    }

    // Add edges to graph
    int n1, n2;
    printf("Enter node pairs that represent edges (e.g. 2 4): ");
    for (int i = 0; i < numOfEdges; i++) {
        scanf("%d %d", &n1, &n2);
        graph[n1 - 1][n2 - 1] = true;
        graph[n2 - 1][n1 - 1] = true;
    }

    if (graphColoring(0)) {
        printf("The nodes can be colored using at most %d colors:\n", MAX_COLOR);
        for (int i = 0; i < numOfNodes; i++) {
            printf("Node %d ==> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("The nodes cannot be colored using %d or fewer colors.\n", MAX_COLOR);
    }
    
    return 0;
}