//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the number of nodes in the circuit
int num_nodes;

// Define the circuit elements
struct circuit_element {
    int node1;
    int node2;
    double value;
};

// Define the circuit
struct circuit_element circuit[MAX_NODES];

// Define the function to solve the circuit
void solve_circuit() {
    int i, j;

    // Initialize the solution matrix
    double solution[MAX_NODES];
    for (i = 0; i < num_nodes; i++) {
        solution[i] = 0.0;
    }

    // Solve the circuit
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            if (i!= j) {
                solution[i] += circuit[j].value * solution[j];
            }
        }
    }

    // Print the solution
    for (i = 0; i < num_nodes; i++) {
        printf("V%d = %.2f\n", i, solution[i]);
    }
}

// Define the function to add a circuit element
void add_element() {
    int node1, node2, value;

    // Get the node numbers and value
    printf("Enter the node numbers and value for the circuit element:\n");
    printf("Node 1: ");
    scanf("%d", &node1);
    printf("Node 2: ");
    scanf("%d", &node2);
    printf("Value: ");
    scanf("%lf", &value);

    // Add the circuit element
    circuit[num_nodes].node1 = node1;
    circuit[num_nodes].node2 = node2;
    circuit[num_nodes].value = value;
    num_nodes++;
}

// Define the main function
int main() {
    int i, choice;

    // Initialize the circuit
    num_nodes = 0;

    // Add circuit elements
    do {
        printf("\nAdd a circuit element? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            add_element();
        }
    } while (choice == 'y');

    // Solve the circuit
    solve_circuit();

    return 0;
}