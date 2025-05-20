//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 9999

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int num_edges;

void add_edge(int src, int dest, int weight) {
    edges[num_edges].src = src;
    edges[num_edges].dest = dest;
    edges[num_edges].weight = weight;
    num_edges++;
}

void dijkstra(int start_node) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start_node] = 0;

    for (int i = 0; i < MAX_NODES - 1; i++) {
        int u = -1;
        int min_dist = INF;

        for (int j = 0; j < MAX_NODES; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < MAX_NODES; v++) {
            if (!visited[v]) {
                int new_dist = dist[u] + edges[v * MAX_NODES + u].weight;

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                }
            }
        }
    }

    printf("Node\tDistance from Source\n");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int num_nodes, num_edges;

    scanf("%d %d", &num_nodes, &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(src, dest, weight);
    }

    int start_node;
    scanf("%d", &start_node);

    dijkstra(start_node);

    return 0;
}