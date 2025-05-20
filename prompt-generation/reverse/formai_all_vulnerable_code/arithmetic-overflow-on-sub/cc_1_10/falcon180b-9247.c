//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct Edge {
    int u, v, w;
};

struct Node {
    int id;
    int dist;
    int parent;
};

void dijkstra(int start_node, int n, struct Edge edges[], int node_dist[], int parent[]) {
    int i, u, v;
    struct Node *dist = (struct Node *) malloc(n * sizeof(struct Node));
    for (i = 0; i < n; i++) {
        dist[i].id = i;
        dist[i].dist = INF;
        dist[i].parent = -1;
    }
    dist[start_node].dist = 0;
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (dist[u].dist!= INF && dist[u].dist + edges[i].w < dist[v].dist) {
                    dist[v].dist = dist[u].dist + edges[i].w;
                    dist[v].parent = u;
                }
            }
        }
    }
    free(dist);
}

int main() {
    srand(time(NULL));
    int n, m, i, u, v, w;
    scanf("%d %d", &n, &m);
    struct Edge edges[m];
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    int start_node;
    do {
        start_node = rand() % n;
    } while (start_node == 0);
    int node_dist[n];
    int parent[n];
    dijkstra(start_node, n, edges, node_dist, parent);
    printf("Shortest Path from Node %d:\n", start_node);
    for (i = 0; i < n; i++) {
        if (node_dist[i]!= INF) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}