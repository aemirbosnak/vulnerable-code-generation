//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 5
#define COLORS 3

int graph[SIZE][SIZE];
int visited[SIZE];
int colors_assigned[SIZE];

void print_graph() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_color(int node, int color) {
    for (int i = 0; i < SIZE; i++) {
        if (graph[node][i] == 1 && colors_assigned[i] == color) {
            return false;
        }
    }
    return true;
}

void graph_coloring() {
    int current_color = 0;
    for (int i = 0; i < SIZE; i++) {
        visited[i] = 0;
        colors_assigned[i] = -1;
    }

    for (int i = 0; i < SIZE; i++) {
        if (visited[i] == 0) {
            int node = i;
            bool assigned_color = false;
            for (int color = 0; color < COLORS && !assigned_color; color++) {
                if (is_valid_color(node, color)) {
                    colors_assigned[node] = color;
                    assigned_color = true;
                }
            }
        }
    }
}

void print_colors() {
    printf("Colors assigned:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Node %d: Color %d\n", i, colors_assigned[i]);
    }
}

void read_graph_data() {
    printf("Enter graph data (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int main() {
    read_graph_data();
    print_graph();
    graph_coloring();
    print_colors();
    return 0;
}