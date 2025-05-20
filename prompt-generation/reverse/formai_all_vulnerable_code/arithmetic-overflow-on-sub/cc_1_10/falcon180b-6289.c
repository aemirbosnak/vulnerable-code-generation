//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mathematical
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 1000
#define INF INT_MAX

typedef struct {
    int v;
    int w;
    int next;
} Edge;

Edge graph[MAX_V][MAX_E];
int dist[MAX_V];
int parent[MAX_V];
int nV, nE;

void init() {
    int i, j;
    for (i = 0; i < nV; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[0] = 0;
}

void addEdge(int u, int v, int w) {
    Edge e = {v, w, -1};
    graph[u][nE++] = e;
    Edge e2 = {u, w, -1};
    graph[v][nE++] = e2;
}

void aStar() {
    int i, u, v;
    for (i = 0; i < nV - 1; i++) {
        u = -1;
        for (int j = 0; j < nV; j++) {
            if (dist[j] < dist[u]) {
                u = j;
            }
        }
        if (u == -1) {
            break;
        }
        int minD = INF;
        for (int j = 0; j < nE; j++) {
            v = graph[u][j].v;
            int alt = dist[u] + graph[u][j].w;
            if (alt < dist[v]) {
                dist[v] = alt;
                parent[v] = u;
            }
        }
    }
}

void printPath(int v) {
    if (v == -1) {
        return;
    }
    printPath(parent[v]);
    printf("%d ", v);
}

int main() {
    int i, u, v, w;
    scanf("%d %d", &nV, &nE);
    for (i = 0; i < nE; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    init();
    aStar();
    printf("Shortest path: ");
    printPath(nV - 1);
    printf("\n");
    return 0;
}