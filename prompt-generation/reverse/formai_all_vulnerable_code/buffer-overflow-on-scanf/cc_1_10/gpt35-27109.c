//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 1000 // Maximum number of nodes in the circuit.

// Defining the Circuit Component Struct
typedef struct component {
    char name[20];
    int node_1;
    int node_2;
    double value;
} Component;

Component circuit[MAX_NODES];   // Array of Component Structures.

// Function to get the Circuit input from the user.
int get_circuit_input() {
    int num_components; // Number of Components in the Circuit

    printf("Enter the number of Components in the Circuit: ");
    scanf("%d", &num_components);

    if(num_components > MAX_NODES) {
        printf("Error: Number of Components exceeds the maximum limit of %d.\n", MAX_NODES);
        exit(1);
    }

    printf("Enter the Circuit Components in the format - Name Node_I Node_J Value:\n");
    for(int i = 0; i < num_components; ++i) {
        scanf("%s %d %d %lf", circuit[i].name, &circuit[i].node_1, &circuit[i].node_2, &circuit[i].value);
    }

    return num_components;
}

// Function to Calculate the Conductance Matrix.
void calculate_conductance_matrix(double **G, int num_nodes, int num_components) {
    // Initializing Conductance Matrix with all 0's
    for(int i = 0; i < num_nodes; ++i) {
        for(int j = 0; j < num_nodes; ++j) {
            G[i][j] = 0.0;
        }
    }

    // Filling the Conductance Matrix
    for(int i = 0; i < num_components; ++i) {
        int node_i = circuit[i].node_1 - 1, node_j = circuit[i].node_2 - 1;

        if(node_i >= 0) G[node_i][node_i] += circuit[i].value;
        if(node_j >= 0) G[node_j][node_j] += circuit[i].value;
        if(node_i >= 0 && node_j >= 0) {
            G[node_i][node_j] -= circuit[i].value;
            G[node_j][node_i] -= circuit[i].value;
        }
    }
}

// Function to Print the Conductance Matrix and Voltage Vector.
void print_matrix(double **matrix, int rows, int cols) {
    printf("\n");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to Solve the Circuit using Gaussian Elimination Method.
void solve_circuit(double **G, double *V, int num_nodes) {
    for(int k = 0; k < num_nodes - 1; ++k) {
        for(int i = k + 1; i < num_nodes; ++i) {
            double factor = G[i][k] / G[k][k];
            for(int j = k + 1; j < num_nodes; ++j) {
                G[i][j] -= factor * G[k][j];
            }
            V[i] -= factor * V[k];
        }
    }

    for(int i = num_nodes - 1; i >= 0; --i) {
        double sum = 0.0;
        for(int j = i + 1; j < num_nodes; ++j) {
            sum += G[i][j] * V[j];
        }
        V[i] = (V[i] - sum) / G[i][i];
    }
}

// Main Function to run the Circuit Simulator.
int main() {
    int num_components = get_circuit_input();
    int num_nodes = -1; // Number of Nodes in the Circuit

    // Calculating the number of Nodes in the Circuit
    for(int i = 0; i < num_components; ++i) {
        num_nodes = fmax(num_nodes, circuit[i].node_1);
        num_nodes = fmax(num_nodes, circuit[i].node_2);
    }

    if(num_nodes == -1) {
        printf("Error: No Components found in the Circuit.\n");
        exit(1);
    }

    // Allocating Memory for Conductance Matrix and Voltage Vector
    double **G = (double**)malloc(num_nodes * sizeof(double*));
    for(int i = 0; i < num_nodes; ++i) G[i] = (double*)malloc(num_nodes * sizeof(double));

    double *V = (double*)malloc(num_nodes * sizeof(double));
    for(int i = 0; i < num_nodes; ++i) V[i] = 0.0;

    calculate_conductance_matrix(G, num_nodes, num_components);
    printf("Conductance Matrix:\n");
    print_matrix(G, num_nodes, num_nodes);

    solve_circuit(G, V, num_nodes);

    printf("Voltage Vector:\n");
    for(int i = 0; i < num_nodes; ++i) {
        printf("Node %d: %lf\n", i + 1, V[i]);
    }

    free(V);
    for(int i = 0; i < num_nodes; ++i) free(G[i]);
    free(G);

    return 0;
}