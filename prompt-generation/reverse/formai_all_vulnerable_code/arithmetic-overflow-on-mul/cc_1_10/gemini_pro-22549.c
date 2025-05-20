//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
/* Welcome to the world of happy circuit simulation! */

#include <stdio.h>
#include <stdlib.h>

// Our happy circuit is represented by a graph of nodes and edges
typedef struct node {
    int value;  // 0 for false, 1 for true
    int fanout; // Number of outgoing edges
    struct edge **edges; // Array of outgoing edges
} node;

typedef struct edge {
    node *from;  // Source node
    node *to;    // Destination node
    int weight; // Weight of the edge (typically 1)
} edge;

// Create a new node with the given value
node *create_node(int value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->fanout = 0;
    new_node->edges = NULL;
    return new_node;
}

// Create a new edge from the source node to the destination node
edge *create_edge(node *from, node *to, int weight) {
    edge *new_edge = malloc(sizeof(edge));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;
    return new_edge;
}

// Add an edge to the source node
void add_edge(node *from, node *to, int weight) {
    from->edges = realloc(from->edges, sizeof(edge *) * (from->fanout + 1));
    from->edges[from->fanout++] = create_edge(from, to, weight);
}

// Propagate the values through the circuit
void propagate(node *start_node) {
    // Queue of nodes to visit
    node **queue = malloc(sizeof(node *) * 100);
    int head = 0, tail = 0;
    queue[tail++] = start_node;

    // Visit all nodes in the queue
    while (head < tail) {
        node *current_node = queue[head++];
        int new_value = 0;  // Default value is false

        // Calculate the new value based on the values of the incoming edges
        for (int i = 0; i < current_node->fanout; i++) {
            new_value |= current_node->edges[i]->from->value * current_node->edges[i]->weight;
        }

        // Update the value of the current node
        current_node->value = new_value;

        // Enqueue the outgoing nodes
        for (int i = 0; i < current_node->fanout; i++) {
            queue[tail++] = current_node->edges[i]->to;
        }
    }

    // Free the queue
    free(queue);
}

// Print the values of all nodes in the circuit
void print_circuit(node *start_node) {
    node **queue = malloc(sizeof(node *) * 100);
    int head = 0, tail = 0;
    queue[tail++] = start_node;

    while (head < tail) {
        node *current_node = queue[head++];
        printf("%d ", current_node->value);

        for (int i = 0; i < current_node->fanout; i++) {
            queue[tail++] = current_node->edges[i]->to;
        }
    }

    printf("\n");
    free(queue);
}

int main() {
    // Create the circuit
    node *input1 = create_node(0);
    node *input2 = create_node(0);
    node *and_gate = create_node(0);
    node *output = create_node(0);

    add_edge(input1, and_gate, 1);
    add_edge(input2, and_gate, 1);
    add_edge(and_gate, output, 1);

    // Propagate the values
    propagate(input1);

    // Print the output
    print_circuit(output);

    return 0;
}