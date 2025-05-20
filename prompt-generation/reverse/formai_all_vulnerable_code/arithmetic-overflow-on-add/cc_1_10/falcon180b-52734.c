//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 99999

int graph[MAX_NODES][MAX_EDGES];
int n, m;
int visited[MAX_NODES];
int dist[MAX_NODES];
int parent[MAX_NODES];
int start_node, end_node;

void dijkstra(int start) {
    int i, j, k, u, v, w;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                u = j;
                v = graph[j][k];
                w = graph[j][k];
                if (dist[u]!= INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
}

void print_path(int end) {
    int temp = end_node;
    if (parent[end_node]!= -1) {
        while (temp!= start_node) {
            printf("%d ", temp);
            temp = parent[temp];
        }
        printf("%d\n", start_node);
    } else {
        printf("No path found.\n");
    }
}

int main() {
    int i, j, k, u, v, w;
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the start node: ");
    scanf("%d", &start_node);
    printf("Enter the end node: ");
    scanf("%d", &end_node);
    printf("Enter the edges and their weights:\n");
    for (i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u][k++] = v;
        graph[v][k++] = u;
    }
    dijkstra(start_node);
    print_path(end_node);
    return 0;
}