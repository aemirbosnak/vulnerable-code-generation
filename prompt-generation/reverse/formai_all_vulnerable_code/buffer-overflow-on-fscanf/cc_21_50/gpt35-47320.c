//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
//This is a C classical circuit simulator example program
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50 // Maximum number of nodes in the circuit

struct element {         // Element struct to store circuit parameters
    int type;
    int node1;
    int node2;
    double value;
};

int main() {
    struct element circuit[MAX_NODES];  // Array of element structs to store the circuit
    int num_elements = 0;               // Initialize the number of elements in the circuit to zero
    
    // Read in the circuit elements from a file and store them in the circuit array
    FILE *file_pointer;
    file_pointer = fopen("circuit.txt", "r");
    if (file_pointer == NULL) {
        printf("Error: Failed to open file\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file_pointer, "%d %d %d %lf", &circuit[num_elements].type, &circuit[num_elements].node1, &circuit[num_elements].node2, &circuit[num_elements].value) != EOF) {
        num_elements++;
    }
    fclose(file_pointer);
    
    // Initialize the conductance matrix and current vector
    double G[MAX_NODES][MAX_NODES] = {0};
    double I[MAX_NODES] = {0};
    
    // Fill in the conductance matrix and current vector based on the circuit elements
    for (int i = 0; i < num_elements; i++) {
        switch(circuit[i].type) {
            case 0: // Resistor
                if (circuit[i].node1 != -1) G[circuit[i].node1][circuit[i].node1] += 1/circuit[i].value;
                if (circuit[i].node2 != -1) G[circuit[i].node2][circuit[i].node2] += 1/circuit[i].value;
                if (circuit[i].node1 != -1 && circuit[i].node2 != -1) {
                    G[circuit[i].node1][circuit[i].node2] -= 1/circuit[i].value;
                    G[circuit[i].node2][circuit[i].node1] -= 1/circuit[i].value;
                }
                break;
            case 1: // Current source
                if (circuit[i].node1 != -1) I[circuit[i].node1] -= circuit[i].value;
                if (circuit[i].node2 != -1) I[circuit[i].node2] += circuit[i].value;
                break;
            case 2: // Voltage source
                if (circuit[i].node1 != -1) {
                    G[circuit[i].node1][num_elements] += 1;
                    G[num_elements][circuit[i].node1] += 1;
                    I[num_elements] -= circuit[i].value;
                }
                if (circuit[i].node2 != -1) {
                    G[circuit[i].node2][num_elements] -= 1;
                    G[num_elements][circuit[i].node2] -= 1;
                    I[num_elements] += circuit[i].value;
                }
                num_elements++;
                break;
        }
    }
    
    // Solve the circuit using Gaussian elimination
    for (int i = 0; i < num_elements; i++) {
        double max_element = 0;
        int pivot = i;
        for (int j = i; j < num_elements; j++) {
            if (abs(G[j][i]) > max_element) {
                max_element = abs(G[j][i]);
                pivot = j;
            }
        }
        if (pivot != i) {
            for (int j = 0; j <= num_elements; j++) {
                double temp = G[i][j];
                G[i][j] = G[pivot][j];
                G[pivot][j] = temp;
            }
        }
        for (int j = i+1; j < num_elements; j++) {
            double factor = G[j][i]/G[i][i];
            for (int k = i; k <= num_elements; k++) {
                G[j][k] -= factor*G[i][k];
            }
        }
    }
    double V[MAX_NODES] = {0};
    for (int i = num_elements-1; i >= 0; i--) {
        double sum = 0;
        for (int j = i+1; j < num_elements; j++) {
            sum += G[i][j]*V[j];
        }
        V[i] = (I[i] - sum)/G[i][i];
    }
    
    // Print the results to the console
    printf("Node Voltages:\n");
    for (int i = 0; i < num_elements; i++) {
        if (circuit[i].type == 2) continue;
        printf("Node %d: %.2f V\n", i+1, V[i]);
    }
    
    return 0;
}