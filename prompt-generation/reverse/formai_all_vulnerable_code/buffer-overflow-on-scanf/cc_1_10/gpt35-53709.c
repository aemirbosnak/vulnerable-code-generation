//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_EDGES 20

/* Define a struct to represent a node in the circuit */
typedef struct {
    int id;
    int value;
} Node;

/* Define a struct to represent an edge in the circuit */
typedef struct {
    int source;
    int target;
    int weight;
} Edge;

/* Define a global array to store the nodes */
Node nodes[MAX_NODES];

/* Define a global array to store the edges */
Edge edges[MAX_EDGES];

/* Define the recursive function to calculate the output value of a node */
int calculate_output(int node_id) {
    int i;
    int output = nodes[node_id].value;
    
    for (i = 0; i < MAX_EDGES; i++) {
        if (edges[i].source == node_id) {
            output += edges[i].weight * calculate_output(edges[i].target);
        }
    }
    
    return output;
}

int main() {
    int i;
    int num_nodes;
    int num_edges;
    
    printf("Enter the number of nodes in the circuit (max %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    
    printf("Enter the number of edges in the circuit (max %d): ", MAX_EDGES);
    scanf("%d", &num_edges);
    
    /* Initialize the nodes */
    for (i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].value = 0;
    }
    
    /* Initialize the edges */
    for (i = 0; i < num_edges; i++) {
        printf("Enter edge %d (source target weight): ", i+1);
        scanf("%d %d %d", &edges[i].source, &edges[i].target, &edges[i].weight);
    }
    
    /* Prompt the user for the node value inputs */
    for (i = 0; i < num_nodes; i++) {
        printf("Enter the value for node %d: ", i);
        scanf("%d", &nodes[i].value);
    }
    
    /* Calculate the output for each node */
    for (i = 0; i < num_nodes; i++) {
        printf("Output for node %d: %d\n", i, calculate_output(i));
    }
    
    return 0;
}