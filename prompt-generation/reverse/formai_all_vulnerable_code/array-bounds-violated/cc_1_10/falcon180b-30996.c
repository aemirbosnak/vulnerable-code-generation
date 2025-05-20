//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 999999

typedef struct {
    int node;
    int weight;
} edge;

edge graph[MAX_EDGES];
int num_edges;
int num_nodes;

int heuristic(int a, int b) {
    return abs(a - b);
}

void dijkstra(int start_node, int end_node) {
    int i, j, k;
    int visited[MAX_NODES];
    int dist[MAX_NODES];
    int parent[MAX_NODES];
    int u, v;

    for (i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start_node] = 0;

    for (i = 0; i < num_nodes - 1; i++) {
        int min_dist = INF;
        int min_node = -1;

        for (j = 0; j < num_nodes; j++) {
            if (dist[j] < min_dist &&!visited[j]) {
                min_dist = dist[j];
                min_node = j;
            }
        }

        visited[min_node] = 1;

        for (j = 0; j < num_edges; j++) {
            u = graph[j].node;
            v = graph[j].weight;

            if (dist[min_node] + heuristic(min_node, v) < dist[v]) {
                dist[v] = dist[min_node] + heuristic(min_node, v);
                parent[v] = min_node;
            }
        }
    }

    printf("Shortest path: ");
    k = end_node;

    while (k!= -1) {
        printf("%d ", k);
        k = parent[k];
    }

    printf("\n");
}

int main() {
    int i, j, k;
    int start_node, end_node;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++) {
        printf("Enter the node and weight for edge %d: ", i + 1);
        scanf("%d %d", &graph[i].node, &graph[i].weight);
    }

    printf("Enter the start node: ");
    scanf("%d", &start_node);

    printf("Enter the end node: ");
    scanf("%d", &end_node);

    dijkstra(start_node, end_node);

    return 0;
}