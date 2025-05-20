//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

struct Node {
    char name[20];
    int id;
    int degree;
    struct Edge *adj_list[MAX_EDGES];
};

struct Edge {
    int weight;
    struct Node *node;
};

void add_edge(struct Node *node1, struct Node *node2, int weight) {
    struct Edge *edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->node = node2;
    edge->weight = weight;
    node1->adj_list[node1->degree++] = edge;
}

void print_graph(struct Node *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s (%d):\n", nodes[i].name, nodes[i].id);
        for (int j = 0; j < nodes[i].degree; j++) {
            printf("\t%s (%d) -> %d\n", nodes[i].adj_list[j]->node->name, nodes[i].adj_list[j]->node->id, nodes[i].adj_list[j]->weight);
        }
    }
}

int main() {
    struct Node nodes[MAX_NODES];
    int num_nodes = 0;

    printf("Enter the number of nodes:\n");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name, ID, and number of edges for node %d:\n", i+1);
        scanf("%s %d %d", nodes[i].name, &nodes[i].id, &nodes[i].degree);
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the edges for node %s:\n", nodes[i].name);
        int num_edges = 0;
        while (scanf("%s %d %d", nodes[i].adj_list[num_edges]->node->name, &nodes[i].adj_list[num_edges]->node->id, &nodes[i].adj_list[num_edges]->weight)!= EOF) {
            num_edges++;
        }
        nodes[i].degree = num_edges;
    }

    print_graph(nodes, num_nodes);

    return 0;
}