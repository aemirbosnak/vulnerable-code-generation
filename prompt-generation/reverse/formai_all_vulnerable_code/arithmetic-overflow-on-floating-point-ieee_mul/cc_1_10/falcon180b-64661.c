//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Point center;
    double radius;
} Circle;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double line_length(Line l) {
    return distance(l.p1, l.p2);
}

double circle_area(Circle c) {
    return PI * pow(c.radius, 2);
}

double circle_circumference(Circle c) {
    return 2 * PI * c.radius;
}

void print_point(Point p) {
    printf("(%lf, %lf)\n", p.x, p.y);
}

void print_line(Line l) {
    printf("Line: ");
    print_point(l.p1);
    printf(" -> ");
    print_point(l.p2);
    printf("\n");
}

void print_circle(Circle c) {
    printf("Circle: ");
    print_point(c.center);
    printf(" (radius = %lf)\n", c.radius);
}

int main() {
    // Example usage
    Point p1 = {0, 0};
    Point p2 = {3, 4};
    Line l = {p1, p2};

    Circle c = {{0, 0}, 5};

    printf("Line length: %lf\n", line_length(l));
    print_line(l);

    printf("Circle area: %lf\n", circle_area(c));
    printf("Circle circumference: %lf\n", circle_circumference(c));
    print_circle(c);

    return 0;
}