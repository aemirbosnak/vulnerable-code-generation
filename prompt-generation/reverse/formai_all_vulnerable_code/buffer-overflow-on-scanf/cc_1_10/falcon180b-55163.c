//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int adj[MAX_VERTICES][MAX_VERTICES];
int n, m;
int visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int path[MAX_VERTICES];
int path_length[MAX_VERTICES];
int start_time, end_time;

void bellman_ford(int start) {
    int i, j, k, u, v;
    for (i = 0; i < n; i++) {
        path_length[i] = INF;
        parent[i] = -1;
    }
    path_length[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].u;
            v = edges[j].v;
            if (path_length[u]!= INF && path_length[u] + edges[j].w < path_length[v]) {
                path_length[v] = path_length[u] + edges[j].w;
                parent[v] = u;
            }
        }
    }
    for (j = 0; j < m; j++) {
        u = edges[j].u;
        v = edges[j].v;
        if (path_length[u]!= INF && path_length[u] + edges[j].w < path_length[v]) {
            printf("Negative cycle found!\n");
            exit(0);
        }
    }
}

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]!= 0 &&!visited[i]) {
            path[v] = i;
            dfs(i);
        }
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    start_time = clock();
    bellman_ford(0);
    end_time = clock();
    printf("The shortest path from vertex 0 to vertex %d is:\n", n - 1);
    for (i = n - 1; i!= -1; i = parent[i]) {
        printf("%d ", i);
    }
    printf("\nThe length of the shortest path is %d\n", path_length[n - 1]);
    printf("Time taken: %.6f seconds\n", ((double) (end_time - start_time)) / CLOCKS_PER_SEC);
    return 0;
}