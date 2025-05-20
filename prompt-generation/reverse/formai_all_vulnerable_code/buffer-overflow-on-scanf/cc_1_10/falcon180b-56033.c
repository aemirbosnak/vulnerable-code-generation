//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 999

int n, m;
int adj_matrix[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int prev[MAX_NODES];
int start_time;

void dijkstra(int start) {
    int i, j, u, v;
    int min_dist = INF, min_node;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        min_node = -1;

        for (j = 0; j < n; j++) {
            if (dist[j] <= min_dist && prev[j]!= -1) {
                min_dist = dist[j];
                min_node = j;
            }
        }

        u = min_node;

        for (v = 0; v < n; v++) {
            if (adj_matrix[u][v]!= INF && dist[u]!= INF && dist[u] + adj_matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_matrix[u][v];
                prev[v] = u;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int i, j, u, v, w, start;

    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &n, &m);

    srand(time(NULL));

    for (i = 0; i < m; i++) {
        printf("Enter the start and end vertices and weight for edge %d: ", i + 1);
        scanf("%d%d%d", &u, &v, &w);

        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    start_time = clock();
    dijkstra(0);
    printf("\nExecution time: %f seconds\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);

    return 0;
}