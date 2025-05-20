//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int vertex;
    int color;
} vertex_t;

void print_graph(vertex_t graph[MAX_VERTICES], int num_vertices) {
    int i, j;

    printf("Adjacency Matrix Representation of the Graph:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("\nVertex %d: Color = %d", i, graph[i].color);
        for (j = 0; j < num_vertices; j++) {
            if (i == j) continue;
            printf("\t%d: %s", j, graph[j].color == graph[i].color ? "Same" : "Different");
        }
    }
}

int greedy_graph_coloring(vertex_t graph[MAX_VERTICES], int num_vertices) {
    int i, next_color, conflict;

    for (i = 0; i < num_vertices; i++) {
        next_color = MIN_COLOR;
        conflict = 1;

        do {
            if (next_color == graph[i].color) {
                conflict = 1;
                break;
            }

            conflict = 0;
            for (int j = 0; j < i; j++) {
                if (graph[i].color == graph[j].color ||
                    graph[i].vertex == graph[j].vertex ||
                    conflict_edge(graph, i, j, num_vertices)) {
                    conflict = 1;
                    break;
                }
            }

            if (!conflict) {
                graph[i].color = next_color;
                break;
            }

            next_color++;
        } while (next_color <= MAX_COLOR);

        if (next_color > MAX_COLOR) {
            printf("\nGraph with %d vertices cannot be colored with %d colors.\n", num_vertices, MAX_COLOR + 1);
            return -1;
        }
    }

    print_graph(graph, num_vertices);
    return 0;
}

int conflict_edge(vertex_t graph[], int i, int j, int num_vertices) {
    return (graph[i].vertex == graph[j].vertex ||
            abs(graph[i].vertex - graph[j].vertex) == 1);
}

int main() {
    int num_vertices;
    vertex_t graph[MAX_VERTICES];

    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        scanf("%d", &graph[i].vertex);
        graph[i].color = MIN_COLOR;
    }

    greedy_graph_coloring(graph, num_vertices);

    return 0;
}