//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_VERTICES 25
#define MAX_EDGES 50
#define MAX_COLORS 6
#define WIDTH 60
#define HEIGHT 25
typedef struct {
    int vertex;
    int color;
} vertex_t;
int graph[MAX_VERTICES][MAX_VERTICES];
int n_vertices, n_edges;
vertex_t colors[MAX_VERTICES];
void print_graph() {
    int i, j;
    printf("\033[1;1H"); // go to home position
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i * WIDTH + j >= n_vertices) continue;
            printf("%c", i * WIDTH + j + 'A' | 0x20);
            if (colors[i * WIDTH + j].color != -1)
                printf(" %d", colors[i * WIDTH + j].color);
            else
                printf(" X ");
            if ((i * WIDTH + j + 1) < n_vertices) printf("  |");
        }
        printf("\n");
    }
}
void init_graph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}
bool valid_color(int vertex, int color) {
    int i;
    for (i = 0; i < n_vertices; i++) {
        if (i != vertex && graph[i][vertex] && colors[i].color == color)
            return false;
    }
    return true;
}
void graph_coloring(int vertex, int color) {
    int i;
    colors[vertex].color = color;
    for (i = 0; i < n_vertices; i++) {
        if (graph[vertex][i] && !valid_color(i, color)) {
            colors[vertex].color = -1;
            return;
        }
    }
    for (i = 0; i < n_vertices; i++) {
        if (colors[i].color == -1 && graph[vertex][i]) {
            graph_coloring(i, (color + 1) % MAX_COLORS);
            if (colors[i].color == -1) break;
        }
    }
}
void create_graph() {
    int i, j, k;
    printf("Enter number of vertices: ");
    scanf("%d", &n_vertices);
    printf("Enter number of edges:\n");
    scanf("%d", &n_edges);
    init_graph();
    srand(time(NULL));
    for (i = 0; i < n_edges; i++) {
        scanf("%d %d", &j, &k);
        graph[j][k] = 1;
        graph[k][j] = 1;
    }
    for (i = 0; i < n_vertices; i++) {
        colors[i].vertex = i;
        colors[i].color = -1;
    }
    int start_vertex = rand() % n_vertices;
    printf("Starting vertex: %d\n", start_vertex);
    graph_coloring(start_vertex, 0);
    print_graph();
}
int main() {
    create_graph();
    return 0;
}