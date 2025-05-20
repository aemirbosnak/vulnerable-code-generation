//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Queue structure
typedef struct queue {
    struct node *head;
    struct node *tail;
} queue;

// Function to create a new node
node *create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to enqueue a node
void enqueue(queue *q, node *n) {
    if (q->head == NULL) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
}

// Function to dequeue a node
node *dequeue(queue *q) {
    if (q->head == NULL) {
        return NULL;
    } else {
        node *temp = q->head;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        return temp;
    }
}

// Function to create a new circuit
int create_circuit(int **circuit, int num_nodes, int num_edges) {
    // Allocate memory for the circuit
    *circuit = (int *)malloc(num_nodes * num_nodes * sizeof(int));

    // Initialize the circuit to 0
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            (*circuit)[i * num_nodes + j] = 0;
        }
    }

    // Read the edges from the user
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        (*circuit)[node1 * num_nodes + node2] = 1;
    }

    return 0;
}

// Function to simulate the circuit
int simulate_circuit(int *circuit, int num_nodes, int *inputs, int *outputs) {
    // Create a queue to store the nodes that need to be processed
    queue q;
    q.head = NULL;
    q.tail = NULL;

    // Enqueue the input nodes
    for (int i = 0; i < num_nodes; i++) {
        if (inputs[i] == 1) {
            enqueue(&q, create_node(i));
        }
    }

    // Process the nodes in the queue until it is empty
    while (q.head != NULL) {
        // Dequeue the next node
        node *n = dequeue(&q);

        // Get the value of the node
        int value = circuit[n->value * num_nodes + n->value];

        // Update the outputs
        outputs[n->value] = value;

        // Enqueue the next nodes
        for (int i = 0; i < num_nodes; i++) {
            if (circuit[n->value * num_nodes + i] == 1 && inputs[i] == 0) {
                enqueue(&q, create_node(i));
            }
        }
    }

    return 0;
}

// Function to print the circuit
void print_circuit(int *circuit, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", circuit[i * num_nodes + j]);
        }
        printf("\n");
    }
}

// Function to print the outputs
void print_outputs(int *outputs, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", outputs[i]);
    }
    printf("\n");
}

int main() {
    // Get the number of nodes and edges from the user
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    // Create the circuit
    int *circuit;
    create_circuit(&circuit, num_nodes, num_edges);

    // Print the circuit
    print_circuit(circuit, num_nodes);

    // Get the inputs from the user
    int *inputs = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        scanf("%d", &inputs[i]);
    }

    // Simulate the circuit
    int *outputs = (int *)malloc(num_nodes * sizeof(int));
    simulate_circuit(circuit, num_nodes, inputs, outputs);

    // Print the outputs
    print_outputs(outputs, num_nodes);

    return 0;
}