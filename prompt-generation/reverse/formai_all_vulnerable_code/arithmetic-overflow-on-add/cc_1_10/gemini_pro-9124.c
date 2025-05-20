//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
// Embark on an electrifying journey through the realm of classical circuit simulation!

#include <stdio.h>
#include <stdlib.h>

// Unveil the secrets of each node in our circuit.
typedef struct Node {
    int value;
    int fanout;
    struct Node **outputs;
} Node;

// Behold, our magical wire that connects nodes together!
typedef struct Wire {
    int value;
    Node *source, *dest;
} Wire;

// Step into the laboratory and craft our very own circuit!
typedef struct Circuit {
    int numNodes, numWires;
    Node *nodes;
    Wire *wires;
} Circuit;

// Create a circuit from scratch - the foundation of our simulation!
Circuit *createCircuit(int numNodes, int numWires) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->numNodes = numNodes;
    circuit->numWires = numWires;
    circuit->nodes = malloc(sizeof(Node) * numNodes);
    circuit->wires = malloc(sizeof(Wire) * numWires);
    return circuit;
}

// Connect nodes with the power of wires - let the current flow!
void connectNodes(Circuit *circuit, int src, int dest) {
    circuit->wires[circuit->numWires].source = &circuit->nodes[src];
    circuit->wires[circuit->numWires].dest = &circuit->nodes[dest];
    circuit->nodes[src].outputs[circuit->nodes[src].fanout++] = &circuit->wires[circuit->numWires++];
}

// Unleash the power of simulation - watch as electricity dances through our circuit!
void simulateCircuit(Circuit *circuit) {
    int i, j, k;
    // Propagate values through the circuit - a cascade of logical operations!
    for (i = 0; i < circuit->numNodes; i++) {
        Node *node = &circuit->nodes[i];
        if (node->value == -1) {
            // Calculate the output value based on inputs.
            for (j = 0; j < node->fanout; j++) {
                Wire *wire = node->outputs[j];
                wire->value = node->value;
            }
        }
    }
    // Display the resulting values - the culmination of our simulation!
    for (k = 0; k < circuit->numNodes; k++) {
        Node *node = &circuit->nodes[k];
        printf("Node %d: %d\n", k, node->value);
    }
}

// Time to witness the magic - let's build and simulate our circuit!
int main() {
    // Craft a circuit with 4 nodes and 3 wires - a glimpse into the world of electronics!
    Circuit *circuit = createCircuit(4, 3);
    // Connect the nodes with wires - the arteries of our circuit!
    connectNodes(circuit, 0, 1);
    connectNodes(circuit, 0, 2);
    connectNodes(circuit, 1, 3);
    // Set the input value - the spark that ignites the circuit!
    circuit->nodes[0].value = 1;
    // Simulate the circuit - let the electrons dance!
    simulateCircuit(circuit);
    return 0;
}