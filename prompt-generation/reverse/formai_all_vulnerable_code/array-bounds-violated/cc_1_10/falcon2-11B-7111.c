//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 100

int color[MAX_V];
int graph[MAX_V][MAX_V];
int colorCount[MAX_V];

int minColor(int n, int color[]) {
    int min = color[0];
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (color[i] < min) {
            min = color[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void greedy_coloring(int vertex, int parent) {
    int min = minColor(vertex, color);
    color[min]++;

    for (int i = 0; i < vertex; i++) {
        if (graph[i][min] == 1) {
            if (color[i] == 0) {
                greedy_coloring(i, min);
            } else if (color[i]!= color[min]) {
                color[min]++;
                min = i;
            }
        }
    }

    color[min]++;
}

int main() {
    int vertices = 0;
    int edges = 0;
    int vertex, edge, i, j;

    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &vertices, &edges);

    for (i = 0; i < vertices; i++) {
        colorCount[i] = 0;
        color[i] = 0;
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d%d", &vertex, &edge);

        if (graph[vertex][edge] == 0) {
            graph[vertex][edge] = 1;
            colorCount[vertex]++;
        }
    }

    for (i = 0; i < vertices; i++) {
        if (colorCount[i] == 0) {
            greedy_coloring(i, -1);
            break;
        }
    }

    printf("Graph coloring done.\n");
    for (i = 0; i < vertices; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < vertices; j++) {
            printf("%d ", color[j]);
        }
        printf("\n");
    }

    return 0;
}