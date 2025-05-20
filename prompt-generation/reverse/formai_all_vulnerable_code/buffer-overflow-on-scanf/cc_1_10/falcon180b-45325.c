//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    char *name;
    struct node *next;
} Node;

typedef struct edge {
    int src_id;
    int dest_id;
    struct edge *next;
} Edge;

Node *nodes = NULL;
Edge *edges = NULL;

void add_node(int id, char *name) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->name = strdup(name);
    new_node->next = NULL;

    if (nodes == NULL) {
        nodes = new_node;
    } else {
        Node *last_node = nodes;
        while (last_node->next!= NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

void add_edge(int src_id, int dest_id) {
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->src_id = src_id;
    new_edge->dest_id = dest_id;
    new_edge->next = NULL;

    if (edges == NULL) {
        edges = new_edge;
    } else {
        Edge *last_edge = edges;
        while (last_edge->next!= NULL) {
            last_edge = last_edge->next;
        }
        last_edge->next = new_edge;
    }
}

void print_nodes() {
    Node *current_node = nodes;
    while (current_node!= NULL) {
        printf("%d: %s\n", current_node->id, current_node->name);
        current_node = current_node->next;
    }
}

void print_edges() {
    Edge *current_edge = edges;
    while (current_edge!= NULL) {
        printf("%d -> %d\n", current_edge->src_id, current_edge->dest_id);
        current_edge = current_edge->next;
    }
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    for (int i = 0; i < num_nodes; i++) {
        char name[50];
        scanf("%s", name);
        add_node(i+1, name);
    }

    for (int i = 0; i < num_edges; i++) {
        int src_id, dest_id;
        scanf("%d %d", &src_id, &dest_id);
        add_edge(src_id, dest_id);
    }

    print_nodes();
    print_edges();

    return 0;
}