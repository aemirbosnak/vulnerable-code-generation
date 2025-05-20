//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 99999

int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int visited[MAX_NODES];
int parent[MAX_NODES];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
}

void prim(int start) {
    int count = 0;
    int u = start;
    int v;
    int min_dist = INF;
    int k;

    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < MAX_NODES - 1; i++) {
        min_dist = INF;
        for (int j = 0; j < MAX_NODES; j++) {
            if (graph[j][u]!= INF && dist[j] > dist[u] && dist[j] < min_dist) {
                min_dist = dist[j];
                v = j;
            }
        }

        graph[u][v] = min_dist;
        graph[v][u] = min_dist;

        count++;
    }
}

void print_solution(int n) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    initialize(n);

    printf("Enter the edges and their weights:\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    prim(0);

    print_solution(n);

    return 0;
}