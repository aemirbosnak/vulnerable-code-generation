//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

struct Point {
    double x;
    double y;
};

struct Graph {
    int num_points;
    struct Point *points;
};

void create_graph(struct Graph *graph) {
    graph->num_points = 0;
    graph->points = (struct Point *) malloc(MAX_POINTS * sizeof(struct Point));
}

void destroy_graph(struct Graph *graph) {
    free(graph->points);
}

void add_point(struct Graph *graph, double x, double y) {
    if (graph->num_points == MAX_POINTS) {
        printf("Error: Maximum number of points reached.\n");
        return;
    }
    graph->points[graph->num_points].x = x;
    graph->points[graph->num_points].y = y;
    graph->num_points++;
}

void plot_graph(struct Graph *graph) {
    int i;
    printf("Plotting graph...\n");
    for (i = 0; i < graph->num_points; i++) {
        printf("(%f, %f)\n", graph->points[i].x, graph->points[i].y);
    }
}

int main() {
    struct Graph graph;
    create_graph(&graph);

    add_point(&graph, 0.0, 0.0);
    add_point(&graph, 1.0, 1.0);
    add_point(&graph, 2.0, 4.0);
    add_point(&graph, 3.0, 9.0);
    add_point(&graph, 4.0, 16.0);

    plot_graph(&graph);

    destroy_graph(&graph);

    return 0;
}