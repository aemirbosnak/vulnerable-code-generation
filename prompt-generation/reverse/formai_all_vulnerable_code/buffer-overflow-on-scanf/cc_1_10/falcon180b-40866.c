//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define INF 9999

int n;
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int parent[MAX_NODES];

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 3;
        }
    }
}

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (graph[j][k]!= INF && dist[j]!= INF && dist[j] + graph[j][k] < dist[k]) {
                    dist[k] = dist[j] + graph[j][k];
                    parent[k] = j;
                }
            }
        }
    }
}

void print_path(int end) {
    if (parent[end] == -1) {
        printf("No path found.\n");
        return;
    }

    printf("Path: ");
    int node = end;
    while (node!= -1) {
        printf("%d ", node);
        node = parent[node];
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    n = rand() % MAX_NODES + 2;

    init();

    int start, end;
    printf("Enter start node: ");
    scanf("%d", &start);
    printf("Enter end node: ");
    scanf("%d", &end);

    dijkstra(start);
    print_path(end);

    return 0;
}