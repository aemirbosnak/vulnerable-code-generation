//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

int adjacency_matrix[MAX_NODES][MAX_NODES];
int node_count;

void add_edge(int start_node, int end_node) {
    adjacency_matrix[start_node][end_node]++;
    adjacency_matrix[end_node][start_node]++;
}

void remove_edge(int start_node, int end_node) {
    adjacency_matrix[start_node][end_node]--;
    adjacency_matrix[end_node][start_node]--;
}

void simulate_circuit() {
    int i, j, k;

    for (i = 0; i < node_count; i++) {
        int voltage = 0;
        int resistance = 1;

        for (j = 0; j < node_count; j++) {
            if (adjacency_matrix[i][j]) {
                resistance += adjacency_matrix[i][j];
                voltage += j;
            }
        }

        int current = voltage / resistance;
        printf("Node %d: Voltage = %d, Resistance = %d, Current = %d\n", i, voltage, resistance, current);

        for (k = 0; k < node_count; k++) {
            if (adjacency_matrix[i][k]) {
                remove_edge(i, k);
                simulate_circuit();
                add_edge(i, k);
            }
        }
    }
}

int main() {
    int i;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &node_count);

    printf("Enter the adjacency matrix (0s and 1s):\n");

    for (i = 0; i < node_count; i++) {
        int j;
        for (j = 0; j < node_count; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    simulate_circuit();
    return 0;
}