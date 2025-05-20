//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 999999

typedef struct {
    int id;
    int weight;
    int next;
} Edge;

typedef struct {
    int id;
    int degree;
    Edge *adj;
} Node;

Node *graph = NULL;
int num_nodes = 0;

void init_graph() {
    num_nodes = 0;
    graph = (Node *)malloc(MAX_NODES * sizeof(Node));
    memset(graph, 0, MAX_NODES * sizeof(Node));
}

void add_node(int id) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        return;
    }
    graph[num_nodes] = (Node) {
       .id = id,
       .degree = 0,
       .adj = NULL
    };
    num_nodes++;
}

void add_edge(int u, int v, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->id = v;
    new_edge->weight = weight;
    new_edge->next = graph[u].adj;
    graph[u].adj = new_edge;
    graph[v].degree++;
}

void print_graph() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        Node *node = &graph[i];
        Edge *edge = node->adj;
        while (edge!= NULL) {
            printf("-> %d (%d)", edge->id, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    init_graph();
    add_node(0);
    add_node(1);
    add_node(2);
    add_node(3);
    add_edge(0, 1, 5);
    add_edge(0, 2, 3);
    add_edge(1, 2, 1);
    add_edge(1, 3, 2);
    add_edge(2, 3, 4);
    print_graph();
    return 0;
}