//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 50
#define MAX_E 100
#define MAX_C 6

int V;
int E;
int graph[MAX_V][MAX_V];
int color[MAX_V];
int ncolors;

void init_graph() {
    int i, j, k;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    for (i = 0; i < E; i++) {
        printf("Enter the edge %d (u, v, w): ", i + 1);
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
}

void init_colors() {
    int i;

    for (i = 0; i < V; i++) {
        color[i] = -1;
    }
}

void print_solution(int solution[MAX_V]) {
    int i;

    printf("The chromatic number is %d.\n", ncolors);
    printf("The coloring is:\n");

    for (i = 0; i < V; i++) {
        printf("%d: %d\n", i, solution[i]);
    }
}

void backtrack(int v, int c, int solution[MAX_V]) {
    int i, j, k;

    if (v == V) {
        ncolors = c;
        print_solution(solution);
        return;
    }

    for (i = 0; i < MAX_C; i++) {
        if (color[v]!= i) {
            color[v] = i;
            backtrack(v + 1, c, solution);
        }
    }
}

int main() {
    int i, j, k;

    init_graph();
    init_colors();

    backtrack(0, 0, color);

    return 0;
}