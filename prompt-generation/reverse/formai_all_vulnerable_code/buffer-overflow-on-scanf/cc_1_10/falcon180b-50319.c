//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 100

int graph[MAX_NODES][MAX_NODES];
int color_map[MAX_NODES];
int num_colors;

void initialize_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void initialize_color_map(int n) {
    for (int i = 0; i < n; i++) {
        color_map[i] = -1;
    }
}

int is_valid_color(int node, int color) {
    for (int i = 0; i < node; i++) {
        if (color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int n) {
    int start_node = 0;
    color_map[start_node] = 0;
    num_colors = 1;

    for (int i = 1; i < n; i++) {
        int current_node = start_node;
        int color_index = 0;

        while (color_index < num_colors) {
            if (is_valid_color(current_node, color_index)) {
                color_map[current_node] = color_index;
                break;
            }
            color_index++;
        }

        if (color_index == num_colors) {
            num_colors++;
            color_map[current_node] = num_colors - 1;
        }

        start_node = current_node + 1;
    }

    return num_colors;
}

void print_color_map(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", color_map[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    initialize_graph(n);
    initialize_color_map(n);

    int num_colors = color_graph(n);

    printf("Number of colors used: %d\n", num_colors);
    print_color_map(n);

    return 0;
}