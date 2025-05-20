//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_VERTEX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 999999

struct vertex {
    int id;
    int color;
    struct vertex *next;
};

struct vertex *graph[MAX_VERTEX];
int vertex_count = 0;

void add_vertex(int id) {
    struct vertex *new_vertex = (struct vertex *)malloc(sizeof(struct vertex));
    new_vertex->id = id;
    new_vertex->color = WHITE;
    new_vertex->next = NULL;
    graph[vertex_count] = new_vertex;
    vertex_count++;
}

void add_edge(int from_id, int to_id) {
    struct vertex *from = graph[from_id];
    struct vertex *to = graph[to_id];
    struct vertex *new_vertex = (struct vertex *)malloc(sizeof(struct vertex));
    new_vertex->id = -1;
    new_vertex->color = BLACK;
    new_vertex->next = NULL;
    from->next = new_vertex;
    to->next = new_vertex;
}

void dfs(int start_vertex, int color) {
    struct vertex *current_vertex = graph[start_vertex];
    while (current_vertex!= NULL) {
        if (current_vertex->color == WHITE) {
            current_vertex->color = color;
            for (struct vertex *neighbor = current_vertex->next; neighbor!= NULL; neighbor = neighbor->next) {
                if (neighbor->color == WHITE) {
                    dfs(neighbor->id, color + 1);
                }
            }
        }
        current_vertex = current_vertex->next;
    }
}

int main() {
    int vertex_count, edge_count;
    scanf("%d %d", &vertex_count, &edge_count);

    for (int i = 0; i < vertex_count; i++) {
        add_vertex(i);
    }

    for (int i = 0; i < edge_count; i++) {
        int from_id, to_id;
        scanf("%d %d", &from_id, &to_id);
        add_edge(from_id, to_id);
    }

    int max_color = 0;
    for (int i = 0; i < vertex_count; i++) {
        if (graph[i]->color == WHITE) {
            dfs(i, 0);
            max_color++;
        }
    }

    printf("Maximum number of colors: %d\n", max_color);

    return 0;
}