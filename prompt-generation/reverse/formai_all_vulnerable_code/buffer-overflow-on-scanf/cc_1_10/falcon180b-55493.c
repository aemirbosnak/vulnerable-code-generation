//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_LABEL_LENGTH 50

typedef struct {
    char label[MAX_LABEL_LENGTH];
    int num_edges;
    int *edges;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void add_edge(Edge *edges, int num_edges, int src, int dest, int weight) {
    edges[num_edges].src = src;
    edges[num_edges].dest = dest;
    edges[num_edges].weight = weight;
    num_edges++;
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    Node *nodes = (Node *) malloc(num_nodes * sizeof(Node));
    Edge *edges = (Edge *) malloc(num_edges * sizeof(Edge));

    for (int i = 0; i < num_nodes; i++) {
        scanf("%s", nodes[i].label);
        nodes[i].num_edges = 0;
        nodes[i].edges = NULL;
    }

    for (int i = 0; i < num_edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(edges, i, src, dest, weight);
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("%s: ", nodes[i].label);
        for (int j = 0; j < num_edges; j++) {
            if (edges[j].src == i) {
                printf("%d ", edges[j].dest);
            }
        }
        printf("\n");
    }

    return 0;
}