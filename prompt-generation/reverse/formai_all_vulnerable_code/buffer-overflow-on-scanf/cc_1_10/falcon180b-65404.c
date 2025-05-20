//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100

typedef struct {
    int id;
    double x, y;
} vertex_t;

typedef struct {
    int start, end;
} edge_t;

vertex_t vertices[MAX_VERTICES];
edge_t edges[MAX_VERTICES];
int num_vertices, num_edges;

void read_vertices() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        printf("Enter vertex %d coordinates (x y): ", i + 1);
        scanf("%lf %lf", &vertices[i].x, &vertices[i].y);
        vertices[i].id = i + 1;
    }
}

void read_edges() {
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter edge %d start and end vertices (start end): ", i + 1);
        scanf("%d %d", &edges[i].start, &edges[i].end);
    }
}

void print_graph() {
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: (%lf, %lf)\n", vertices[i].id, vertices[i].x, vertices[i].y);
    }

    for (int i = 0; i < num_edges; i++) {
        printf("Edge %d: (%d, %d)\n", i + 1, edges[i].start, edges[i].end);
    }
}

void calculate_distances() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            double dx = vertices[j].x - vertices[i].x;
            double dy = vertices[j].y - vertices[i].y;
            double distance = sqrt(dx * dx + dy * dy);

            printf("Distance between vertex %d and vertex %d: %lf\n", i + 1, j + 1, distance);
        }
    }
}

int main() {
    read_vertices();
    read_edges();

    print_graph();

    calculate_distances();

    return 0;
}