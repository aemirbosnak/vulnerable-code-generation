//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_COLORS 3

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int color[MAX_VERTICES];

int is_safe(int v, int c, int color[], int i) {
    int j = 0;
    while (j < i) {
        if (color[j] == c || graph[j][v] == 1) {
            return 0;
        }
        j++;
    }
    return 1;
}

void backtrack(int v, int i, int color[]) {
    if (v == i) {
        return;
    }
    color[v] = color[i];
    v++;
    backtrack(v, i, color);
}

void color_graph(int v, int i, int color[]) {
    if (v == i) {
        return;
    }
    for (int j = 0; j < MAX_COLORS; j++) {
        if (is_safe(v, j, color, i)) {
            color[v] = j;
            color_graph(v + 1, i, color);
        }
    }
}

int main() {
    int i, j, k;
    printf("Enter number of vertices: ");
    scanf("%d", &i);
    if (i > MAX_VERTICES || i < 2) {
        printf("Invalid number of vertices.\n");
        exit(0);
    }
    for (j = 0; j < i; j++) {
        for (k = 0; k < i; k++) {
            scanf("%d", &graph[j][k]);
        }
    }
    printf("Enter number of colors: ");
    scanf("%d", &i);
    if (i > MAX_COLORS || i < 2) {
        printf("Invalid number of colors.\n");
        exit(0);
    }
    color_graph(0, 0, color);
    printf("Vertex\tColor\n");
    for (j = 0; j < i; j++) {
        printf("%d\t%d\n", j, color[j]);
    }
    return 0;
}