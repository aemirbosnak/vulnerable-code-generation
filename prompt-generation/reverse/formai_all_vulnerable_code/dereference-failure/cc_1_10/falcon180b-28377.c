//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    char name[20];
    int num_edges;
    int *edges;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Too many nodes.\n");
        return;
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num_edges = 0;
    nodes[num_nodes].edges = NULL;
    num_nodes++;
}

void add_edge(char *from, char *to) {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, from) == 0) {
            break;
        }
    }
    for (j = 0; j < num_nodes; j++) {
        if (strcmp(nodes[j].name, to) == 0) {
            break;
        }
    }
    if (i == num_nodes || j == num_nodes) {
        printf("Error: Node not found.\n");
        return;
    }
    nodes[i].num_edges++;
    nodes[i].edges = realloc(nodes[i].edges, sizeof(int) * nodes[i].num_edges);
    nodes[i].edges[nodes[i].num_edges - 1] = j;
}

void print_nodes() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%s\n", nodes[i].name);
    }
}

void print_edges() {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %s:\n", nodes[i].name);
        for (j = 0; j < nodes[i].num_edges; j++) {
            printf("  Edge to node %s\n", nodes[nodes[i].edges[j]].name);
        }
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_edge("A", "B");
    add_edge("A", "C");
    add_edge("B", "D");
    print_nodes();
    print_edges();
    return 0;
}