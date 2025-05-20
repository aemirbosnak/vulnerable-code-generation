//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>

#define MAX_NODES 10
#define MAX_RESISTORS 15

// Structure for each resistor
struct resistor {
    int n1, n2; // Nodes connected to
    double resistance;
};

int num_nodes = 0;
int num_res = 0;

double node_voltages[MAX_NODES];
struct resistor resistors[MAX_RESISTORS];

// Function to simulate the circuit
void circuit_simulator() {
    double iter_tol = 1e-6; // Iteration tolerance
    int max_iter = 1500; // Maximum number of iterations
    int iter = 0; // Current iteration
    double delta_voltages[MAX_NODES]; // Change in voltage for each node
    double iter_error = 0; // Error for this iteration
    
    // Initialize node voltages to zero
    for (int i = 0; i < MAX_NODES; i++) {
        node_voltages[i] = 0;
    }
    
    printf("Starting circuit simulation...\n\n");
    
    // Iterate until convergence or maximum number of iterations reached
    while (iter < max_iter) {
        iter++;
        
        // Calculate change in voltage for each node
        for (int i = 0; i < num_nodes; i++) {
            double delta_v = 0;
            
            // Calculate contribution from each resistor
            for (int j = 0; j < num_res; j++) {
                if (resistors[j].n1 == i) {
                    delta_v += (node_voltages[resistors[j].n2] - node_voltages[i]) / resistors[j].resistance;
                } else if (resistors[j].n2 == i) {
                    delta_v += (node_voltages[resistors[j].n1] - node_voltages[i]) / resistors[j].resistance;
                }
            }
            
            delta_voltages[i] = delta_v;
        }
        
        // Update node voltages
        for (int i = 0; i < num_nodes; i++) {
            node_voltages[i] += delta_voltages[i];
        }
        
        // Calculate iteration error
        iter_error = 0;
        for (int i = 0; i < num_nodes; i++) {
            double v_diff = delta_voltages[i];
            if (v_diff < 0) {
                v_diff = -v_diff;   
            }
            if (v_diff > iter_error) {
                iter_error = v_diff;
            }
        }
        
        // Check if circuit has converged
        if (iter_error < iter_tol) {
            printf("Circuit simulation converged after %d iterations.\n\n", iter);
            break;
        }
    }
    
    // Print node voltages
    printf("Node voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %f V\n", i, node_voltages[i]);
    }
    
    printf("\n");
}

// Function to add a resistor to the circuit
void add_resistor(int n1, int n2, double resistance) {
    if (num_res == MAX_RESISTORS) {
        printf("Error: Maximum number of resistors reached.\n");
    } else if (n1 < 0 || n1 >= num_nodes || n2 < 0 || n2 >= num_nodes) {
        printf("Error: Invalid node number.\n");
    } else if (resistance <= 0) {
        printf("Error: Resistance must be greater than zero.\n");
    } else {
        // Add resistor to list
        resistors[num_res].n1 = n1;
        resistors[num_res].n2 = n2;
        resistors[num_res].resistance = resistance;
        num_res++;
    }
}

int main() {
    int choice = 0;
    int n1, n2;
    double resistance;
    
    printf("Welcome to the circuit simulator!\n\n");
    
    // Prompt user for number of nodes
    printf("Please enter the number of nodes in the circuit (maximum %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    if (num_nodes < 2 || num_nodes > MAX_NODES) {
        printf("Error: Invalid number of nodes.\n");
        return 0;
    }
    
    // Main loop
    while (choice != 3) {
        printf("Menu:\n");
        printf("1. Add resistor\n");
        printf("2. Simulate circuit\n");
        printf("3. Exit program\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Prompt user for resistor details
                printf("Please enter the two nodes that the resistor connects: ");
                scanf("%d %d", &n1, &n2);
                printf("Please enter the resistance of the resistor: ");
                scanf("%lf", &resistance);
                
                // Add resistor to circuit
                add_resistor(n1, n2, resistance);
                break;
            case 2:
                // Simulate circuit
                circuit_simulator();
                break;
            case 3:
                // Exit program
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}