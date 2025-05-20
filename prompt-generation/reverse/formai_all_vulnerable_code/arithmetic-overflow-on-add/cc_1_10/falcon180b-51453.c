//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 200

typedef struct {
    int v;
    int w;
} Edge;

Edge graph[MAX_E];
int V, E;

void addEdge(int v, int w) {
    graph[E].v = v;
    graph[E].w = w;
    E++;
}

void DFS(int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    int i;
    for (i = 0; i < V; i++) {
        if (graph[i].v == v &&!visited[graph[i].w]) {
            DFS(graph[i].w, visited);
        }
    }
}

int main() {
    int i;
    scanf("%d %d", &V, &E);
    for (i = 0; i < E; i++) {
        int v, w;
        scanf("%d %d", &v, &w);
        addEdge(v, w);
    }
    int visited[V];
    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, visited);
        }
    }
    return 0;
}