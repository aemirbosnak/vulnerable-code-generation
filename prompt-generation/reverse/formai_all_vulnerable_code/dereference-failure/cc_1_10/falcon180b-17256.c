//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 7

typedef struct {
    int id;
    int color;
} Node;

void init_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        graph[i].id = i;
        graph[i].color = -1;
    }
}

void print_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", graph[i].color);
    }
    printf("\n");
}

int is_valid_color(Node *graph, int n, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[i].color == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(Node *graph, int n, int node_id) {
    int color = rand() % MAX_COLORS;
    while (!is_valid_color(graph, n, color)) {
        color = rand() % MAX_COLORS;
    }
    graph[node_id].color = color;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node *graph = (Node *) malloc(n * sizeof(Node));
    init_graph(graph, n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        color_node(graph, n, i);
    }

    print_graph(graph, n);

    free(graph);
    return 0;
}