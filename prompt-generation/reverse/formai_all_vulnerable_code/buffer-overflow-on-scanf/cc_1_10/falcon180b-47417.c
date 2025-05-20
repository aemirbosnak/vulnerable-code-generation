//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_V 100
#define MAX_E 10000
#define MAX_COLOR 6

int V, E;
int graph[MAX_V][MAX_V];
int color[MAX_V];

void initGraph(int v, int e) {
    V = v;
    E = e;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

bool checkColor(int u, int c) {
    for (int v = 0; v < V; v++) {
        if (graph[u][v] == 1 && color[v] == c) {
            return false;
        }
    }
    return true;
}

void colorGraph(int start) {
    int i = start;
    while (i < V) {
        int c = 1;
        while (!checkColor(i, c)) {
            c++;
        }
        color[i] = c;
        i++;
    }
}

int main() {
    srand(time(NULL));

    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    initGraph(v, e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    colorGraph(0);

    printf("Color:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }

    return 0;
}