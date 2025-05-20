//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 1000
#define MAX_COLORS 7

typedef struct {
    int vertex;
    int color;
} Edge;

int V, E;
Edge edges[MAX_EDGES];
int colors[MAX_VERTICES];

void init(int v) {
    V = v;
    E = 0;
    for (int i = 0; i < V; i++) {
        colors[i] = -1;
    }
}

void addEdge(int v, int w) {
    edges[E].vertex = v;
    edges[E].color = -1;
    E++;
}

int graphColoring(int v, int e) {
    int i, j, w, k;
    int count = 0;
    for (i = 0; i < e; i++) {
        w = edges[i].vertex;
        for (j = 0; j < V; j++) {
            if (colors[j] == -1 && colors[w] == -1) {
                colors[j] = 1;
                colors[w] = 2;
                count++;
                break;
            }
        }
        if (j == V) {
            return 0;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);
    init(v);
    for (int i = 0; i < e; i++) {
        int a, b;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
    int result = graphColoring(v, e);
    printf("The chromatic number of the graph is %d\n", result);
    return 0;
}