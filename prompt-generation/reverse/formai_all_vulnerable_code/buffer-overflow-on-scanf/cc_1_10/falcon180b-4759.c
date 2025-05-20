//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int color[MAX_VERTICES] = {0};
int nvertices;

void init_graph() {
    int i, j;
    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void read_graph() {
    int i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &nvertices);
    printf("Enter the graph:\n");
    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph() {
    int i, j, k, c = 0;
    for (i = 0; i < nvertices; i++) {
        color[i] = ++c % MAX_COLORS;
    }
    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            if (graph[i][j] == 1) {
                for (k = 0; k < nvertices; k++) {
                    if (graph[i][k] == 1 && color[k]!= color[j]) {
                        color[j] = color[k];
                        break;
                    }
                }
            }
        }
    }
}

void print_colors() {
    int i;
    for (i = 0; i < nvertices; i++) {
        printf("%d ", color[i]);
    }
}

int main() {
    srand(time(NULL));
    read_graph();
    init_graph();
    color_graph();
    print_graph();
    printf("\nColors:\n");
    print_colors();
    return 0;
}