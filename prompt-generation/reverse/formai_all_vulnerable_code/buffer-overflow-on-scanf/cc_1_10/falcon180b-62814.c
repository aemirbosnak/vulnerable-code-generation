//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define V 9

int graph[V][V] = { { 0, 3, 0, 0, 0, 0, 0, 0, 0 },
                    { 3, 0, 4, 0, 0, 0, 0, 0, 0 },
                    { 0, 4, 0, 1, 0, 0, 0, 0, 0 },
                    { 0, 0, 1, 0, 3, 0, 0, 0, 0 },
                    { 0, 0, 0, 3, 0, 2, 0, 0, 0 },
                    { 0, 0, 0, 0, 2, 0, 1, 0, 0 },
                    { 0, 0, 0, 0, 0, 1, 0, 3, 0 },
                    { 0, 0, 0, 0, 0, 0, 3, 0, 4 },
                    { 0, 0, 0, 0, 0, 0, 0, 4, 0 } };

int n, m, i, j, k, u, v, w, s;

int color[V];

void init_color(int start) {
    for (i = 0; i < V; i++)
        color[i] = start;
}

int is_valid(int c) {
    for (i = 0; i < V; i++)
        if (graph[i][j] == 1 && color[i] == c)
            return 0;
    return 1;
}

void color_graph(int start) {
    int c = start;
    for (i = 0; i < V; i++) {
        if (color[i] == -1 && is_valid(c)) {
            color[i] = c;
            for (j = 0; j < V; j++)
                if (graph[i][j] == 1)
                    color[j] = -1;
        }
        c++;
    }
}

int main() {
    int c;
    printf("Enter the number of colors: ");
    scanf("%d", &c);
    init_color(1);
    color_graph(1);
    printf("\nColoring:\n");
    for (i = 0; i < V; i++)
        printf("%d ", color[i]);
    return 0;
}