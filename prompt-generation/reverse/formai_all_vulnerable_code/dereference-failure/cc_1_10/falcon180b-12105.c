//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10
#define M 10
#define INF INT_MAX

int n, m;
int **graph;
int **dist;
int start, end;

void init() {
    srand(time(NULL));
    n = N;
    m = M;
    graph = (int **) malloc(n * sizeof(int *));
    dist = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        graph[i] = (int *) malloc(m * sizeof(int));
        dist[i] = (int *) malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j) {
            graph[i][j] = rand() % 3;
            dist[i][j] = INF;
        }
    }
    start = 0;
    end = n - 1;
}

void print_solution(int **dist) {
    printf("Vertex\t Distance from Source\n");
    for (int v = 0; v < n; v++)
        printf("%d \t\t %d\n", v, dist[v][end]);
}

void dijkstra(int spt, int **graph, int **dist, int n) {
    int u, v, w, min_dist;

    for (int count = 0; count < n - 1; count++) {
        min_dist = INF;
        for (int i = 0; i < n; i++) {
            if (dist[spt][i]!= INF && dist[spt][i] + graph[i][end] < min_dist) {
                min_dist = dist[spt][i] + graph[i][end];
                u = i;
            }
        }

        for (int v = 0; v < n; v++)
            dist[u][v] = dist[spt][v] + graph[u][v];
    }
}

int main() {
    init();
    dijkstra(start, graph, dist, n);
    print_solution(dist);

    return 0;
}