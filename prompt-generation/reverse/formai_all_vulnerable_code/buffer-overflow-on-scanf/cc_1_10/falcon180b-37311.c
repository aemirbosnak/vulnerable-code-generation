//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7
#define INF 999999

int graph[MAX_VERTICES][MAX_VERTICES];
int n, m;
int color[MAX_VERTICES];
int k;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph() {
    int i, j, c;
    for (i = 0; i < n; i++) {
        color[i] = rand() % MAX_COLORS;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1 && color[i] == color[j]) {
                c = rand() % MAX_COLORS;
                while (c == color[i] || c == color[j]) {
                    c = rand() % MAX_COLORS;
                }
                color[i] = c;
                color[j] = c;
            }
        }
    }
}

void print_colors() {
    int i;
    printf("Colors:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main() {
    int i, j;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    color_graph();
    print_graph();
    print_colors();
    return 0;
}