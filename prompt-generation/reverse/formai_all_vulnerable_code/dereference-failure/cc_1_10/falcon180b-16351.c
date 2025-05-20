//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int num_neighbors;
    int *neighbors;
} Node;

Node *nodes;
int num_nodes;

void add_node(char *name) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = num_nodes;
    new_node->num_neighbors = 0;
    new_node->neighbors = NULL;
    nodes[num_nodes++] = *new_node;
}

void add_edge(int node1, int node2) {
    Node *n1 = &nodes[node1];
    Node *n2 = &nodes[node2];
    n1->num_neighbors++;
    n2->num_neighbors++;
    n1->neighbors = (int *) realloc(n1->neighbors, n1->num_neighbors * sizeof(int));
    n2->neighbors = (int *) realloc(n2->neighbors, n2->num_neighbors * sizeof(int));
    n1->neighbors[n1->num_neighbors - 1] = node2;
    n2->neighbors[n2->num_neighbors - 1] = node1;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        Node *n = &nodes[i];
        printf("%s (%d) - ", n->name, n->id);
        for (int j = 0; j < n->num_neighbors; j++) {
            printf("%d ", n->neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    nodes = (Node *) malloc(MAX_NODES * sizeof(Node));
    num_nodes = 0;
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(2, 4);
    print_graph();
    return 0;
}