//Falcon-180B DATASET v1.0 Category: Data mining ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define TRUE 1
#define FALSE 0
#define INF 99999

typedef struct {
    int vertex;
    int weight;
} Edge;

Edge graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int dist[MAX];
int n; // number of vertices
int m; // number of edges

void dijkstra(int start_vertex);

int main() {
    int i, j, u, v, w;
    FILE *fp;
    fp = fopen("graph.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j].vertex = -1;
            graph[i][j].weight = INF;
        }
    }

    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d %d", &u, &v, &w);
        graph[u][v].vertex = v;
        graph[u][v].weight = w;
        graph[v][u].vertex = u;
        graph[v][u].weight = w;
    }

    int start_vertex = 0; // set the starting vertex
    dijkstra(start_vertex);

    return 0;
}

void dijkstra(int start_vertex) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = FALSE;
        parent[i] = -1;
    }

    dist[start_vertex] = 0;
    visited[start_vertex] = TRUE;

    for (i = 0; i < n - 1; i++) {
        int min_dist = INF;
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        visited[u] = TRUE;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v].vertex!= -1 && dist[u]!= INF && dist[u] + graph[u][v].weight < dist[v]) {
                dist[v] = dist[u] + graph[u][v].weight;
                parent[v] = u;
            }
        }
    }

    printf("Vertex\t Distance\tPath\n");
    for (i = 0; i < n; i++) {
        if (i!= start_vertex) {
            printf("%d\t\t%d\t", i, dist[i]);
            int v = i;
            while (v!= -1) {
                printf("%d ", v);
                v = parent[v];
            }
            printf("\n");
        }
    }
}