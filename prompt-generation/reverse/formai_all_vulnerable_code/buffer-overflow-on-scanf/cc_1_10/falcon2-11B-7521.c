//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure for a node in the circuit
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Define a structure for the circuit
typedef struct Circuit {
    Node* head;
} Circuit;

// Function to create a new circuit
Circuit* createCircuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

// Function to add a new node to the circuit
Node* addNode(Circuit* circuit, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (circuit->head == NULL) {
        circuit->head = node;
    } else {
        Node* current = circuit->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = node;
    }

    return node;
}

// Function to print the circuit
void printCircuit(Circuit* circuit) {
    Node* current = circuit->head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to find the nth node in the circuit
Node* findNode(Circuit* circuit, int n) {
    Node* current = circuit->head;
    Node* prev = NULL;

    for (int i = 1; i <= n; i++) {
        if (current == NULL) {
            printf("Error: n is greater than the number of nodes in the circuit\n");
            return NULL;
        }

        if (i == n) {
            return current;
        }

        prev = current;
        current = current->next;
    }

    return prev;
}

// Main function
int main() {
    Circuit* circuit = createCircuit();
    int n;

    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &value);

        addNode(circuit, value);
    }

    printCircuit(circuit);
    printf("Enter the position of the node you want to find: ");
    scanf("%d", &n);

    Node* node = findNode(circuit, n);
    if (node!= NULL) {
        printf("Node %d is at position %d\n", node->value, node->next - circuit->head);
    } else {
        printf("Node not found\n");
    }

    return 0;
}