//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000 // maximum number of nodes allowed
#define MAX_EDGES 1000000 // maximum number of edges allowed

typedef struct {
    int from; // starting vertex of edge
    int to; // ending vertex of edge
    double weight; // weight of edge
} Edge;

Edge edges[MAX_EDGES]; // array of edges
double voltage[MAX_NODES]; // voltage of each node
int num_nodes, num_edges; // number of nodes and edges in circuit

int main() {
    printf("Welcome to the Classical Circuit Simulator!\n");
    printf("Please enter the number of nodes in your circuit: ");
    scanf("%d", &num_nodes);
    
    if (num_nodes < 2 || num_nodes > MAX_NODES) {
        printf("Invalid number of nodes. Please enter a number between 2 and %d.\n", MAX_NODES);
        return 0;
    }

    // initialize all voltages to 0
    for (int i = 0; i < num_nodes; i++) {
        voltage[i] = 0;
    }

    printf("Please enter the number of edges in your circuit: ");
    scanf("%d", &num_edges);

    if (num_edges < 1 || num_edges > MAX_EDGES) {
        printf("Invalid number of edges. Please enter a number between 1 and %d.\n", MAX_EDGES);
        return 0;
    }

    // read in edges
    printf("Please enter the starting node, ending node, and weight for each edge, separated by spaces:\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d %lf", &edges[i].from, &edges[i].to, &edges[i].weight);
    }

    // print out circuit
    printf("\nYour circuit has the following nodes and edges:\n");
    printf("Nodes: ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", i);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("(%d, %d): %.2lf\n", edges[i].from, edges[i].to, edges[i].weight);
    }

    // calculate voltage of each node using Kirchhoff's Laws
    for (int i = 0; i < num_nodes; i++) {
        double sum = 0;
        for (int j = 0; j < num_edges; j++) {
            if (edges[j].to == i) {
                sum += voltage[edges[j].from] * edges[j].weight;
            }
            else if (edges[j].from == i) {
                sum -= voltage[edges[j].to] * edges[j].weight;
            }
        }
        voltage[i] = sum;
    }

    // print out voltages of each node
    printf("\nThe voltages of each node are:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.2lf\n", i, voltage[i]);
    }

    return 0;
}