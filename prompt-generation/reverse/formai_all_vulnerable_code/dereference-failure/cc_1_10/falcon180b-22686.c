//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    double value;
    struct Node *next;
};

struct Circuit {
    struct Node *head;
};

struct Circuit *createCircuit() {
    struct Circuit *circuit = malloc(sizeof(struct Circuit));
    circuit->head = NULL;
    return circuit;
}

void addNode(struct Circuit *circuit, double value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    if (circuit->head == NULL) {
        circuit->head = node;
    } else {
        struct Node *temp = circuit->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void printCircuit(struct Circuit *circuit) {
    struct Node *node = circuit->head;
    while (node!= NULL) {
        printf("%lf ", node->value);
        node = node->next;
    }
    printf("\n");
}

void solveCircuit(struct Circuit *circuit) {
    struct Node *node = circuit->head;
    while (node!= NULL) {
        double sum = 0;
        struct Node *temp = circuit->head;
        while (temp!= node) {
            sum += temp->value;
            temp = temp->next;
        }
        node->value = sum;
        node = node->next;
    }
}

int main() {
    struct Circuit *circuit = createCircuit();
    addNode(circuit, 1);
    addNode(circuit, 2);
    addNode(circuit, 3);
    addNode(circuit, 4);
    addNode(circuit, 5);
    printCircuit(circuit);
    solveCircuit(circuit);
    printCircuit(circuit);
    return 0;
}