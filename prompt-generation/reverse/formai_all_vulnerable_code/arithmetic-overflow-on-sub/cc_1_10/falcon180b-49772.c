//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 5000
#define INVALID -1

typedef struct {
    int vertex;
    int weight;
    int next;
} Edge;

int graph[MAX_VERTEX][MAX_VERTEX];
Edge edges[MAX_EDGE];

int n, m, start, end, i, j, k, u, v, w;

void dijkstra(int start) {
    int dist[MAX_VERTEX];
    int visited[MAX_VERTEX] = {0};
    int parent[MAX_VERTEX] = {INVALID};

    for (i = 0; i < n; i++) {
        dist[i] = INVALID;
    }

    dist[start] = 0;

    for (k = 0; k < n - 1; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (graph[i][j]!= INVALID && dist[i]!= INVALID && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                    parent[j] = i;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    printf("-----------------------------------\n");

    for (i = 0; i < n; i++) {
        if (dist[i]!= INVALID) {
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}

void addEdge() {
    int u, v, w;

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges in the form of (u, v, w):\n");

    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);

        edges[i].vertex = v;
        edges[i].weight = w;
        edges[i].next = graph[u][v];
        graph[u][v] = i;
    }
}

int main() {
    int choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    addEdge();

    printf("Enter the source vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}