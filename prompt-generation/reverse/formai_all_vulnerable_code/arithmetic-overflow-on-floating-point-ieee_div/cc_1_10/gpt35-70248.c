//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

// Struct to represent a circuit element
typedef struct {
    char type; // can be 'R', 'L', 'C', or 'V'
    double value; // value of the element
    int node1; // first node of the element
    int node2; // second node of the element
} circuit_element;

// Struct to represent a node
typedef struct {
    int num_elements; // number of elements connected to the node
    circuit_element *elements[MAX_NODES]; // array of elements connected to the node
    double voltage; // voltage at the node
} circuit_node;

// Function to simulate the circuit and calculate the node voltages
void simulate(circuit_element *elements, int num_elements, circuit_node *nodes, int num_nodes) {
    int i, j;
    double res_matrix[num_nodes][num_nodes], b_matrix[num_nodes], x_matrix[num_nodes];
    // Initialize matrices to 0
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            res_matrix[i][j] = 0;
            b_matrix[i] = 0;
            x_matrix[i] = 0;
        }
    }
    // Populate matrices with element values
    for (i = 0; i < num_elements; i++) {
        circuit_element e = elements[i];
        if (e.type == 'R') {
            res_matrix[e.node1][e.node1] += 1/e.value;
            res_matrix[e.node1][e.node2] -= 1/e.value;
            res_matrix[e.node2][e.node1] -= 1/e.value;
            res_matrix[e.node2][e.node2] += 1/e.value;
        }
        else if (e.type == 'L' || e.type == 'C') {
            double s = (e.type == 'L') ? e.value : 1/(e.value);
            res_matrix[e.node1][e.node1] += s;
            res_matrix[e.node1][e.node2] -= s;
            res_matrix[e.node2][e.node1] -= s;
            res_matrix[e.node2][e.node2] += s;
            b_matrix[e.node1] += (e.type == 'L') ? 0 : e.value*e.value/(2*1.5);
            b_matrix[e.node2] -= (e.type == 'L') ? 0 : e.value*e.value/(2*1.5);
        }
        else if (e.type == 'V') {
            b_matrix[e.node1] -= e.value;
            b_matrix[e.node2] += e.value;
        }
    }
    // Solve for node voltages
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            if (i != j) {
                double factor = res_matrix[j][i]/res_matrix[i][i];
                for (int k = 0; k < num_nodes; k++) {
                    res_matrix[j][k] -= factor*res_matrix[i][k];
                }
                b_matrix[j] -= factor*b_matrix[i];
            }
        }
    }
    for (i = 0; i < num_nodes; i++) {
        x_matrix[i] = b_matrix[i]/res_matrix[i][i];
    }
    // Update node voltages
    for (i = 0; i < num_nodes; i++) {
        nodes[i].voltage = x_matrix[i];
    }
}

int main() {
    // Create circuit elements
    circuit_element elements[] = {
        {'R', 100, 0, 1},
        {'L', 0.1, 1, 2},
        {'C', 100e-6, 2, 3},
        {'V', 10, 0, 3},
    };
    int num_elements = sizeof(elements)/sizeof(circuit_element);
    // Create circuit nodes
    circuit_node nodes[] = {
        {2, {&elements[0], &elements[3]}, 0},
        {2, {&elements[0], &elements[1]}, 0},
        {2, {&elements[1], &elements[2]}, 0},
        {2, {&elements[2], &elements[3]}, 0},
    };
    int num_nodes = sizeof(nodes)/sizeof(circuit_node);
    // Simulate the circuit and calculate the node voltages
    simulate(elements, num_elements, nodes, num_nodes);
    // Print the node voltages
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d voltage: %f V\n", i, nodes[i].voltage);
    }
    return 0;
}