//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int to;
    int cost;
};

typedef struct Edge Edge;

void bellmanFord(int n, Edge *edges, int start, int *dist) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dist[j]!= INF && dist[j] + edges[k].cost < dist[k]) {
                    dist[k] = dist[j] + edges[k].cost;
                }
            }
        }
    }
}

int main() {
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        edges[i].to = v;
        edges[i].cost = c;
    }

    int *dist = (int *)malloc(n * sizeof(int));

    bellmanFord(n, edges, start, dist);

    printf("Vertex\t Distance from Source\n");

    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    free(edges);
    free(dist);

    return 0;
}