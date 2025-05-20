//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 1000
#define MAX_NODES 1000
#define INF 99999

typedef struct {
    int x, y;
} Node;

Node graph[MAX_NODES];
int n;

void addEdge(int u, int v, int w) {
    graph[u].x = v;
    graph[u].y = w;
}

void dijkstra(int start) {
    int dist[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[j] > dist[i] + graph[i].y) {
                dist[j] = dist[i] + graph[i].y;
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, k, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        printf("Enter the start node and end node for edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        printf("Enter the weight of the edge: ");
        scanf("%d", &w);
        addEdge(u, v, w);
    }

    printf("Enter the starting node: ");
    scanf("%d", &u);

    dijkstra(u);

    return 0;
}