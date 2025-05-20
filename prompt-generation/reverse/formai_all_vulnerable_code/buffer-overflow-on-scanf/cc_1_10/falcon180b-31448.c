//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 99999
#define NO_PARENT -1

int adj_matrix[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int visited[MAX_NODES];
int parent[MAX_NODES];

void dijkstra(int source) {
    int i, u, v, min_dist;

    for (i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
        parent[i] = NO_PARENT;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (i = 0; i < MAX_NODES - 1; i++) {
        min_dist = INF;
        u = -1;

        for (int j = 0; j < MAX_NODES; j++) {
            if (!visited[j] && dist[j] <= min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < MAX_NODES; v++) {
            if (!visited[v] && adj_matrix[u][v] && dist[u]!= INF && dist[u] + adj_matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_matrix[u][v];
                parent[v] = u;
            }
        }
    }
}

void print_solution(int dest) {
    int v = dest;

    if (parent[dest] == NO_PARENT) {
        printf("No path found between %d and %d\n", 0, dest);
        return;
    }

    printf("Shortest path from node %d to node %d: ", 0, dest);

    do {
        printf("%d ", v);
        v = parent[v];
    } while (v!= NO_PARENT);

    printf("\n");
}

int main() {
    int i, j, k, source, dest;

    printf("Enter the number of nodes: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("Enter the destination node: ");
    scanf("%d", &dest);

    print_solution(dest);

    return 0;
}