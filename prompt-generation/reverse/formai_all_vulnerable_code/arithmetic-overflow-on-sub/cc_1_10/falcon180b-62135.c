//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 0x3f3f3f3f

typedef struct {
    int num;
    int *adj;
    int *weight;
} Graph;

Graph create_graph(int num) {
    Graph g;
    g.num = num;
    g.adj = (int *) malloc(num * sizeof(int));
    g.weight = (int *) malloc(num * sizeof(int));
    memset(g.adj, -1, num * sizeof(int));
    memset(g.weight, INF, num * sizeof(int));
    return g;
}

void add_edge(Graph *g, int u, int v, int w) {
    g->adj[u] = v;
    g->weight[u] = w;
}

void dijkstra(Graph *g, int start) {
    int i, u, v, w;
    int dist[MAX_VERTEX];
    int visited[MAX_VERTEX];

    memset(dist, INF, sizeof(dist));
    memset(visited, 0, sizeof(visited));

    dist[start] = 0;

    for (i = 0; i < g->num - 1; i++) {
        for (u = 0; u < g->num; u++) {
            if (dist[u]!= INF && g->adj[u]!= -1) {
                v = g->adj[u];
                w = g->weight[u];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < g->num; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, u, v, w;
    Graph g;
    char ch;

    printf("Enter the number of vertices: ");
    scanf("%d", &g.num);

    printf("Enter the edges with their weights (u v w):\n");
    for (i = 0; i < g.num; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&g, u, v, w);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &u);

    dijkstra(&g, u);

    return 0;
}