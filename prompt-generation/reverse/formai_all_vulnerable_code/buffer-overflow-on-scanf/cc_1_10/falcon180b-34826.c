//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define INF 9999

typedef struct {
    int u;
    int v;
    int w;
} Edge;

Edge graph[MAX_EDGES];
int n;
int dist[MAX_NODES];

void init() {
    int i;
    for (i = 0; i < MAX_EDGES; i++) {
        graph[i].u = -1;
        graph[i].v = -1;
        graph[i].w = -1;
    }
    for (i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
    }
}

void addEdge(int u, int v, int w) {
    graph[n].u = u;
    graph[n].v = v;
    graph[n].w = w;
    n++;
}

void dijkstra(int start) {
    int i, j, u, v;
    int minDist = 0;
    int count = 0;

    dist[start] = 0;

    for (i = 0; i < n - 1 && count < MAX_NODES - 1; i++) {
        minDist = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (dist[graph[j].u]!= INF && graph[j].v!= -1 && dist[graph[j].u] + graph[j].w < minDist) {
                minDist = dist[graph[j].u] + graph[j].w;
                u = graph[j].v;
            }
        }

        if (u!= -1) {
            dist[u] = minDist;
            count++;
        }
    }
}

int main() {
    int i, j;
    int start, end;

    srand(time(NULL));

    n = rand() % MAX_EDGES;

    for (i = 0; i < n; i++) {
        addEdge(rand() % MAX_NODES, rand() % MAX_NODES, rand() % 100);
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    printf("Shortest path from %d to %d: %d\n", start, end, dist[end]);

    return 0;
}