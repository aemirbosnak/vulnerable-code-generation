//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int connected;
    int edges[MAX_EDGES];
    int num_edges;
} Node;

int main() {
    int num_nodes, num_edges, i, j;
    Node nodes[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i);
        scanf("%s", nodes[i].name);
        nodes[i].connected = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++) {
        printf("Enter the nodes for edge %d (separated by space): ", i);
        scanf("%s", nodes[0].name);
        scanf("%s", nodes[1].name);
        nodes[0].edges[nodes[0].num_edges++] = i;
        nodes[1].edges[nodes[1].num_edges++] = i;
        nodes[0].connected = 1;
        nodes[1].connected = 1;
    }

    for (i = 0; i < num_nodes; i++) {
        if (!nodes[i].connected) {
            printf("Node %s is not connected to any other nodes.\n", nodes[i].name);
        }
    }

    for (i = 0; i < num_nodes; i++) {
        if (nodes[i].connected) {
            printf("Connected nodes for %s:\n", nodes[i].name);
            for (j = 0; j < nodes[i].num_edges; j++) {
                printf("  Edge %d\n", nodes[i].edges[j]);
            }
        }
    }

    return 0;
}