//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 99999

typedef struct {
    int id;
    char name[20];
    int x, y;
} node;

typedef struct {
    int u, v, w;
} edge;

node nodes[MAX_NODES];
edge edges[MAX_EDGES];
int n, m, start, end;

void read_nodes() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node %d details:\n", i+1);
        scanf("%d %s %d %d", &nodes[i].id, nodes[i].name, &nodes[i].x, &nodes[i].y);
    }
}

void read_edges() {
    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Enter edge %d details:\n", i+1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
}

void dijkstra(int s) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < n-1; i++) {
        int u = -1, min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int new_dist = dist[u] + edges[get_edge(u, v)].w;

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                }
            }
        }
    }

    printf("Shortest distances from node %d:\n", s);

    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");
}

int get_edge(int u, int v) {
    for (int i = 0; i < m; i++) {
        if (edges[i].u == u && edges[i].v == v) {
            return i;
        }
    }

    return -1;
}

int main() {
    printf("Enter start node ID: ");
    scanf("%d", &start);

    read_nodes();
    read_edges();

    dijkstra(start);

    return 0;
}