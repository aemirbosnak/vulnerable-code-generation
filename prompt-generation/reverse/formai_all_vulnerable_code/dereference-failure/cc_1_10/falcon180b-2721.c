//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define MAX_NEIGHBORS 10

typedef struct {
    int id;
    char name[32];
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

int num_nodes = 0;
Node *nodes = NULL;
int num_edges = 0;
Edge *edges = NULL;

void add_node(int id, char *name) {
    Node *node = malloc(sizeof(Node));
    node->id = id;
    strcpy(node->name, name);
    node->degree = 0;
    node->neighbors = NULL;
    nodes = realloc(nodes, sizeof(Node) * ++num_nodes);
    nodes[num_nodes - 1] = *node;
    free(node);
}

void add_edge(int source, int destination, int weight) {
    Edge *edge = malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    edges = realloc(edges, sizeof(Edge) * ++num_edges);
    edges[num_edges - 1] = *edge;
    free(edge);
}

void print_node(Node *node) {
    printf("ID: %d\n", node->id);
    printf("Name: %s\n", node->name);
    printf("Degree: %d\n", node->degree);
    printf("Neighbors:\n");
    for (int i = 0; i < node->degree; i++) {
        printf("%d ", node->neighbors[i]);
    }
    printf("\n");
}

void print_edge(Edge *edge) {
    printf("Source: %d\n", edge->source);
    printf("Destination: %d\n", edge->destination);
    printf("Weight: %d\n", edge->weight);
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        print_node(&nodes[i]);
    }
}

int main() {
    add_node(1, "A");
    add_node(2, "B");
    add_node(3, "C");
    add_node(4, "D");
    add_node(5, "E");

    add_edge(1, 2, 5);
    add_edge(2, 3, 2);
    add_edge(3, 4, 1);
    add_edge(4, 5, 3);

    print_graph();

    return 0;
}