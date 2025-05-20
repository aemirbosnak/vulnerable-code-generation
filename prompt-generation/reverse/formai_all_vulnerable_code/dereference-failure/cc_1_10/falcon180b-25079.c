//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 7

typedef struct {
    int num;
    int color;
} Node;

void init_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        graph[i].num = i;
        graph[i].color = -1;
    }
}

bool is_valid_color(Node *graph, int n, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[i].color == color) {
            return false;
        }
    }
    return true;
}

void color_node(Node *graph, int n, int node_index, int color) {
    graph[node_index].color = color;
}

int search_color(Node *graph, int n, int node_index) {
    for (int i = 0; i < MAX_COLORS; i++) {
        if (is_valid_color(graph, n, i)) {
            color_node(graph, n, node_index, i);
            return i;
        }
    }
    return -1;
}

void print_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", graph[i].num, graph[i].color);
    }
}

int main() {
    srand(time(NULL));

    int n = rand() % MAX_NODES + 1;
    Node *graph = (Node *) malloc(n * sizeof(Node));
    init_graph(graph, n);

    int *color_counts = (int *) malloc(MAX_COLORS * sizeof(int));
    for (int i = 0; i < MAX_COLORS; i++) {
        color_counts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int color = search_color(graph, n, i);
        color_counts[color]++;
    }

    printf("Number of colors used: %d\n", MAX_COLORS - 1);

    for (int i = 0; i < MAX_COLORS; i++) {
        if (color_counts[i] > 0) {
            printf("%d: %d\n", i, color_counts[i]);
        }
    }

    print_graph(graph, n);

    free(graph);
    free(color_counts);

    return 0;
}