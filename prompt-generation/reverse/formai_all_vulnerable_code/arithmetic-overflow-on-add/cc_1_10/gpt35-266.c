//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 10
#define MAX_EDGES 20

typedef struct node_t {
    int id;
    int voltage;
} Node;

typedef struct edge_t {
    int id;
    Node *src;
    Node *dst;
    int resistance;
    int current;
} Edge;

int main() {
    srand(time(NULL));
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes, num_edges;
    printf("Welcome! This is the Surrealist Circuit Simulator v1.0\n");
    printf("Enter the number of nodes (up to %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    printf("Enter the number of edges (up to %d): ", MAX_EDGES);
    scanf("%d", &num_edges);
    printf("Generating circuit...\n");
    for (int i=0; i<num_nodes; i++) {
        nodes[i].id = i+1;
        nodes[i].voltage = rand() % 10 + 1;
    }
    for (int i=0; i<num_edges; i++) {
        int src, dst, resistance;
        do {
            src = rand() % num_nodes + 1;
            dst = rand() % num_nodes + 1;
        } while (src == dst);
        resistance = rand() % 10 + 1;
        edges[i].id = i+1;
        edges[i].src = &nodes[src-1];
        edges[i].dst = &nodes[dst-1];
        edges[i].resistance = resistance;
        edges[i].current = 0;
        printf("Edge %d: %d -> %d (%d ohms)\n", edges[i].id, src, dst, resistance);
    }
    printf("Circuit generated!\n");
    printf("Starting simulation...\n");
    while (1) {
        printf("\nNodes:\n");
        for (int i=0; i<num_nodes; i++) {
            printf("%d: %dV\n", nodes[i].id, nodes[i].voltage);
        }
        printf("\nEdges:\n");
        for (int i=0; i<num_edges; i++) {
            Edge *edge = &edges[i];
            int voltage_diff = edge->src->voltage - edge->dst->voltage;
            edge->current = voltage_diff / edge->resistance;
            printf("%d -> %d: %dA (%d ohms)\n", edge->src->id, edge->dst->id, edge->current, edge->resistance);
        }
        printf("\nEnter node ID to change voltage (0 to quit): ");
        int node_id, voltage;
        scanf("%d", &node_id);
        if (node_id == 0) break;
        printf("Enter new voltage for node %d: ", node_id);
        scanf("%d", &voltage);
        for (int i=0; i<num_nodes; i++) {
            if (nodes[i].id == node_id) {
                nodes[i].voltage = voltage;
                break;
            }
        }
    }
    printf("Simulation ended. Goodbye!\n");
    return 0;
}