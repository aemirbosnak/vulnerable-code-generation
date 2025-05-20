//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_VERTEX 100
#define MAX_COLOR 100

int V, E, i, j, k, u, v, w, count[MAX_COLOR], color[MAX_VERTEX];
int graph[MAX_VERTEX][MAX_VERTEX];

void initialize() {
    srand(time(NULL));
    for (i = 0; i < MAX_VERTEX; i++) {
        color[i] = -1;
        count[i] = 0;
    }
}

void generateGraph() {
    int seed;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v w):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
}

void backtrack(int x, int c) {
    int i, j;
    if (x == V) {
        if (c <= MAX_COLOR) {
            count[c]++;
        }
        return;
    }

    for (i = 1; i <= MAX_COLOR; i++) {
        if (color[x]!= i && color[graph[x][0]]!= i) {
            color[x] = i;
            backtrack(x + 1, c);
        }
    }
}

void colorGraph() {
    int i, c;
    for (i = 0; i <= MAX_COLOR; i++) {
        count[i] = 0;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &c);

    if (c > MAX_COLOR) {
        printf("Invalid number of colors\n");
        exit(0);
    }

    backtrack(0, 0);

    for (i = 1; i <= MAX_COLOR; i++) {
        if (count[i] > 0) {
            printf("Color %d is used %d times\n", i, count[i]);
        }
    }
}

int main() {
    initialize();
    generateGraph();
    colorGraph();

    return 0;
}