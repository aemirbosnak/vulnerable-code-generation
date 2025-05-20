//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 999999
#define MAX_V 100
#define MAX_E 500

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_E];
int n, m, s, d;
int dist[MAX_V];
int parent[MAX_V];

void dijkstra(int start) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    int openSet[MAX_V];
    int openSetSize = 0;
    int closedSet[MAX_V];
    int closedSetSize = 0;
    openSet[openSetSize++] = start;

    while (openSetSize > 0) {
        int currNode = -1;
        for (i = 0; i < openSetSize; i++) {
            u = openSet[i];
            if (currNode == -1 || dist[u] < dist[currNode]) {
                currNode = u;
            }
        }
        if (currNode == -1) {
            break;
        }
        openSetSize--;
        closedSet[closedSetSize++] = currNode;

        int v;
        for (v = 0; v < n; v++) {
            if (edges[currNode * n + v].w > 0) {
                int newDist = dist[currNode] + edges[currNode * n + v].w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = currNode;
                }
            }
        }
    }
}

int main() {
    int i;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u, v, weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter start vertex: ");
    scanf("%d", &s);

    dijkstra(s);

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }

    printf("\nPath: ");
    int v = d;
    while (v!= -1) {
        printf("%d ", v);
        v = parent[v];
    }
    printf("\n");

    return 0;
}