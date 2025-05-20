//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n;

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
            if (graph[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void print_color() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int is_valid(int v, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        color[i] = rand() % MAX_COLORS;
    }
}

int main() {
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph();
    print_graph();
    color_graph();
    print_color();
    return 0;
}