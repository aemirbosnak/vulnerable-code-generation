//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define N 8

int dist[N][N];
int parent[N][N];
int n, start, end;

void init_distances() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }
    dist[start][start] = 0;
}

void dijkstra(int start_vertex) {
    int u, v, min_dist;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[start_vertex][j]!= INF && dist[start_vertex][j] + dist[j][i] < dist[start_vertex][i]) {
                dist[start_vertex][i] = dist[start_vertex][j] + dist[j][i];
                parent[start_vertex][i] = j;
            }
        }
    }
}

void print_solution(int end_vertex) {
    int u;
    if (dist[start][end] == INF) {
        printf("No path found\n");
    } else {
        printf("Path: ");
        u = end;
        while (u!= start) {
            printf("%d ", u);
            u = parent[start][u];
        }
        printf("%d\n", start);
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    printf("Enter the end vertex: ");
    scanf("%d", &end);
    init_distances();
    dijkstra(start);
    print_solution(end);
    return 0;
}