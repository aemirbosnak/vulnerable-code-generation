//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000

typedef struct node {
    int id;
    int degree;
    struct edge *edges;
} Node;

typedef struct edge {
    int dest;
    int weight;
    struct edge *next;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes, num_edges;

void add_node(int id) {
    nodes[num_nodes].id = id;
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].edges = NULL;
    num_nodes++;
}

void add_edge(int src, int dest, int weight) {
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->dest = dest;
    new_edge->weight = weight;
    new_edge->next = NULL;

    if (nodes[src].edges == NULL) {
        nodes[src].edges = new_edge;
    } else {
        Edge *current_edge = nodes[src].edges;
        while (current_edge->next!= NULL) {
            current_edge = current_edge->next;
        }
        current_edge->next = new_edge;
    }

    nodes[src].degree++;
    nodes[dest].degree++;
    num_edges++;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i].id);
        Edge *current_edge = nodes[i].edges;
        while (current_edge!= NULL) {
            printf("(%d, %d) ", current_edge->dest, current_edge->weight);
            current_edge = current_edge->next;
        }
        printf("\n");
    }
}

int main() {
    int num_vertices, num_edges, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        add_node(i);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter the source, destination and weight for edge %d: ", i+1);
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }

    print_graph();

    return 0;
}