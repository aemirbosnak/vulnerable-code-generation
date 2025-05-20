//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

int adj_matrix[MAX_NODES][MAX_NODES];

void add_edge(int u, int v, int weight) {
    adj_matrix[u][v] = weight;
    adj_matrix[v][u] = weight;
}

void dijkstra(int start_node) {
    int n = 0;
    int distances[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INF;
        visited[i] = 0;
    }

    distances[start_node] = 0;

    for (int i = 1; i < MAX_NODES; i++) {
        int min_distance = INF;
        int u = -1;

        for (int j = 0; j < MAX_NODES; j++) {
            if (distances[j] < min_distance && visited[j] == 0) {
                min_distance = distances[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < MAX_NODES; v++) {
            if (adj_matrix[u][v] > 0 && visited[v] == 0) {
                int new_distance = distances[u] + adj_matrix[u][v];

                if (new_distance < distances[v]) {
                    distances[v] = new_distance;
                }
            }
        }
    }

    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d -> %d: %d\n", start_node, i, distances[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            adj_matrix[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(u, v, weight);
    }

    int start_node;
    scanf("%d", &start_node);

    dijkstra(start_node);

    return 0;
}