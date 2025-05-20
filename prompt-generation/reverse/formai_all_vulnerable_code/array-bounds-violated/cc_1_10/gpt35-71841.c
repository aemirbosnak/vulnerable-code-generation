//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000

int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
bool visited[MAX_NODES]; // Array to keep track of visited nodes
int num_nodes; // Number of nodes in the network

// Function to initialize the adjacency matrix
void init() {
    for(int i = 0; i < num_nodes; i++) {
        for(int j = 0; j < num_nodes; j++) {
            adj[i][j] = 0;
        }
    }
}

// Function to add an edge between two nodes
void add_edge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to perform DFS traversal
void dfs(int u) {
    visited[u] = true;
    printf("%d ", u); // Print the node
    for(int v = 0; v < num_nodes; v++) {
        if(adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

// Main function
int main() {
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    init();

    printf("Enter the edges as pairs of integers (u v), in the range 0 to %d. Enter -1 -1 to stop.\n", num_nodes-1);
    int u, v;
    do {
        scanf("%d %d", &u, &v);
        if(u != -1 && v != -1) {
            add_edge(u, v);
        }
    } while(u != -1 && v != -1);

    printf("The network topology map is:\n");
    for(int i = 0; i < num_nodes; i++) {
        if(!visited[i]) {
            dfs(i); // Perform DFS traversal
        }
    }

    return 0;
}