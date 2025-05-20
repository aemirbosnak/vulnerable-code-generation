//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: brave
/*
 * Brave Data Structures Visualization Program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define a structure to represent a node in a linked list */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Define a structure to represent a graph */
typedef struct graph {
    int num_nodes;
    int num_edges;
    Node *nodes;
} Graph;

/* Initialize a graph with n nodes and 0 edges */
void init_graph(Graph *graph, int n) {
    graph->num_nodes = n;
    graph->num_edges = 0;
    graph->nodes = malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        graph->nodes[i].data = i;
        graph->nodes[i].next = NULL;
    }
}

/* Add an edge between nodes u and v in the graph */
void add_edge(Graph *graph, int u, int v) {
    Node *node_u = &graph->nodes[u];
    Node *node_v = &graph->nodes[v];
    node_u->next = node_v;
    graph->num_edges++;
}

/* Remove an edge between nodes u and v in the graph */
void remove_edge(Graph *graph, int u, int v) {
    Node *node_u = &graph->nodes[u];
    Node *node_v = &graph->nodes[v];
    node_u->next = NULL;
    graph->num_edges--;
}

/* Print the graph in a visual format */
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node *node = &graph->nodes[i];
        if (node->next != NULL) {
            printf("[%d] -> [%d]\n", i, node->next->data);
        } else {
            printf("[%d]\n", i);
        }
    }
}

int main() {
    Graph graph;
    init_graph(&graph, 5);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 0);
    print_graph(&graph);
    remove_edge(&graph, 0, 1);
    remove_edge(&graph, 1, 2);
    remove_edge(&graph, 2, 3);
    remove_edge(&graph, 3, 4);
    remove_edge(&graph, 4, 0);
    print_graph(&graph);
    return 0;
}