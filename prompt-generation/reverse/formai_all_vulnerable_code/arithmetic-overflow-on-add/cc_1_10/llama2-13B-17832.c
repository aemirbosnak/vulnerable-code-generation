//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct {
    char *name;      // Node name
    char *label;    // Node label
    int weight;     // Node weight
    struct Node *next; // Next node in the graph
} Node;

// Graph definition
typedef struct {
    Node *head;   // Head node of the graph
    int num_nodes; // Number of nodes in the graph
} Graph;

// Function to create a new node
Node *new_node(char *name, char *label, int weight) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->name = name;
    node->label = label;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Function to add a node to the graph
void add_node(Graph *graph, Node *node) {
    if (graph->num_nodes == 0) {
        graph->head = node;
    } else {
        graph->head->next = node;
    }
    graph->num_nodes++;
}

// Function to print the graph
void print_graph(Graph *graph) {
    Node *current = graph->head;
    printf("Graph with %d nodes:\n", graph->num_nodes);
    while (current != NULL) {
        printf("Node %s (%d): %s\n", current->name, current->weight, current->label);
        current = current->next;
    }
}

int main() {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    Node *node1 = new_node("Alice", "Student", 10);
    Node *node2 = new_node("Bob", "Teacher", 20);
    Node *node3 = new_node("Charlie", "Friend", 30);
    Node *node4 = new_node("David", "Colleague", 40);

    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);
    add_node(graph, node4);

    print_graph(graph);

    return 0;
}