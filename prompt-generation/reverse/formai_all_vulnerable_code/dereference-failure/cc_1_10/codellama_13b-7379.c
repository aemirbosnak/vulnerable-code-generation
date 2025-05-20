//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Graph node structure
struct GraphNode {
    int value;
    struct GraphNode* next;
};

// Graph structure
struct Graph {
    struct GraphNode* nodes;
    int numNodes;
};

// Recursive function to print the graph
void printGraph(struct Graph* graph) {
    if (graph == NULL) {
        return;
    }

    struct GraphNode* node = graph->nodes;
    while (node != NULL) {
        printf("%d ", node->value);
        printGraph(node->next);
    }
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numNodes = 5;

    struct GraphNode* node1 = malloc(sizeof(struct GraphNode));
    node1->value = 1;
    node1->next = NULL;

    struct GraphNode* node2 = malloc(sizeof(struct GraphNode));
    node2->value = 2;
    node2->next = node1;

    struct GraphNode* node3 = malloc(sizeof(struct GraphNode));
    node3->value = 3;
    node3->next = node2;

    struct GraphNode* node4 = malloc(sizeof(struct GraphNode));
    node4->value = 4;
    node4->next = node3;

    struct GraphNode* node5 = malloc(sizeof(struct GraphNode));
    node5->value = 5;
    node5->next = node4;

    graph->nodes = node5;

    printGraph(graph);

    return 0;
}