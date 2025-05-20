//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/* Node represents a basic electrical component */
typedef struct Node {
    char* type;     // the type of the node ('resistor', 'capacitor', or 'inductor')
    double value;   // the value of the node in Ohms, Farads, or Henrys
} Node;

/* Edge represents a connection between two nodes in the circuit */
typedef struct Edge {
    int node1;      // the index of the first node
    int node2;      // the index of the second node
    double weight;  // the weight of the edge in Ohms, Farads, or Henrys
} Edge;

int main() {
    int num_nodes, num_edges;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &num_nodes);

    Node* nodes = (Node*) malloc(num_nodes * sizeof(Node));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].type = (char*) malloc(20 * sizeof(char));
        printf("Enter the type of node %d (resistor, capacitor, or inductor): ", i + 1);
        scanf("%s", nodes[i].type);
        printf("Enter the value of node %d in the correct unit (Ohms, Farads, or Henrys): ", i + 1);
        scanf("%lf", &nodes[i].value);
    }

    printf("Enter the number of edges in the circuit: ");
    scanf("%d", &num_edges);

    Edge* edges = (Edge*) malloc(num_edges * sizeof(Edge));
    for (int i = 0; i < num_edges; i++) {
        printf("Enter the indices of nodes connected by edge %d (starting from 1): ", i + 1);
        scanf("%d %d", &edges[i].node1, &edges[i].node2);
        printf("Enter the weight of the edge in the correct unit (Ohms, Farads, or Henrys): ");
        scanf("%lf", &edges[i].weight);
    }

    // display the circuit in matrix form
    printf("\nCircuit in matrix form:\n");
    double** matrix = (double**) malloc(num_nodes * sizeof(double*));
    for (int i = 0; i < num_nodes; i++) {
        matrix[i] = (double*) calloc(num_nodes, sizeof(double));
    }

    for (int i = 0; i < num_edges; i++) {
        int node1 = edges[i].node1 - 1;
        int node2 = edges[i].node2 - 1;
        double weight = edges[i].weight;
        matrix[node1][node1] += weight / nodes[node1].value;
        matrix[node2][node2] += weight / nodes[node2].value;
        matrix[node1][node2] -= weight / nodes[node1].value;
        matrix[node2][node1] -= weight / nodes[node2].value;
    }

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    free(nodes);
    free(edges);
    for (int i = 0; i < num_nodes; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}