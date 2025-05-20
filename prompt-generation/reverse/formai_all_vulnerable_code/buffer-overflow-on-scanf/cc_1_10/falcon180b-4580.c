//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100
#define MAX_E 1000
#define MAX_COLOR 6

int V, E;
int adj[MAX_V][MAX_V];
int color[MAX_V];
int final_color[MAX_V];

void init_graph() {
    srand(time(NULL));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                printf("%d ", i);
            }
        }
    }
}

void init_color() {
    for (int i = 0; i < V; i++) {
        color[i] = rand() % MAX_COLOR;
    }
}

void print_color() {
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
}

int is_valid_color(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v) {
    if (v == V) {
        printf("\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", final_color[i]);
        }
        printf("\n");
        return;
    }
    for (int c = 1; c <= MAX_COLOR; c++) {
        if (is_valid_color(v, c)) {
            color[v] = c;
            final_color[v] = c;
            backtrack(v + 1);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    init_graph();
    init_color();
    backtrack(0);
    return 0;
}