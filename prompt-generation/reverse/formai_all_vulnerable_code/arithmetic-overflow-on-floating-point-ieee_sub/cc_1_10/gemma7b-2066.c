//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

typedef struct Node {
    int index;
    struct Node* next;
    double voltage;
    double current;
} Node;

void initialize_circuit(Node* head) {
    head = malloc(MAX * sizeof(Node));
    head->next = NULL;
    head->voltage = 0.0;
    head->current = 0.0;
}

void add_node(Node* head, int index, double voltage, double current) {
    Node* newNode = malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;
    newNode->voltage = voltage;
    newNode->current = current;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        Node* temp = head->next;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void simulate_circuit(Node* head) {
    for (Node* node = head->next; node; node = node->next) {
        double resistance = 10000.0; // in ohms
        double voltage_drop = node->voltage * resistance;
        double new_voltage = node->voltage - voltage_drop;
        node->current = voltage_drop / resistance;
        node->voltage = new_voltage;
    }
}

int main() {
    Node* head = NULL;
    initialize_circuit(head);

    add_node(head, 1, 12.0, 0.0);
    add_node(head, 2, 6.0, 0.0);
    add_node(head, 3, 0.0, 0.0);

    simulate_circuit(head);

    for (Node* node = head->next; node; node = node->next) {
        printf("Node %d: Voltage %.2f, Current %.2f\n", node->index, node->voltage, node->current);
    }

    return 0;
}