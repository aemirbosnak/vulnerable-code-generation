//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10
#define INF 99999

int nVerts;
int graph[MAX_VERTS][MAX_VERTS];
int dist[MAX_VERTS];
int prev[MAX_VERTS];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < nVerts; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;

    for (i = 0; i < nVerts - 1; i++) {
        for (j = 0; j < nVerts; j++) {
            for (u = 0; u < nVerts; u++) {
                if (dist[u]!= INF && dist[u] + graph[u][j] < dist[j]) {
                    dist[j] = dist[u] + graph[u][j];
                    prev[j] = u;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < nVerts; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &nVerts);

    printf("Enter the edges and their weights (u, v, w):\n");
    for (i = 0; i < nVerts; i++) {
        for (j = 0; j < nVerts; j++) {
            graph[i][j] = INF;
        }
    }

    int m;
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}