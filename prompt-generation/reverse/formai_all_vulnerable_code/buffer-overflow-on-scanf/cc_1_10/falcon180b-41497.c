//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 6

struct node {
    int id;
    int color;
};

int is_valid(struct node *nodes, int n, int color) {
    for (int i = 0; i < n; i++) {
        if (nodes[i].color == color || nodes[i].id == color) {
            return 0;
        }
    }
    return 1;
}

void init_graph(struct node *nodes, int n) {
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].color = -1;
    }
}

void print_graph(struct node *nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nodes[i].id);
    }
    printf("\n");
}

void apply_color(struct node *nodes, int n, int color) {
    for (int i = 0; i < n; i++) {
        if (nodes[i].color == -1) {
            nodes[i].color = color;
            return;
        }
    }
}

int color_graph(struct node *nodes, int n) {
    int colors[MAX_COLORS] = {1, 2, 3, 4, 5, 6};
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int color = rand() % MAX_COLORS;
        while (!is_valid(nodes, n, color)) {
            color = (color + 1) % MAX_COLORS;
        }
        apply_color(nodes, n, color);
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct node *nodes = (struct node*) malloc(n * sizeof(struct node));

    init_graph(nodes, n);

    if (color_graph(nodes, n)) {
        printf("Colored graph:\n");
        print_graph(nodes, n);
    } else {
        printf("Failed to color graph.\n");
    }

    free(nodes);
    return 0;
}