//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAXN 1000
#define MAXM 1000000
#define INF INT_MAX

int n, m, s, t, c;
int graph[MAXN][MAXN];
int dist[MAXN];
int parent[MAXN];
int color[MAXN];

void init() {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        color[i] = rand() % 10;
    }
    dist[s] = 0;
}

void dijkstra(int start) {
    int u, v, min_dist;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]!= INF && dist[j]!= INF) {
                    if (dist[i] > dist[j] + graph[j][i]) {
                        dist[i] = dist[j] + graph[j][i];
                        parent[i] = j;
                    }
                }
            }
        }
    }
}

void print_solution() {
    printf("Vertex\tColor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &s, &t, &c);
        graph[s][t] = c;
    }
    init();
    dijkstra(0);
    printf("Minimum Distance from Source to all other Vertices\n");
    for (int i = 0; i < n; i++) {
        if (i!= s) {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
    printf("\n");
    print_solution();
    return 0;
}