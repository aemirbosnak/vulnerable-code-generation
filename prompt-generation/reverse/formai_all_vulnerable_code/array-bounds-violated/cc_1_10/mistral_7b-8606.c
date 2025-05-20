//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertex;
    int distance;
} Edge;

typedef struct {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];
} SPT;

void printSolution(int src, SPT set) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (!set.sptSet[i])
            continue;
        printf("%d \t %d\n", i, set.dist[i]);
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src) {
    SPT spT;
    int i, minDist, v, u;

    for (i = 0; i < MAX_VERTICES; ++i) {
        spT.dist[i] = INT_MAX;
        spT.sptSet[i] = false;
    }

    spT.dist[src] = 0;

    for (i = 0; i < MAX_VERTICES - 1; ++i) {
        // Find the minimum distance vertex not yet processed.
        minDist = INT_MAX;
        for (v = 0; v < MAX_VERTICES; ++v)
            if (!spT.sptSet[v] && spT.dist[v] <= minDist) {
                u = v;
                minDist = spT.dist[v];
            }

        // Mark the picked vertex as processed.
        spT.sptSet[u] = true;

        // Update dist value of the adjacent vertices.
        for (Edge *it = &graph[u][0]; it < &graph[u][MAX_VERTICES]; ++it) {
            v = it->vertex;
            if (!spT.sptSet[v] && it->distance < INT_MAX &&
                spT.dist[u] + it->distance < spT.dist[v]) {
                spT.dist[v] = spT.dist[u] + it->distance;
            }
        }
    }

    printSolution(src, spT);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, m, src;

    scanf("%d %d %d", &n, &m, &src);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }

    dijkstra(graph, src);

    return 0;
}