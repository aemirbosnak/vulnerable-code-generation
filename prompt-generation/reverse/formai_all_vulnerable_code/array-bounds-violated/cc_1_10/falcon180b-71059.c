//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX 1000
#define INF INT_MAX

int n, m, u, v, w, i, j, k, ans, max_ans;
int dist[MAX][MAX];
int parent[MAX][MAX];

void init() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = INF;
            parent[i][j] = -1;
        }
    }
}

void prim() {
    int min_dist = INF, u = 0, v = -1;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        u = 0;

        for (j = 0; j < n; j++) {
            if (dist[u][j] < min_dist) {
                min_dist = dist[u][j];
                v = j;
            }
        }

        for (k = 0; k < n; k++) {
            if (dist[u][k] + dist[k][v] < dist[u][v]) {
                dist[u][v] = dist[u][k] + dist[k][v];
                parent[u][v] = k;
            }
        }
    }
}

void print_solution() {
    printf("Vertex\t Distance from Source\n");

    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[0][i]);
    }
}

int main() {
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges with their weights:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    init();

    for (i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    prim();

    printf("\nMinimum Spanning Tree:\n");
    print_solution();

    return 0;
}