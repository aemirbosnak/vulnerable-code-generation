//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000
#define INF 9999

typedef struct {
    int u, v;
    int weight;
} Edge;

int dist[MAX_NODES];
int prev[MAX_NODES];
int n, m;

void dijkstra(int start, int end) {
    int i, j, u, v;
    int min_dist = INF, u_min;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n-1; i++) {
        min_dist = INF;
        u_min = -1;

        for (j = 0; j < n; j++) {
            if (dist[j] < min_dist && prev[j]!= -1) {
                min_dist = dist[j];
                u_min = j;
            }
        }

        for (v = 0; v < n; v++) {
            if ((dist[u_min] + dist[v]) < dist[v]) {
                dist[v] = dist[u_min] + dist[v];
                prev[v] = u_min;
            }
        }
    }

    printf("Shortest Path: ");
    for (i = end; i!= -1; i = prev[i]) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int i, j, u, v, w;
    Edge graph[MAX_EDGES];

    srand(time(NULL));

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the start node: ");
        scanf("%d", &u);

        printf("Enter the end node: ");
        scanf("%d", &v);

        printf("Enter the weight: ");
        scanf("%d", &w);

        graph[i].u = u;
        graph[i].v = v;
        graph[i].weight = w;
    }

    dijkstra(0, n-1);

    return 0;
}