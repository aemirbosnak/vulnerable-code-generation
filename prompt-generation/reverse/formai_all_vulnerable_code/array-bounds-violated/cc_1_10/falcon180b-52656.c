//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999
#define EPSILON 0.000001

typedef struct {
    int from;
    int to;
    int cost;
} Edge;

Edge edges[MAX_EDGES];
int nEdges = 0;

void addEdge(int from, int to, int cost) {
    edges[nEdges++] = (Edge) {.from = from,.to = to,.cost = cost};
}

int dist[MAX_NODES];

void dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;

    for (int i = 0; i < nEdges; i++) {
        Edge e = edges[i];
        int u = e.from;
        int v = e.to;
        int c = e.cost;

        if (dist[u]!= INF && dist[u] + c < dist[v]) {
            dist[v] = dist[u] + c;
        }
    }
}

void printSolution(int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Enter the edges (u, v, w): ");
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);
    printSolution(n);

    return 0;
}