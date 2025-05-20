//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int degree;
    int *adjacent;
} Node;

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

Node *graph;
int num_nodes, num_edges;
Edge *edges;

void init_graph() {
    num_nodes = 0;
    num_edges = 0;
    graph = (Node *)malloc(MAX_NODES * sizeof(Node));
    edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
}

void add_node(int id, char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    graph[num_nodes].id = id;
    strcpy(graph[num_nodes].name, name);
    graph[num_nodes].degree = 0;
    graph[num_nodes].adjacent = (int *)malloc(MAX_EDGES * sizeof(int));
    num_nodes++;
}

void add_edge(int u, int v, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    edges[num_edges].u = u;
    edges[num_edges].v = v;
    edges[num_edges].weight = weight;
    num_edges++;
}

void print_graph() {
    int i;
    printf("Network Topology:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%d %s\n", graph[i].id, graph[i].name);
        printf("Adjacent nodes: ");
        int j;
        for (j = 0; j < graph[i].degree; j++) {
            printf("%d ", graph[i].adjacent[j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    init_graph();
    add_node(1, "Node 1");
    add_node(2, "Node 2");
    add_node(3, "Node 3");
    add_node(4, "Node 4");
    add_edge(1, 2, 5);
    add_edge(2, 3, 3);
    add_edge(3, 4, 2);
    add_edge(4, 1, 7);
    print_graph();
    return 0;
}