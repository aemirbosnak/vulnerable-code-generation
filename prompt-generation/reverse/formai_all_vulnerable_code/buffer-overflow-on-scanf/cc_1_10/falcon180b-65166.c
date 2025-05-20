//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1000

typedef struct {
    int x;
    int y;
    int z;
} Point;

typedef struct {
    Point *vertices;
    int num_vertices;
} Polygon;

typedef struct {
    Polygon *polygons;
    int num_polygons;
} Graph;

void read_vertices(Polygon *polygon) {
    int i;
    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &polygon->num_vertices);
    polygon->vertices = (Point *)malloc(polygon->num_vertices * sizeof(Point));
    for (i = 0; i < polygon->num_vertices; i++) {
        printf("Enter vertex %d (x y z): ", i + 1);
        scanf("%d %d %d", &polygon->vertices[i].x, &polygon->vertices[i].y, &polygon->vertices[i].z);
    }
}

void read_polygons(Graph *graph) {
    int i;
    printf("Enter the number of polygons in the graph: ");
    scanf("%d", &graph->num_polygons);
    graph->polygons = (Polygon *)malloc(graph->num_polygons * sizeof(Polygon));
    for (i = 0; i < graph->num_polygons; i++) {
        read_vertices(&graph->polygons[i]);
    }
}

void draw_polygon(Polygon *polygon) {
    int i;
    printf("Polygon %d:\n", polygon->num_vertices);
    for (i = 0; i < polygon->num_vertices; i++) {
        printf("(%d %d %d) ", polygon->vertices[i].x, polygon->vertices[i].y, polygon->vertices[i].z);
    }
}

void draw_graph(Graph *graph) {
    int i;
    for (i = 0; i < graph->num_polygons; i++) {
        draw_polygon(&graph->polygons[i]);
    }
}

int main() {
    Graph graph;
    read_polygons(&graph);
    draw_graph(&graph);
    return 0;
}