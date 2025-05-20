//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTEX 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void read_polygon(Polygon *polygon) {
    printf("Enter number of vertices: ");
    scanf("%d", &polygon->num_points);
    polygon->points = (Point *)malloc(polygon->num_points * sizeof(Point));
    for (int i = 0; i < polygon->num_points; i++) {
        printf("Enter vertex %d coordinates (x y): ", i + 1);
        scanf("%d %d", &polygon->points[i].x, &polygon->points[i].y);
    }
}

void print_polygon(Polygon *polygon) {
    printf("Polygon with %d vertices:\n", polygon->num_points);
    for (int i = 0; i < polygon->num_points; i++) {
        printf("(%d, %d)\n", polygon->points[i].x, polygon->points[i].y);
    }
}

void rotate_polygon(Polygon *polygon, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    Point center = {0, 0};
    for (int i = 0; i < polygon->num_points; i++) {
        Point vertex = polygon->points[i];
        double x = vertex.x - center.x;
        double y = vertex.y - center.y;
        double new_x = x * cosine - y * sine;
        double new_y = x * sine + y * cosine;
        vertex.x = center.x + new_x;
        vertex.y = center.y + new_y;
        polygon->points[i] = vertex;
    }
}

int main() {
    Polygon polygon;
    read_polygon(&polygon);
    print_polygon(&polygon);
    rotate_polygon(&polygon, M_PI / 4);
    print_polygon(&polygon);
    return 0;
}