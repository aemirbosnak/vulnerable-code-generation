//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>

#define MAX_NODES 100

int num_nodes;
double circuit_matrix[MAX_NODES][MAX_NODES];

/* function to initialize the circuit matrix */
void initialize_matrix() {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            circuit_matrix[i][j] = 0;
        }
    }
}

/* function to add an element to the circuit matrix */
void add_element(int node1, int node2, double value) {
    circuit_matrix[node1][node2] += value;
    circuit_matrix[node2][node1] += value; // add symmetric element
}

/* function to print the circuit matrix */
void print_circuit_matrix() {
    int i, j;
    printf("\nCircuit Matrix:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) { 
            printf("%lf\t", circuit_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, node1, node2;
    double value;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    initialize_matrix();

    printf("\nEnter elements as 'node1 node2 value' (enter -1 to exit):\n");
    scanf("%d %d %lf", &node1, &node2, &value);

    while (node1 != -1) {
        add_element(node1, node2, value);
        scanf("%d %d %lf", &node1, &node2, &value);
    }

    print_circuit_matrix();

    return 0;
}