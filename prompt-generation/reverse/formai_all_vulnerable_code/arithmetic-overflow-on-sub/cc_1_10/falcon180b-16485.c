//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_COLOR 7

int V;
int E;
int graph[MAX_VERTEX][MAX_VERTEX] = {0};
int color[MAX_VERTEX] = {0};

void initGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges: ");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void printColor() {
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

void colorGraph() {
    int startTime = clock();
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    while (count < V) {
        for (int l = 0; l < MAX_COLOR; l++) {
            if (color[j] == l) {
                k = (k + 1) % MAX_COLOR;
            }
        }
        color[i] = k;
        i++;
        j = (j + 1) % V;
        count++;
    }
    int endTime = clock();
    printf("Time taken: %d ms\n", endTime - startTime);
}

int main() {
    initGraph();
    printGraph();
    colorGraph();
    printColor();
    return 0;
}