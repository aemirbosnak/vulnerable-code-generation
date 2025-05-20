//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100
#define MAX_E 200

int V, E;
int dist[MAX_V];
int parent[MAX_V];
int adj_list[MAX_V][MAX_V];

void init_graph() {
    int u, v, w;

    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &V, &E);

    printf("Enter the edges with their weights:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &u, &v, &w);
        adj_list[u][v] = w;
        adj_list[v][u] = w;
    }
}

void a_star_search(int start, int end) {
    int u, v;
    int min_dist = INF;
    int min_index = -1;

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        u = min_index;
        for (int j = 0; j < V; j++) {
            v = j;
            if (adj_list[u][v]!= INF && dist[u] + adj_list[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_list[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest path from %d to %d:\n", start, end);
    printf("%d ", end);

    while (parent[end]!= -1) {
        end = parent[end];
        printf("%d ", end);
    }

    printf("\nTotal weight: %d\n", dist[end]);
}

int main() {
    init_graph();
    int start, end;

    printf("Enter the start and end vertices: ");
    scanf("%d%d", &start, &end);

    a_star_search(start, end);

    return 0;
}