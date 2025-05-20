//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 999999

typedef struct {
    int id;
    int weight;
    int dest;
} Edge;

typedef struct {
    int id;
    int visited;
    int dist;
    int parent;
} Node;

Edge graph[MAX_EDGES];
Node dist[MAX_NODES];

int numEdges = 0;
int numNodes = 0;

void addEdge(int u, int v, int w) {
    graph[numEdges].id = numEdges;
    graph[numEdges].dest = v;
    graph[numEdges].weight = w;
    numEdges++;
}

void dijkstra(int start) {
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < numNodes; i++) {
        dist[i].dist = INF;
        dist[i].visited = false;
    }

    dist[start].dist = 0;
    for (int i = 0; i < numNodes - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = graph[j].dest;
            int v = graph[j].id;
            int w = graph[j].weight;

            if (dist[u].dist!= INF && dist[u].dist + w < dist[v].dist) {
                dist[v].dist = dist[u].dist + w;
                dist[v].parent = u;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    numNodes = n;
    numEdges = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int start;
    scanf("%d", &start);

    dijkstra(start);

    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < numNodes; i++) {
        if (dist[i].visited)
            printf("%d \t %d\n", i, dist[i].dist);
    }

    return 0;
}