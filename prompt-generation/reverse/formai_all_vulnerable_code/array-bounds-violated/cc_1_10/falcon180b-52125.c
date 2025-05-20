//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 6
#define S 2

int graph[V][V];
int dist[V];
int parent[V];

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = rand() % 100;
        }
    }
}

void dijkstra(int start) {
    int i, u, v;
    int min_dist = INF, min_u = -1;

    for (i = 0; i < V; i++) {
        dist[i] = graph[start][i];
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 1; i < V; i++) {
        min_dist = INF;
        min_u = -1;

        for (u = 0; u < V; u++) {
            if (dist[u]!= INF && dist[u] + graph[u][i] < min_dist) {
                min_dist = dist[u] + graph[u][i];
                min_u = u;
            }
        }

        if (min_u!= -1) {
            dist[i] = min_dist;
            parent[i] = min_u;
        }
    }
}

void print_solution(int end) {
    int v = end;

    printf("Vertex\t Distance from Source\tPath\n");
    printf("------------------\t--------------------\t-----\n");

    while (v!= -1) {
        printf("%d \t\t %d \t\t", v, dist[v]);
        if (parent[v]!= -1)
            printf("-> %d", parent[v]);
        else
            printf("-> Start");
        printf("\n");
        v = parent[v];
    }
}

int main() {
    int start, end;
    srand(time(NULL));
    init_graph();

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Enter the ending vertex: ");
    scanf("%d", &end);

    print_solution(end);

    return 0;
}