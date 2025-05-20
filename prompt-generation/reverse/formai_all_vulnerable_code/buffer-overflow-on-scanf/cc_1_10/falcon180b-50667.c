//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int nvertices;
int ncolors;
int colors[MAX_VERTICES];

void init_graph() {
    int i, j;
    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int is_valid_color(int v, int c) {
    int i;
    for (i = 0; i < nvertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_vertex(int v, int c) {
    colors[v] = c;
}

int main() {
    int i, j, k, l;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &nvertices);
    printf("Enter the number of colors: ");
    scanf("%d", &ncolors);
    init_graph();
    int max_conflicts = 0;
    for (k = 0; k < ncolors; k++) {
        int conflicts = 0;
        for (i = 0; i < nvertices; i++) {
            colors[i] = -1;
        }
        for (i = 0; i < nvertices; i++) {
            if (colors[i] == -1 && is_valid_color(i, k)) {
                color_vertex(i, k);
                for (j = 0; j < nvertices; j++) {
                    if (graph[i][j] && colors[j] == k) {
                        conflicts++;
                    }
                }
            }
        }
        if (conflicts > max_conflicts) {
            max_conflicts = conflicts;
        }
    }
    printf("Maximum number of conflicts: %d\n", max_conflicts);
    return 0;
}