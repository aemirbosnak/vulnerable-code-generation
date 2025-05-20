//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[MAX_POINTS];
    int num_vertices;
} Polygon;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void add_point(Polygon* poly, double x, double y) {
    if (poly->num_vertices < MAX_POINTS) {
        poly->vertices[poly->num_vertices].x = x;
        poly->vertices[poly->num_vertices].y = y;
        poly->num_vertices++;
    } else {
        printf("Polygon cannot have more than %d vertices.\n", MAX_POINTS);
    }
}

double polygon_perimeter(Polygon* poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly->num_vertices; i++) {
        perimeter += distance(poly->vertices[i], poly->vertices[(i + 1) % poly->num_vertices]);
    }
    return perimeter;
}

double polygon_area(Polygon* poly) {
    double area = 0.0;
    for (int i = 0; i < poly->num_vertices; i++) {
        area += (poly->vertices[i].x * poly->vertices[(i + 1) % poly->num_vertices].y) -
                (poly->vertices[(i + 1) % poly->num_vertices].x * poly->vertices[i].y);
    }
    return fabs(area) / 2.0;
}

void print_polygon(Polygon* poly) {
    printf("Polygon with %d vertices:\n", poly->num_vertices);
    for (int i = 0; i < poly->num_vertices; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

int main() {
    Polygon polygon;
    polygon.num_vertices = 0;

    printf("Enter the number of vertices for the polygon (max %d): ", MAX_POINTS);
    int num_vertices;
    scanf("%d", &num_vertices);

    if (num_vertices > MAX_POINTS) {
        printf("Exceeding maximum number of vertices.\n");
        return 1;
    }

    for (int i = 0; i < num_vertices; i++) {
        double x, y;
        printf("Enter coordinates for vertex %d (format: x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        add_point(&polygon, x, y);
    }

    print_polygon(&polygon);
    
    double perimeter = polygon_perimeter(&polygon);
    double area = polygon_area(&polygon);
    
    printf("Perimeter of the polygon: %.2f\n", perimeter);
    printf("Area of the polygon: %.2f\n", area);

    return 0;
}