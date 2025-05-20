//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int count;
} Polygon;

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double polygon_area(Polygon *poly) {
    double area = 0.0;
    for (int i = 0; i < poly->count; i++) {
        int j = (i + 1) % poly->count;
        area += poly->points[i].x * poly->points[j].y;
        area -= poly->points[j].x * poly->points[i].y;
    }
    return fabs(area) / 2.0;
}

void print_polygon(Polygon *poly) {
    printf("Polygon Points:\n");
    for (int i = 0; i < poly->count; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i, poly->points[i].x, poly->points[i].y);
    }
}

void add_point_to_polygon(Polygon *poly, double x, double y) {
    if (poly->count < MAX_POINTS) {
        poly->points[poly->count].x = x;
        poly->points[poly->count].y = y;
        poly->count++;
    } else {
        printf("Polygon can only have %d points.\n", MAX_POINTS);
    }
}

void generate_regular_polygon(Polygon *poly, int num_sides, double radius) {
    for (int i = 0; i < num_sides; i++) {
        double angle = 2 * PI * i / num_sides;
        add_point_to_polygon(poly, radius * cos(angle), radius * sin(angle));
    }
}

void display_area(Polygon *poly) {
    double area = polygon_area(poly);
    printf("The area of the polygon is: %.2f\n", area);
}

int main() {
    Polygon poly;
    poly.count = 0;

    int num_sides;
    double radius;

    printf("Enter the number of sides for the regular polygon (3 or more): ");
    scanf("%d", &num_sides);
    if (num_sides < 3) {
        printf("A polygon must have at least 3 sides.\n");
        return 1;
    }

    printf("Enter the radius of the polygon: ");
    scanf("%lf", &radius);

    generate_regular_polygon(&poly, num_sides, radius);
    print_polygon(&poly);
    display_area(&poly);

    Point p1 = {2, 3}, p2 = {5, 7};
    printf("Distance between Point A (%.2f, %.2f) and Point B (%.2f, %.2f): %.2f\n",
           p1.x, p1.y, p2.x, p2.y, distance(p1, p2));

    return 0;
}