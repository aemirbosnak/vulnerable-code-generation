//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100 // maximum number of nodes allowed in the circuit

struct Element { // an element in the circuit
    char name; // name of the element
    int node1; // node 1
    int node2; // node 2
    double value; // value of the element
};

struct Circuit { // the whole circuit
    int num_nodes; // number of nodes in the circuit
    struct Element elements[MAX_NODES]; // list of elements in the circuit
};

void simulate(struct Circuit circuit, double *values) { // simulates the circuit
    double voltages[MAX_NODES]; // array to store node voltages
    memset(voltages, 0, sizeof(voltages)); // initialize voltages to zero
    for (int i = 0; i < circuit.num_nodes; i++) { // iterate over nodes
        for (int j = 0; j < MAX_NODES; j++) { // iterate over elements
            if (circuit.elements[j].name == '\0') break; // end of elements
            if (circuit.elements[j].node1 == i) { // element connected to node i
                switch (circuit.elements[j].name) { // check element type
                    case 'R': // resistor
                        voltages[i] += (values[circuit.elements[j].node1] - values[circuit.elements[j].node2]) / circuit.elements[j].value; // add voltage drop
                        break;
                    case 'C': // capacitor
                        voltages[i] += values[circuit.elements[j].node1]; // add current voltage
                        break;
                    case 'L': // inductor
                        voltages[i] += circuit.elements[j].value * (values[circuit.elements[j].node1] - values[circuit.elements[j].node2]); // add voltage drop
                        break;
                    case 'V': // voltage source
                        if (circuit.elements[j].node1 == i) {
                            voltages[i] += circuit.elements[j].value; // add voltage source value
                        } else {
                            voltages[i] -= circuit.elements[j].value; // subtract voltage source value
                        }
                        break;
                    case 'I': // current source
                        if (circuit.elements[j].node1 == i) {
                            voltages[i] += circuit.elements[j].value; // add current source value
                        } else {
                            voltages[i] -= circuit.elements[j].value; // subtract current source value
                        }
                        break;
                    default:
                        printf("Unknown element type\n");
                        break;
                }
            }
            if (circuit.elements[j].node2 == i) { // element connected to node i
                switch (circuit.elements[j].name) { // check element type
                    case 'R': // resistor
                        voltages[i] += (values[circuit.elements[j].node2] - values[circuit.elements[j].node1]) / circuit.elements[j].value; // add voltage drop
                        break;
                    case 'C': // capacitor
                        voltages[i] += values[circuit.elements[j].node2]; // add current voltage
                        break;
                    case 'L': // inductor
                        voltages[i] += circuit.elements[j].value * (values[circuit.elements[j].node2] - values[circuit.elements[j].node1]); // add voltage drop
                        break;
                    case 'V': // voltage source
                        if (circuit.elements[j].node2 == i) {
                            voltages[i] += circuit.elements[j].value; // add voltage source value
                        } else {
                            voltages[i] -= circuit.elements[j].value; // subtract voltage source value
                        }
                        break;
                    case 'I': // current source
                        if (circuit.elements[j].node2 == i) {
                            voltages[i] += circuit.elements[j].value; // add current source value
                        } else {
                            voltages[i] -= circuit.elements[j].value; // subtract current source value
                        }
                        break;
                    default:
                        printf("Unknown element type\n");
                        break;
                }
            }
        }
    }
    memcpy(values, voltages, sizeof(voltages)); // copy new voltages to original values array
}

int main() {
    struct Circuit circuit;
    int num_elements = 0;
    printf("Enter number of nodes in the circuit: ");
    scanf("%d", &circuit.num_nodes);
    while (num_elements < MAX_NODES) { // maximum number of elements reached
        printf("Enter element type (R/C/L/V/I) or press Enter to finish: ");
        fflush(stdin); // clear input buffer
        char element_type = getchar();
        if (element_type == '\n') { // end of input
            break;
        }
        printf("Enter node 1: ");
        int node1;
        scanf("%d", &node1);
        printf("Enter node 2: ");
        int node2;
        scanf("%d", &node2);
        printf("Enter element value: ");
        double element_value;
        scanf("%lf", &element_value);
        struct Element element = {element_type, node1, node2, element_value};
        circuit.elements[num_elements] = element;
        num_elements++;
    }
    double node_voltages[MAX_NODES] = {0}; // initialize node voltages to zero
    int num_iterations = 0;
    printf("Enter number of iterations: ");
    scanf("%d", &num_iterations);
    for (int i = 0; i < num_iterations; i++) { // simulate circuit for specified number of iterations
        simulate(circuit, node_voltages);
        printf("Iteration %d: ", i + 1);
        for (int j = 0; j < circuit.num_nodes; j++) {
            printf("Node %d: %lfV ", j, node_voltages[j]);
        }
        printf("\n");
    }
    return 0;
}