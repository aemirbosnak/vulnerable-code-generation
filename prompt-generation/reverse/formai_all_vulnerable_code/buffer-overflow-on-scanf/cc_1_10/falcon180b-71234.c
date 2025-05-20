//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int colors[MAX_VERTICES];

void initialize_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int is_valid_color(int vertex, int color) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int vertex = 0;
    int color = 0;
    while (vertex < n) {
        if (colors[vertex] == -1) {
            int found = 0;
            while (!found) {
                color++;
                if (color == MAX_COLORS) {
                    color = 0;
                }
                found = 1;
                for (int i = 0; i < vertex; i++) {
                    if (!is_valid_color(i, color)) {
                        found = 0;
                        break;
                    }
                }
            }
            colors[vertex] = color;
            vertex++;
        } else {
            vertex++;
        }
    }
}

void print_graph(int n, int colors[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initialize_graph(n);
    color_graph();
    printf("Colored graph:\n");
    print_graph(n, colors);
    return 0;
}