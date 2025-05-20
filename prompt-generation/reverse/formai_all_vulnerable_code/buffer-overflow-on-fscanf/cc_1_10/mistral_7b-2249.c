//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define INF 999999
typedef struct {
    int src;
    int dest;
    int weight;
} Edge;
typedef struct {
    int vertex;
    int color;
} Node;
int graph[MAX_VERTICES][MAX_VERTICES];
int nVertices, nEdges;
Edge edges[MAX_EDGES];
Node nodes[MAX_VERTICES];
bool isGraphBicolorable(int source, int currentColor) {
    for (int i = 0; i < nVertices; i++) {
        if (graph[source][i] != -1 && nodes[i].color == currentColor) {
            return false;
        }
    }
    return true;
}
int bicolorGraph(int source) {
    nodes[source].color = 0;
    for (int i = 0; i < nEdges; i++) {
        if (graph[edges[i].src][edges[i].dest] == edges[i].src) {
            if (!isGraphBicolorable(edges[i].dest, 1 - nodes[source].color)) {
                return -1;
            }
        }
        int neighborColor = nodes[edges[i].dest].color;
        if (graph[edges[i].src][edges[i].dest] == -1 || neighborColor != nodes[source].color) {
            nodes[edges[i].dest].color = 1 - nodes[source].color;
            int result = bicolorGraph(edges[i].dest);
            if (result == -1) {
                return -1;
            }
        }
    }
    return 1;
}
void readGraphFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    fscanf(file, "%d %d", &nVertices, &nEdges);
    for (int i = 0; i < nEdges; i++) {
        fscanf(file, "%d %d", &edges[i].src, &edges[i].dest);
        graph[edges[i].src][edges[i].dest] = edges[i].src;
        graph[edges[i].dest][edges[i].src] = edges[i].dest;
    }
    fclose(file);
}
int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    readGraphFromFile(filename);
    if (bicolorGraph(0) == -1) {
        printf("This graph is not bicolorable.\n");
    } else {
        printf("This graph is bicolorable.\n");
    }
    return 0;
}