//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 9999

typedef struct {
    int vertex;
    int distance;
    int parent;
} Path;

int graph[MAX_VERTICES][MAX_VERTICES];
int nVertices;

void dijkstra(int start, int end) {
    int i, j, u, v;
    Path path[MAX_VERTICES];
    for (i = 0; i < nVertices; i++) {
        path[i].vertex = i;
        path[i].distance = INF;
        path[i].parent = -1;
    }
    path[start].distance = 0;

    for (i = 0; i < nVertices - 1; i++) {
        for (j = 0; j < nVertices; j++) {
            for (u = 0; u < nVertices; u++) {
                if (graph[j][u]!= INF && path[j].distance!= INF && path[j].distance + graph[j][u] < path[u].distance) {
                    path[u].distance = path[j].distance + graph[j][u];
                    path[u].parent = j;
                }
            }
        }
    }

    printf("Vertex\t Distance\tPath\n");
    printf("-----------------------------\n");
    for (i = 0; i < nVertices; i++) {
        if (i == end) {
            printf("%d\t\t %d\t\t", i, path[i].distance);
            while (path[i].parent!= -1) {
                printf("%d ", path[i].parent);
                i = path[i].parent;
            }
            printf("\n");
        } else {
            printf("%d\t\t %d\t\t", i, path[i].distance);
        }
    }
}

int main() {
    int i, j, u, v, start, end;
    printf("Enter the number of vertices: ");
    scanf("%d", &nVertices);

    printf("Enter the graph:\n");
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("Enter the end vertex: ");
    scanf("%d", &end);

    dijkstra(start, end);

    return 0;
}