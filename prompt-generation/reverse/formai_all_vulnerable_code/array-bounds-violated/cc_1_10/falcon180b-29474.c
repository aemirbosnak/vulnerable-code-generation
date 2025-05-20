//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 999999

int graph[MAX_NODES][MAX_NODES];

void initGraph(int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            graph[i][j] = INF;
        }
    }
}

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void dijkstra(int start, int end) {
    int n = 0;
    int i, j, k;
    int dist[MAX_NODES];
    int prev[MAX_NODES];
    int u, v;

    for(i=0; i<MAX_NODES; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;
    int minDist = INF;

    for(i=0; i<MAX_NODES-1; i++) {
        minDist = INF;
        u = -1;

        for(j=0; j<MAX_NODES; j++) {
            if(dist[j] < minDist && prev[j]!= -1) {
                minDist = dist[j];
                u = j;
            }
        }

        for(k=0; k<MAX_NODES; k++) {
            if(graph[u][k]!= INF && dist[u] + graph[u][k] < dist[k]) {
                dist[k] = dist[u] + graph[u][k];
                prev[k] = u;
            }
        }
    }

    printf("Shortest path from node %d to node %d:\n", start, end);
    i = end;
    while(i!= -1) {
        printf("%d ", i);
        i = prev[i];
    }
    printf("\n");
}

int main() {
    int n, m, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    initGraph(n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v w):\n");
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int start, end;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    dijkstra(start, end);

    return 0;
}