//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000
#define INF 999999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int num_edges = 0;

int adj_list[MAX_NODES][MAX_NODES];
int num_nodes = 0;

void add_edge(int u, int v, int w) {
    edges[num_edges++] = (Edge) {u, v, w};
    adj_list[u][v] = w;
}

void dijkstra(int start) {
    int i, j, k, u, v;
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < num_nodes - 1; i++) {
        for (j = 0; j < num_nodes; j++) {
            for (k = 0; k < num_edges; k++) {
                if (edges[k].u == j && edges[k].v == i && dist[j]!= INF && dist[j] + edges[k].w < dist[i]) {
                    dist[i] = dist[j] + edges[k].w;
                }
            }
        }
    }

    printf("Node\t Distance from Source\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, k, u, v, w;
    char ch;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++) {
        printf("Enter the details of edge %d:\n", i + 1);
        printf("Enter the source node: ");
        scanf("%d", &u);
        printf("Enter the destination node: ");
        scanf("%d", &v);
        printf("Enter the weight of the edge: ");
        scanf("%d", &w);
        add_edge(u, v, w);
    }

    printf("Enter the starting node for Dijkstra's algorithm: ");
    scanf("%d", &k);

    dijkstra(k);

    return 0;
}