//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_V 100
#define MAX_E 200

typedef struct {
    int v;
    int w;
    int weight;
} Edge;

int V, E;
Edge graph[MAX_E];
int dist[MAX_V];
int parent[MAX_V];

void dijkstra(int start) {
    int i, j, u, v;
    int min_dist = 99999;

    for (i = 0; i < V; i++) {
        dist[i] = 99999;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < V - 1; i++) {
        min_dist = 99999;
        for (j = 0; j < V; j++) {
            if (dist[j] <= min_dist && parent[j]!= -1) {
                u = j;
                min_dist = dist[j];
            }
        }

        for (j = 0; j < V; j++) {
            if (graph[u].v == j && dist[u]!= 99999 && dist[u] + graph[u].weight < dist[j]) {
                dist[j] = dist[u] + graph[u].weight;
                parent[j] = u;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges with their weights:\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[i].v = v;
        graph[i].w = u;
        graph[i].weight = w;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}