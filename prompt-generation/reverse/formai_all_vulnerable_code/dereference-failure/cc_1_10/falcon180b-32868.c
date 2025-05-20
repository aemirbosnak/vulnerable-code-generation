//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int number;
    float voltage;
    struct node *next;
} Node;

// Define the circuit structure
typedef struct circuit {
    Node *head;
} Circuit;

// Function to create a new node
Node *createNode(int number, float voltage) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->number = number;
    newNode->voltage = voltage;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the circuit
void addNode(Circuit *circuit, Node *newNode) {
    if (circuit->head == NULL) {
        circuit->head = newNode;
    } else {
        Node *currentNode = circuit->head;
        while (currentNode->next!= NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Function to print the circuit
void printCircuit(Circuit *circuit) {
    Node *currentNode = circuit->head;
    printf("Circuit:\n");
    while (currentNode!= NULL) {
        printf("Node %d: Voltage = %.2f\n", currentNode->number, currentNode->voltage);
        currentNode = currentNode->next;
    }
}

// Function to simulate the circuit
void simulateCircuit(Circuit *circuit) {
    Node *currentNode = circuit->head;
    while (currentNode!= NULL) {
        currentNode->voltage = currentNode->voltage + 1;
        currentNode = currentNode->next;
    }
}

int main() {
    // Create the circuit
    Circuit circuit;
    circuit.head = NULL;

    // Add nodes to the circuit
    Node *node1 = createNode(1, 5.0);
    Node *node2 = createNode(2, 10.0);
    Node *node3 = createNode(3, 15.0);
    addNode(&circuit, node1);
    addNode(&circuit, node2);
    addNode(&circuit, node3);

    // Print the circuit
    printCircuit(&circuit);

    // Simulate the circuit
    simulateCircuit(&circuit);

    // Print the circuit after simulation
    printCircuit(&circuit);

    return 0;
}