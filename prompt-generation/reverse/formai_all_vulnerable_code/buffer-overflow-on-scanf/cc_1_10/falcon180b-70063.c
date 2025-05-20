//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODE 100
#define INF INT_MAX

int dist[NODE][NODE];
int parent[NODE][NODE];

void initDist() {
    for (int i = 0; i < NODE; i++) {
        for (int j = 0; j < NODE; j++) {
            dist[i][j] = INF;
        }
    }
}

void initParent() {
    for (int i = 0; i < NODE; i++) {
        for (int j = 0; j < NODE; j++) {
            parent[i][j] = -1;
        }
    }
}

void dijkstra(int start, int end) {
    initDist();
    initParent();

    dist[start][end] = 0;

    for (int i = 0; i < NODE; i++) {
        int u = -1, minDist = INF;
        for (int j = 0; j < NODE; j++) {
            if (dist[i][j] < minDist) {
                minDist = dist[i][j];
                u = j;
            }
        }
        for (int k = 0; k < NODE; k++) {
            if (dist[i][k] > dist[i][u] + dist[u][k]) {
                dist[i][k] = dist[i][u] + dist[u][k];
                parent[i][k] = u;
            }
        }
    }

    int path[NODE];
    int v = end;
    int count = 0;
    while (v!= -1) {
        path[count++] = v;
        v = parent[v][end];
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    int start, end;
    printf("Enter start node: ");
    scanf("%d", &start);
    printf("Enter end node: ");
    scanf("%d", &end);

    dijkstra(start, end);

    return 0;
}