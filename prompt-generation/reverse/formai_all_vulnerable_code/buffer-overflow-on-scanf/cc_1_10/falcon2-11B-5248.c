//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vertex;
    int color;
} Vertex;

int minColor(Vertex *vertex, int n) {
    int min = 1;
    for (int i = 0; i < n; i++) {
        if (vertex[i].color == 0) {
            min = 1;
            break;
        } else {
            min++;
        }
    }
    return min;
}

void printVertex(Vertex *vertex, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, vertex[i].color);
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    Vertex *vertex = (Vertex*) malloc(n * sizeof(Vertex));

    printf("Enter the edges in the form of <source, destination>: ");
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        vertex[v1].color = 0;
        vertex[v2].color = 0;
    }

    int color = 1;
    while (color <= n) {
        if (color == minColor(vertex, n)) {
            printf("No solution.\n");
            break;
        }
        for (int i = 0; i < n; i++) {
            if (vertex[i].color == 0) {
                vertex[i].color = color;
                color++;
                break;
            }
        }
    }

    if (color <= n) {
        printf("Solution found with %d colors.\n", color);
    }

    printVertex(vertex, n);

    free(vertex);
    return 0;
}