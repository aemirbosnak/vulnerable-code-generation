//FormAI DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10

// Structure to hold node information
struct node {
    int id; // Node ID
    int count; // Total number of connections/node degree
    int edges[MAX_NODES]; // Adjacency list
};

// Create graph using adjacency matrix representation
void create_graph(struct node graph[], int num_nodes) {
    int i, j, num_edges;
    for (i = 0; i < num_nodes; i++) {
        graph[i].id = i;
        printf("Enter the number of edges for node %d: ", i);
        scanf("%d", &num_edges);
        graph[i].count = num_edges;
        printf("Enter the edges for node %d separated by spaces: ", i);
        for (j = 0; j < num_edges; j++) {
            scanf("%d", &graph[i].edges[j]);
        }
    }
}

// Display graph using adjacency list representation
void display_graph(struct node graph[], int num_nodes) {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d (%d connections): ", graph[i].id, graph[i].count);
        for (j = 0; j < graph[i].count; j++) {
            printf("%d ", graph[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    struct node graph[MAX_NODES];
    int num_nodes;

    printf("Enter the number of nodes in the graph (max %d): ", MAX_NODES);
    scanf("%d", &num_nodes);

    create_graph(graph, num_nodes);

    printf("\nAdjacency list representation of the graph:\n");
    display_graph(graph, num_nodes);

    return 0;
}