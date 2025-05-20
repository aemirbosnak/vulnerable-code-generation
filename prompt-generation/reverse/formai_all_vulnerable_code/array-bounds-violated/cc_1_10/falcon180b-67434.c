//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define INF 9999999

typedef struct {
    int x;
    int y;
} Node;

Node graph[MAX_NODES];
int n;

void read_graph(void) {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for node %d: ", i);
        scanf("%d %d", &graph[i].x, &graph[i].y);
    }
}

void dijkstra(int start, int end) {
    int dist[n];
    int prev[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        int min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int new_dist = dist[u] + abs(graph[u].x - graph[v].x) + abs(graph[u].y - graph[v].y);

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    prev[v] = u;
                }
            }
        }
    }

    printf("Shortest path from node %d to node %d:\n", start, end);
    int v = end;

    while (v!= -1) {
        printf("%d ", v);
        v = prev[v];
    }

    printf("\nTotal distance: %d\n", dist[end]);
}

int main(void) {
    read_graph();

    int start, end;
    printf("Enter start and end nodes: ");
    scanf("%d %d", &start, &end);

    dijkstra(start, end);

    return 0;
}