//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define INF 9999

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

int n, m;
int adj_matrix[MAX_NODES][MAX_NODES];
Edge edges[MAX_EDGES];

void add_edge(int src, int dest, int weight) {
    adj_matrix[src][dest] = weight;
    adj_matrix[dest][src] = weight;
    edges[m].src = src;
    edges[m].dest = dest;
    edges[m].weight = weight;
    m++;
}

void dijkstra(int start) {
    int i, j, u, v;
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (u = 0; u < m; u++) {
                if (edges[u].src == j && edges[u].dest == i && dist[j]!= INF && dist[j] + edges[u].weight < dist[i]) {
                    dist[i] = dist[j] + edges[u].weight;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges with their weights:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    dijkstra(0);

    return 0;
}