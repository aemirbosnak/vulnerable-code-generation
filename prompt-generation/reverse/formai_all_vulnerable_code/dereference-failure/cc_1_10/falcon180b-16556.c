//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surrealist constants
#define PI 3.14159265358979323846
#define EULER 2.71828182845904523536
#define GOLDEN_RATIO 1.618033988749895
#define SQRT_2 1.41421356237309504880

// Surrealist data structures
typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

// Surrealist functions
void generate_random_points(Point *points, int num_points) {
    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
    }
}

int is_convex(Polygon *polygon) {
    int num_points = polygon->num_points;
    Point *points = polygon->points;
    int count = 0;
    for (int i = 0; i < num_points; i++) {
        Point p1 = points[i];
        Point p2 = points[(i + 1) % num_points];
        Point p3 = points[(i + 2) % num_points];
        if ((p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y) > 0) {
            count++;
        }
    }
    return count == num_points;
}

void print_polygon(Polygon *polygon) {
    int num_points = polygon->num_points;
    Point *points = polygon->points;
    printf("Polygon with %d points:\n", num_points);
    for (int i = 0; i < num_points; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

// Surrealist main function
int main() {
    int num_points = 5;
    Point *points = malloc(sizeof(Point) * num_points);
    generate_random_points(points, num_points);
    Polygon polygon = {points, num_points};
    if (is_convex(&polygon)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is not convex.\n");
    }
    print_polygon(&polygon);
    free(points);
    return 0;
}