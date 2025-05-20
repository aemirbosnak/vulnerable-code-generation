//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 9999999

typedef struct {
    int node;
    int cost;
    int next;
} Edge;

int num_nodes, num_edges;
int *node_to_index;
Edge *edges;

void dijkstra(int start_node) {
    int i, u, v, min_dist;
    int *dist = calloc(num_nodes, sizeof(int));
    int *visited = calloc(num_nodes, sizeof(int));

    for (i = 0; i < num_nodes; i++) {
        dist[i] = INF;
    }

    dist[start_node] = 0;

    for (i = 0; i < num_nodes - 1; i++) {
        min_dist = INF;
        for (u = 0; u < num_nodes; u++) {
            if (!visited[u] && dist[u] < min_dist) {
                min_dist = dist[u];
                v = u;
            }
        }

        visited[v] = 1;

        for (u = 0; u < num_nodes; u++) {
            if (!visited[u] && edges[v*num_nodes+u].cost + dist[v] < dist[u]) {
                dist[u] = edges[v*num_nodes+u].cost + dist[v];
            }
        }
    }

    printf("Node\tDistance from Start Node\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, cost;

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    node_to_index = calloc(num_nodes, sizeof(int));
    edges = calloc(num_nodes*num_nodes, sizeof(Edge));

    printf("Enter edges (node1 node2 cost):\n");

    for (i = 0; i < num_nodes; i++) {
        node_to_index[i] = i;
    }

    for (i = 0; i < num_nodes*num_nodes; i++) {
        scanf("%d%d%d", &u, &v, &cost);
        edges[i].node = v;
        edges[i].cost = cost;
        edges[i].next = node_to_index[u];
        node_to_index[u] = i;
    }

    dijkstra(0);

    return 0;
}